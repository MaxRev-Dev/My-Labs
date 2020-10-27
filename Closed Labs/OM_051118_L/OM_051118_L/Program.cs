using System;
using System.Linq;

namespace Grad
{
    internal class Program
    {
        private static double F(double[] x)
        {
            var x1 = x[0];
            var x2 = x[1];
            var x3 = x[2];
            return 4 * Math.Pow(x1, 2)
                + 5 * Math.Pow(x2, 2)
                + 7 * Math.Pow(x3, 2)
                - (2 * x1 * x2)
                + x1 * x3
                + x1 - x2 + x3;
        }

        private static double Dx1(double[] x)
        {
            var x1 = x[0];
            var x2 = x[1];
            var x3 = x[2];
            return 8 * x1 + x3 - 2 * x2 + 1;
        }
        private static double Dx2(double[] x)
        {
            var x1 = x[0];
            var x2 = x[1];
            var x3 = x[2];
            return 10 * x2 - 2 * x1 - 1;
        }
        private static double Dx3(double[] x)
        {
            var x1 = x[0];
            var x2 = x[1];
            var x3 = x[2];
            return 14 * x3 + x1 + 1;
        }

        private static Func<double[], double>[] Dx;

        private static double[] FindGrad(double[] x)
        {
            var dfDx = Dx.Select(f => f(x)).ToArray();

            double norm = Math.Sqrt(dfDx.Select(v => Math.Pow(v, 2)).Sum());

            return dfDx.Select(v => v / norm).ToArray();
        }

        private static void Main(string[] args)
        {
            Dx = new Func<double[], double>[] { Dx1, Dx2, Dx3 };
            int N = Dx.Length;

            double epsilon = 0.01;
            double a = 1, b = 0.5;
            double[] x_cur = new double[N].Select(x => 1.0).ToArray(), x_next = x_cur;
            double[] grad = new double[N];

            while (true)
            {
                x_cur = x_next;
                grad = FindGrad(x_cur);
                x_next = x_cur.Select((x, i) => x - a * grad[i]).ToArray();

                var left = F(x_cur.Select((x, i) => x - x_next[i]).ToArray());
                var g = grad.Select(gri =>
                        (left <= -epsilon * a * Math.Pow(Math.Abs(gri), 2))).All(x => x);
                if (g)  
                    break;
                else
                    a *= b; 
                Console.WriteLine(string.Join(" ", x_cur.Select((x, i) => $"x{i + 1}={x.ToString("f2")}")));
                Console.WriteLine($"y={F(x_cur)}\n");

            }
            Console.WriteLine(string.Join(" ", x_cur.Select((x, i) => $"x{i + 1}={x.ToString("f2")}")));

            Console.WriteLine($"y={F(x_cur).ToString("f2")}");

            Console.ReadKey();
        }
    }
}

