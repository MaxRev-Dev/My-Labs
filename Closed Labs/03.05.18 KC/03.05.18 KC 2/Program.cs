using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GP_Array
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.OutputEncoding = Encoding.UTF8;
            Console.WriteLine("Введіть кількість об'єктів ГП: ");
            int count = int.Parse(Console.ReadLine());
            GeometricProgression[] gp_array = new GeometricProgression[count];
            for (var i = 0; i < count; i++)
            {
                Console.WriteLine("[" + i + 1 + "] Введіть перший член ГП: ");
                double a0 = double.Parse(Console.ReadLine().ToString());

                Console.WriteLine("[" + i + 1 + "] Введіть знаменник ГП: ");
                double q = double.Parse(Console.ReadLine().ToString());

                Console.WriteLine("[" + i + 1 + "] Введіть кількість членів ГП: ");
                int n = int.Parse(Console.ReadLine().ToString());
                gp_array[i] = new GeometricProgression() { A0 = a0, N = n, Q = q };
            }
            List<double> maxItems = new List<double>();
            foreach (var i in gp_array)
            {
                if (i.HasMaxLastItem())
                {
                    maxItems.Add(i.GetLastItem());
                }
            }
            if (maxItems.Count > 0)
            {
                Console.WriteLine("Номер прогресії = {0}", maxItems.OrderByDescending(x => x).First());
            }
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
