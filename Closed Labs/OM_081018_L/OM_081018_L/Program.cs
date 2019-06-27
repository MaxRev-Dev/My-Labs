using System;

namespace GlobalMinimum
{
    internal class Program
    {
        private static void Main(string[] args)
        {

            double A = 1.0, B = 1.5, e = 0.05;

            double f(double x) => Math.Pow(x, 2) - 2.0 * x + Math.Pow(Math.E, -x);

            double ak = A, bk = B, min;
            double lambda = (Math.Sqrt(5.0) + 3) / 2.0;

            var zk = bk - (bk - ak) / lambda; // праве наближення
            var tk = ak + (bk - ak) / lambda; // ліве наближення

            while (Math.Abs(tk - zk) > e)
            {
                if (f(tk) < f(zk))
                    bk = zk;
                else
                    ak = tk;
                zk = bk - (bk - ak) / lambda;
                tk = ak + (bk - ak) / lambda;
            }

            min = (bk + ak) / 2;

            Console.WriteLine("Golden section-search: {0}", min);



            int k = 1, j = 1;
            ak = A; bk = B; // початкові [А0, B0]


            double fk = Fn(j);
            double fk1 = Fn(j + 1);
            double fk2 = fk1 + fk;
            while (!(fk1 < (B - A) / e && (B - A) / e <= fk2))
            //обчислюємо кількість кроків
            {
                j++;
                fk = Fn(j);
                fk1 = Fn(j + 1);
                fk2 = fk1 + fk;
            }

            int m = j;

            zk = ak + (bk + ak) * (Fn(m + 1) * 1.0 / Fn(m + 2)); // праве наближення
            tk = ak + (bk + ak) * (Fn(m) * 1.0 / Fn(m + 2)); // ліве наближення
          
            while (Math.Abs(tk - zk) > e)
            {
                if (f(tk) < f(zk))
                    bk = zk;
                else
                    ak = tk;
                zk = ak + (bk + ak) * (Fn(m - k + 1) * 1.0 / Fn(m + 2));
                tk = ak + (bk + ak) * (Fn(m - k) * 1.0 / Fn(m + 2));
                k++;
            }

            min = (bk + ak) / 2;


            Console.WriteLine("Fibonachi numbers method: {0}", min);

            Console.Read();

        }

        private static int Fn(int n) // n число Фібоначчі
        {
            return n == 0 ? 0 : (n == 1 ? 1 : Fn(n - 1) + Fn(n - 2));
        }
    }
}
