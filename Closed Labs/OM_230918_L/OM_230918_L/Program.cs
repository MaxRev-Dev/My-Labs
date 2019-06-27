using System;
using System.Collections.Generic;
using System.Linq;

namespace OM_230918_L
{
    internal class Program
    {
        private static void Main(string[] args)
        {
            double x0 = 7.0, xn = 11.0, e = 0.01,
                min = double.MaxValue;

            double f(double x) => Math.Cos(x) / Math.Pow(x, 2);

            double fDx(double x) => -(x * Math.Sin(x) * 2.0 * Math.Cos(x)) / Math.Pow(x, 3);

            List<double> Derivs = new List<double>();
            double L(double a, double b)
            {
                for (double i = a; i <= b; i += e)
                    Derivs.Add(fDx(i));
                return Derivs.Max();
            }
            var l = L(x0, xn);
            var h = 2.0 * e / l;
            var xi = x0 + h / 2;


            for (int i = 1; xi != xn; i++)
            {
                xi = Math.Min(xi + h * i, xn);
                var y = f(xi);
                if (min > y)
                {
                    min = y;
                }
            }
            Console.WriteLine("Minimum passive:" + min.ToString("f5"));


            min = double.MaxValue;
            xi = x0 + h / 2;
            var Fi = f(xi);
            for (int i = 1; xi != xn; i++)
            {
                Fi = Math.Min(Fi, f(xi));
                xi = Math.Min(xi + h * (f(xi) - Fi / l), xn);
                var y = f(xi);
                if (min > y)
                {
                    min = y;
                }
            }
            Console.WriteLine("Minimum gradual:" + min.ToString("f5"));
            Console.Read();
        }
    }
}
