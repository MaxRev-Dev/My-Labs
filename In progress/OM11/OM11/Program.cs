using System;
using System.Collections.Generic;
using System.Linq;

namespace OM11
{
    using F = Func<double[], double>;
    using Fr = Func<double[], double, double>;
    class Program
    {
        private interface IPF
        {
            double Fk(double[] x);
            double Fk_P(double[] x, double r);
            IEnumerable<F> GetDerivs();
            IEnumerable<Fr> GetDerivsR();
            double Fi_1(double[] x);
            double Fi_2(double[] x);
            double PenaltyFunction(double[] x, double r);
        }

        class InternalPenaltyFunctionMethod : IPF
        {
            public double Fk(double[] x)
            {
                return Math.Pow(x[0] - 5, 2) + Math.Pow(x[1] - 3, 2) - x[0] * x[1];
            }
            public double Fk_P(double[] x, double r)
            {
                return Fk(x) + PenaltyFunction(x, r);
            }

            public IEnumerable<F> GetDerivs()
            {
                yield return x => 2 * (x[0] - 5) - x[1];
                yield return x => 2 * (x[1] - 3) - x[0];
            }
            public IEnumerable<Fr> GetDerivsR()
            {
                double dx1(double[] x) => x[0] + x[1] - 3;
                double dx2(double[] x) => -x[0] + 2 * x[1] - 4;
                //first derivative
                yield return (x, r) => 2 * (x[0] - 5) - x[1] +
                                       r * (1.0 / Math.Log(Math.Abs(dx1(x))) -
                                            1.0 / Math.Log(Math.Abs(dx2(x))));
                //2nd
                yield return (x, r) => 2 * (x[1] - 3) - x[0] +
                                       r * (1.0 / Math.Log(Math.Abs(dx1(x))) +
                                            2.0 / Math.Log(Math.Abs(dx2(x))));
            }
            public double Fi_1(double[] x)
            {
                return x[0] + x[1] - 3;
            }
            public double Fi_2(double[] x)
            {
                return -x[0] + 2 * x[1] - 4;
            }
            public double PenaltyFunction(double[] x, double r)
            {
                return r * new F[] { Fi_1, Fi_2 }.Sum(i => 1.0 / i.Invoke(x));
            }
        }

        class ExternalPenaltyFunctionMethod : IPF
        {
            public double Fk(double[] x)
            {
                return -4 * x[0] - x[1];
            }

            public double Fk_P(double[] x, double r)
            {
                return Fk(x) + PenaltyFunction(x, r);
            }

            public IEnumerable<F> GetDerivs()
            {
                yield return x => -x[1];
                yield return x => 2 * x[1] - 5 * x[2];
                yield return x => 2 * x[1] - 5 * x[2];
            }
            public IEnumerable<Fr> GetDerivsR()
            {
                yield return (x, r) => -x[1] + PenaltyFunction(x, r);
                yield return (x, r) => 2 * x[1] - 5 * x[2] + PenaltyFunction(x, r);
                yield return (x, r) => 2 * x[1] - 5 * x[2] + PenaltyFunction(x, r);
            }
            public double Fi_1(double[] x)
            {
                return -Math.Pow(x[0], 2) - x[1] + 2;
            }
            public double Fi_2(double[] x)
            {
                return -x[0] - x[1] + 6;
            }
            public double PenaltyFunction(double[] x, double r)
            {
                return r * new F[] { Fi_1, Fi_2 }.Sum(i => Math.Pow(i.Invoke(x), 2));
            }
        }

        private static double[] FindGrad(IEnumerable<F> derivs, double[] x)
        {
            var dfDx = derivs.Select(f => f(x)).ToArray();

            double norm = Math.Sqrt(dfDx.Select(v => Math.Pow(v, 2)).Sum());

            return dfDx.Select(v => v / norm).ToArray();

        }
        private static double[] FindGrad(IEnumerable<Fr> derivs, double[] x, double r)
        {
            var dfDx = derivs.Select(f => f(x, r)).ToArray();

            double norm = Math.Sqrt(dfDx.Select(v => Math.Pow(v, 2)).Sum());

            return dfDx.Select(v => v / norm).ToArray();
        }

        static void Main(string[] args)
        {
            foreach (var m in new[] {
                typeof(InternalPenaltyFunctionMethod),
                typeof(ExternalPenaltyFunctionMethod) })
            {
                var method = (IPF)Activator.CreateInstance(m);

                Console.WriteLine($"{m.Name}");
                double r = 1;
                double c = 10;
                double eps = 0.05;
                int krok = 0;

                double[] X = { 1.5, 1 }; /*m == typeof(ExternalPenaltyFunctionMethod) ? 1 : -1;*/
                double min;

                while (true)
                {
                    min = 0;
                    var a = .5;
                    var b = 0.5;

                    double epsilon = 0.01;
                    double[]
                        x_next = X,
                        grad;
                    while (true)
                    {
                        X = x_next;
                        grad = FindGrad(method.GetDerivsR(), X, r);
                        x_next = X.Select((xv, i) => xv - a * grad[i]).ToArray();

                        var left = method.Fk_P(X.Select((xv, i) => xv - x_next[i]).ToArray(), r);
                        if (grad.All(gr =>
                        left <= -epsilon * a * Math.Pow(Math.Abs(gr), 2)))
                            break;
                        a *= b;
                        Console.WriteLine(string.Join(" ",
                            X.Select((x, i) => $"x{i + 1}={x:f2}")));
                        Console.WriteLine($"y={ method.Fk_P(X, r)}\n");
                    }

                    if (Math.Abs(method.PenaltyFunction(X, r)) <= eps)
                    {
                        break;
                    }
                    r /= c;
                    c += 2;
                    krok++;
                }
                Console.WriteLine($"Minimum = {min}\n at {string.Join(',', X)}\nCount iteration = {krok}\n");
            }
        }
    }
}