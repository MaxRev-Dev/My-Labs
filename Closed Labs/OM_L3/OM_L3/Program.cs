using System;
using System.Linq;
using System.Linq.Expressions;

namespace BMR
{
    internal class Program
    {
        internal class Point
        {
            public Point() { }
            public Point(double x, double y)
            {
                X = x; Y = y;
            }
            public double X { get; set; }
            public double Y { get; set; }
            public override string ToString()
            {
                return $"x: {X}, y: {Y}";
            }

            internal Point Copy()
            {
                return new Point(X, Y);
            }
        }


        private class BrokenLinesMethod
        {

            private Point CalculateNext(Point left, Point right)
            {
                double newX = ((left.Y - right.Y) / 180 + left.X + right.X) / 2.0;
                return new Point(newX, left.Y + 180.0 * (left.X - newX));
            }
            public Point Minimum(Expression<Func<double, double>> expression, double A, double B, int itersCount)
            {
                var fun = expression.Compile();
                double F(double x) => fun.Invoke(x);
                var points = new Point[itersCount + 1].Select(xv => new Point()).ToArray();
                var minimums = new Point[itersCount].Select(xv => new Point()).ToArray();

                points[0] = new Point(A, F(A));
                points[1] = new Point(B, F(B));

                minimums[0] = CalculateNext(points[0], points[1]);

                int indexOfMinimum = 0, iter, stepi;
                for (iter = 2; iter <= itersCount; iter++)
                {
                    var ymin = minimums.Min(t => t.Y);
                    indexOfMinimum = minimums.ToList().Select(xv => xv.Y).ToList().IndexOf(ymin);

                    for (stepi = 1; stepi <= (iter - indexOfMinimum - 1); stepi++)
                        points[iter - stepi + 1] = points[iter - stepi].Copy();

                    points[indexOfMinimum + 1].X = minimums[indexOfMinimum].X;

                    points[indexOfMinimum + 1].Y = F(points[indexOfMinimum + 1].X);

                    for (stepi = 1; stepi <= (iter - indexOfMinimum - 1); stepi++)
                        minimums[iter - stepi] = minimums[iter - stepi - 1].Copy();

                    minimums[indexOfMinimum] = CalculateNext(points[indexOfMinimum], points[indexOfMinimum + 1]);

                    minimums[indexOfMinimum + 1] = CalculateNext(points[indexOfMinimum + 1], points[indexOfMinimum + 2]);
                    if (points[indexOfMinimum].X == 0.0)
                    {

                    }
                    Console.WriteLine($"[{iter}] {points[indexOfMinimum]}");
                }
                return points[indexOfMinimum];
            }
        }


        private static void Main(string[] args)
        {
            Console.WriteLine("Result: " +
                new BrokenLinesMethod()
                .Minimum(
x => Math.Pow(Math.E, x) + 1.0 / x,
                            A: 0.5, B: 0.59,
                            itersCount: 7000)
                );
            Console.ReadKey();
        }
    }
}

//x => Math.Pow(Math.E, x) + 1.0 / x