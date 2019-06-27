using System;
using System.Linq;

namespace OM_271018_L3
{
    internal class Program
    {
        private static double FL(double a, double b)
        {
            return Math.Max(FuncDerivative(a), FuncDerivative(b));
        }

        private static double Func(double x)
        {
            return Math.Cos(Math.Pow(x, 3)) / x;
        }

        private static double FuncDerivative(double x)
        {
            return -(x * Math.Sin(x) * 2.0 * Math.Cos(x)) / Math.Pow(x, 3);
        }

        private static readonly double Deg = 180;

        private static void NextPoints(double[] points, double x1, double y1, double x2, double y2)
        {
            double left = (y1 - y2) / (2 * Deg) + (x1 + x2) / 2;
            points[0] = left;
            points[1] = y1 + Deg * x1 - Deg * left;
        }
        private static void Main(string[] args)
        {
            double
                xA = 7.0,
                xB = 11.0, constLip = FL(xA, xB);
            const int iterations = 10;
            double[]
                CurrentPoints = new double[2],
                minX = new double[iterations],
                minY = new double[iterations],
                x = new double[iterations + 1],
                y = new double[iterations + 1];
            int minNum = 0, i, j;
            x[0] = xA; //left x
            x[1] = xB; //right x
            y[0] = Func(x[0]); 
            y[1] = Func(x[1]);

            NextPoints(CurrentPoints, x[0], y[0], x[1], y[1]); //find first point
            minX[0] = CurrentPoints[0];
            minY[0] = CurrentPoints[1];
            for (i = 2; i <= iterations; i++)
            {
                minNum = minY.ToList().IndexOf(minY.Min()); // minimum to curve
                for (j = 1; j <= (i - minNum - 1); j++)
                {
                    x[i - j + 1] = x[i - j]; // moving known points
                    y[i - j + 1] = y[i - j];
                }
                x[minNum + 1] = minX[minNum]; // placing new points to array of known
                y[minNum + 1] = Func(x[minNum + 1]);
                for (j = 1; j <= (i - minNum - 1); j++)
                {
                    minX[i - j] = minX[i - j - 1];
                    minY[i - j] = minY[i - j - 1];
                }
                //x+1
                NextPoints(CurrentPoints, x[minNum], y[minNum], x[minNum + 1], y[minNum + 1]);
                minX[minNum] = CurrentPoints[0];
                minY[minNum] = CurrentPoints[1];
                //x+2
                NextPoints(CurrentPoints, x[minNum + 1], y[minNum + 1], x[minNum + 2], y[minNum + 2]);
                minX[minNum + 1] = CurrentPoints[0];
                minY[minNum + 1] = CurrentPoints[1]; 

                Console.WriteLine($"[{i}] {x[minNum]} {y[minNum]}");
            }
            Console.WriteLine($"Minimum: {x[minNum]} {y[minNum]}");

            Console.ReadKey();

        }
    }
}
