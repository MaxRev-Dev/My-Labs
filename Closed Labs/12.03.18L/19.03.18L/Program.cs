using System;
using System.Linq;
using System.Text;

namespace PlaneSSpace
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.OutputEncoding = Encoding.GetEncoding(1251);

            Plane[] pls = new Plane[1000];
            var planes = pls.Select(x => x = new Plane()).ToArray();
            foreach (var i in planes)
                i.SetRandom();

            Console.Write("Введіть координати точки [x y z]: ");
            var f = Console.ReadLine()
                .Split(new char[] { ' ', '\t' }, StringSplitOptions.RemoveEmptyEntries)
                .Select(x => double.Parse(x)).ToArray();
            Console.WriteLine("Генеруємо 1000 випадкових площин...");
            Console.WriteLine("Ось перші 20..");
            foreach (var i in planes.OrderByDescending(x => x.Contains(f[0], f[1], f[2])).Take(20))
            {
                if (i.Contains(f[0], f[1], f[2]))
                    Console.WriteLine("Точка належить площині {0}", i.GetName());
                else Console.WriteLine("Точка не належить площині {0}", i.GetName());
            }

            Console.ReadKey();
        }
    }

    class Plane
    {
        public Plane() { } // Default ctor
        public Plane(double A, double B, double C, double D = 0)
        {
            a = A; b = B; c = C; d = D;
        }

        #region RandomizePlanes
        private static Random rand = new Random();
        public static int GetRandomNumber(int min, int max)
        {
            lock (rand) // synchronize
            {
                return rand.Next(min, max);
            }
        }
        private double GetNext() => Convert.ToDouble(GetRandomNumber(-10, 10));
        #endregion

        public void SetRandom()
        {
            a = GetNext();
            b = GetNext();
            c = GetNext();
            d = GetNext();
        }
        public string GetName() =>
            string.Format("{0}x + {1}y + {2}z + {3} = 0:", a.ToString("f1"), b.ToString("f1"), c.ToString("f1"), d.ToString("f1"));
        public bool Contains(double x, double y, double z) => a * x + b * y + c * z + d == 0;
        public double a, b, c, d; 
    }
}
