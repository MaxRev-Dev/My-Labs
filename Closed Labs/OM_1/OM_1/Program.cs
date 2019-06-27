using System;
using System.Collections.Generic;
using System.Linq;
using System.Linq.Expressions;

namespace PassiveFullCrossing
{
    internal class Program
    {
        private static void Main(string[] args)
        {
            double eps = 0.01,
                a = 0.1, b = 2.0;
            Expression<Func<double, double>> func =
                x => Math.Pow(Math.E, x) + 1.0 / x;
            Expression<Func<double, double>> deriv =
                x => Math.Pow(Math.E, x) - 1.0 / Math.Pow(x, 2);
              
            var pc = new PassiveCrossing(a, b, eps, func, deriv);
            var r1 = pc.Solve();
            Console.WriteLine($"Passive [xMin:{r1[0]} yMin: {r1[1]} ]");

            var fc = new FullCrossing(a, b, eps, func, deriv);
            var r2 = fc.Solve();
            Console.WriteLine($"Passive [xMin:{r2[0]} yMin: {r2[1]}]");
            Console.ReadLine();
        }
    }

    internal class PassiveCrossing : Crossing
    {
        public PassiveCrossing(
            double a,
            double b,
            double eps,
            Expression<Func<double, double>> func,
            Expression<Func<double, double>> deriv)
            : base(a, b, eps, 1, func, deriv)
        {

        }
        public double[] Solve()
        {
            var h = 2 * Epsilon / L;
            var x = A + h / 2;
            int icr = 1;
            double min = double.MaxValue, max = double.MinValue,xmin = double.MaxValue,xmax = double .MinValue;
            while (true)
            {
                x = Math.Min(x + h * icr++, B);
                var y = FuncX(x);
                if (max < y)
                {
                    xmax = x;
                    max = y;
                }
                if (min > y)
                {
                    xmin = x;
                    min = y;
                }
                if (x == B) break;
            }
            return new[] { xmin,min,xmax, max };
        }

    }

    internal class FullCrossing : Crossing
    {
        public FullCrossing(
            double a,
            double b,
            double eps,
            Expression<Func<double, double>> func,
            Expression<Func<double, double>> deriv)
            : base(a, b, eps, 1, func, deriv)
        {

        }
        public double[] Solve()
        {
            var h = 2 * Epsilon / L;
            var x = A + h / 2;
            double min = double.MaxValue, max = double.MinValue, xmin = double.MaxValue, xmax = double.MinValue;
            x = A + h / 2;
            var Fi = FuncX(x);
            while (true)
            {
                Fi = Math.Min(Fi, FuncX(x));
                x = Math.Min(x + h + (FuncX(x) - Fi) / L, B);
                var y = FuncX(x);
                if (max < y)
                {
                    xmax = x;
                    max = y;
                }
                if (min > y)
                {
                    xmin = x;
                    min = y;
                }
                if (x == B) break;
            }
            return new[] { xmin, min,xmax, max };
        }
    }
    internal abstract class Crossing
    {
        protected Crossing(
            double a,
            double b,
            double eps,
            double step,
            Expression<Func<double, double>> func,
            Expression<Func<double, double>> deriv)
        {
            A = a;
            B = b;
            Epsilon = eps;
            Step = step;
            Deriv = deriv.Compile();
            FuncX = func.Compile();
        }

        private Func<double, double> Deriv { get; }
        public Func<double, double> FuncX { get; }
        public double A { get; set; }
        public double B { get; set; }
        protected double Step { get; set; }
        protected double L
        {
            get {
                return Math.Max(Deriv(A), Deriv(B));  
            }
        }
        protected double Derivative(double x)
        {
            return Deriv.Invoke(x);
        }
        public double Epsilon { get; }
        public int Iterations { get; protected set; }
    }
     
}
