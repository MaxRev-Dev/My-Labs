using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace L3
{
    class Program
    {
        class Point
        {
            float X { get; set; }
            float Y { get; set; }
            float Z { get; set; }

            public Point(float x, float y, float z) : this()
            {
                X = x; Y = y; Z = z;
            }
            public Point()
            {
                Random();
            }

            public bool InFirstOctant()
            {
                return (Math.Sign(X) > 0 && Math.Sign(Y) > 0 && Math.Sign(Z) > 0);
            }
            public static Random random = new Random();
            private void Random()
            {
                X = random.Next(-10, 10);
                Y = random.Next(-10, 10);
                Z = random.Next(-10, 10);
            }
            public override string ToString()
            {
                return string.Format("x:{0} y:{1} z:{2}", X.ToString("f2"), Y.ToString("f2"), Z.ToString("f2"));
            }
        }

        static void Main(string[] args)
        {
            Point[] arr = new Point[15].Select(x => x = new Point()).ToArray();

            Console.WriteLine("Points:\n"
                + string.Join("\n", arr.Select(x => x.ToString())));

            Console.WriteLine("\nPoints in first octant:\n"
               + string.Join("\n", arr.Where(x => x.InFirstOctant())));
            Console.ReadLine();
        }
    }
}
