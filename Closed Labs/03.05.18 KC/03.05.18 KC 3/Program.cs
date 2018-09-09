using System;
using System.Linq;

namespace LinearInequality
{
    class Program
    {
        static void Main(string[] args)
        {
            LinearInequalitySystem2 lis2 = new LinearInequalitySystem2();
            lis2.SetA(2, 2, 10);
            lis2.Print();
            var d = Console.ReadLine().Split(' ').Select(x => double.Parse(x)).ToArray();
            if (lis2.IsApplicable(d))
            {
                Console.WriteLine("Вектор задовольняє систему нерівностей");
            }
            else
            {
                Console.WriteLine("Вектор не задовольняє систему нерівностей");
            }

            LinearInequalitySystem3 lis3 = new LinearInequalitySystem3();
            lis3.SetA(1, 3, 10);
            lis3.Print();

            d = Console.ReadLine().Split(' ').Select(x => double.Parse(x)).ToArray();
            if (lis3.IsApplicable(d))
            {
                Console.WriteLine("Вектор задовольняє систему нерівностей");
            }
            else
            {
                Console.WriteLine("Вектор не задовольняє систему нерівностей");
            }

            Console.ReadKey();
        }
        class LinearInequalitySystem2
        {
            protected Row[] Sys;
            public Row[] System { get; }
            public class Row
            {
                private double[] a;
                private double b;
                private object[] x;
                public double B
                {
                    get {
                        return this.b;
                    }
                    set {
                        this.b = value;
                    }
                }
                public object[] X
                {
                    get {
                        return this.x;
                    }
                }
                public double[] A
                {
                    get {
                        return this.a;
                    }
                }
                public bool IsApplicable(double[] x_v)
                {
                    if (x_v.Count() != a.Count())
                    {
                        return false;
                    }
                    double sum = 0;
                    for (int i = 0; i < a.Count(); i++)
                    {
                        sum += a[i] * x_v[i];
                    }
                    if (sum <= b)
                    {
                        return true;
                    }
                    return false;
                }
                public Row(int count)
                {
                    b = 0;
                    a = new double[count].Select(x => x = 0).ToArray();
                    x = new string[count].Select(x => "x").ToArray();
                }
            }
            public void Print()
            {
                foreach (var i in Sys)
                {
                    Console.Write("{0}{1} ", i.A[0], i.X[0]);
                    for (int r = 1; r < i.A.Count(); r++)
                    {
                        Console.Write("+ {0}{1} ", i.A[r], i.X[r]);
                    }
                    Console.WriteLine(" <= {0}", i.B);
                }
            }
            public bool IsApplicable(double[] x)
            {
                foreach (var i in Sys)
                {
                    if (!i.IsApplicable(x))
                    {
                        return false;
                    }
                }
                return true;
            }
            public LinearInequalitySystem2()
            {
                Sys = new Row[2].Select(x => x = new Row(2)).ToArray();
            }
            public void SetA(int row, int i, double val)
            {
                this.Sys[row - 1].A[i - 1] = val;
            }
            public void SetB(int i, double val)
            {
                this.Sys[i - 1].B = val;
            }
        }
        class LinearInequalitySystem3 : LinearInequalitySystem2
        {
            public LinearInequalitySystem3()
            {
                Sys = new Row[3].Select(x => x = new Row(3)).ToArray();
            }
        }
    }
}
