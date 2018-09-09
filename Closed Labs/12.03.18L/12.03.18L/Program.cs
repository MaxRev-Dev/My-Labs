using System;
using System.Linq;
using System.Text;

namespace PlaneSpace
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.OutputEncoding = Encoding.GetEncoding(1251);

            Console.Write("Введіть нормаль площини [A B C D=0]: ");

            var f = Console.ReadLine()
                .Split(new char[] { ' ', '\t' },StringSplitOptions.RemoveEmptyEntries)
                .Select(x => double.Parse(x)).ToArray();


            Plane pl = (f.Count() == 4) ?
                new Plane(f[0], f[1], f[2], f[3]) :
                new Plane(f[0], f[1], f[2]);

            Console.Write("Введіть координати точки [x y z]: ");

            f = Console.ReadLine()
                .Split(' ')
                .Select(x => double.Parse(x)).ToArray();

            if (pl.Contains(f[0], f[1], f[2]))
                Console.WriteLine("Точка належить площині");
            else Console.WriteLine("Точка не належить площині");

            Console.ReadKey();
        }
    }

    class Plane
    {
        public Plane(double A, double B, double C, double D = 0)
        {
            a = A; b = B; c = C; d = D;
        }
        public bool Contains(double x, double y, double z) => a * x + b * y + c * z + d == 0;
        public double a, b, c, d;
    }
}
