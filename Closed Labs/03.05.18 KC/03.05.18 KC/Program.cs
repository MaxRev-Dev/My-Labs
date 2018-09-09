using System;
using System.Text;

namespace ClassEx
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.OutputEncoding = Encoding.UTF8;
            Console.WriteLine("Введіть перший член ГП: ");
            double a0 = double.Parse(Console.ReadLine().ToString());

            Console.WriteLine("Введіть знаменник ГП: ");
            double q = double.Parse(Console.ReadLine().ToString());

            Console.WriteLine("Введіть кількість членів ГП: ");
            int n = int.Parse(Console.ReadLine().ToString());

            var gp = new GeometricProgression() { A0 = a0, N = n, Q = q };
            if (gp.HasMaxLastItem())
            {
                Console.WriteLine("Прогресія має останній найбільший член");
                Console.WriteLine("Це {0}", gp.GetLastItem());
            }
            else
                Console.WriteLine("Прогресія спадна і не має останнього найбільшого члена");
            Console.ReadKey();
        }
        class GeometricProgression
        {
            public double A0 { get; set; }
            public double Q { get; set; }
            public int N { get; set; }
            public double GetLastItem(int n = 1)
            {
                return A0 * Math.Pow(Q, N - n);
            }
            public bool HasMaxLastItem()
            {
                return GetLastItem(1) > GetLastItem(2);
            }
        }
    }
}
