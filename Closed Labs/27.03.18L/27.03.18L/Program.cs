using System;
using System.Linq;

namespace SOLE
{
    sealed class Program
    {
        static void Main(string[] args)
        {
            //створення об'єків систем               
            LSystem2 system2 = new LSystem2();
            LSystem3 system3 = new LSystem3();
            Console.WriteLine("\nSystem 1 (2 rows 2 vars): ");
            system2.Show();    //вивід через перевантажений метод 
            Console.WriteLine("\nSystem 1 (3 rows 3 vars): ");
            system3.Show();      //вивід системи в консоль

            Console.WriteLine("Enter x1 x2");
            var x = Console.ReadLine()
                .Split(new char[] { ' ','\t' },StringSplitOptions.RemoveEmptyEntries)
                .Select(f => double.Parse(f)).ToArray();
            Console.WriteLine("X is " + (system2.IsEqualTo(x) ? "the root" : "not root") + " of equatation");

            Console.WriteLine("Enter x1 x2 x3");
            x = Console.ReadLine().Split(new char[] { ' ','\t' },StringSplitOptions.RemoveEmptyEntries).Select(f => double.Parse(f)).ToArray();
            Console.WriteLine("X is " + (system3.IsEqualTo(x) ? "the root" : "not root") + " of equatation");

            system2 = new LSystem2();

            //ввід вручну
            //для правильної системи 
            // 5*1+5+1=10
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    Console.Write("Enter line[" + (i + 1) + "] coef[" + (j + 1) + "]: ");
                    system2.SetCoef(i,j,double.Parse(Console.ReadLine()));
                }
                Console.Write("Enter line[" + (i + 1) + "] -> B: ");
                system2.SetB(i,double.Parse(Console.ReadLine()));
            }

            Console.WriteLine("Enter x1 x2");
            x = Console.ReadLine().Split(new char[] { ' ','\t' },StringSplitOptions.RemoveEmptyEntries).Select(f => double.Parse(f)).ToArray();
            Console.WriteLine("X is " + (system2.IsEqualTo(x) ? "the root" : "not root") + " of equatation");

            Console.ReadLine();
        }

        sealed class LSystem2 : BaseSystem
        {
            public LSystem2() : base(2) { }      
            public override void Show()
            {
                foreach (var x in System)
                    Console.WriteLine("{0}*{1}+{2}*{3}={4}",x.a[0],x.x[0],x.a[1],x.x[1],x.b);
            }
        }
        sealed class LSystem3 : BaseSystem
        {
            public LSystem3() : base(3) { }
            public override void Show()
            {
                foreach (var x in System)
                    Console.WriteLine("{0}*{1}+{2}*{3}+{4}*{5}={6}",x.a[0],x.x[0],x.a[1],x.x[1],x.a[2],x.x[2],x.b);
            }
        }

        interface ISystem
        {
            void Show();
            void SetCoef(int line,int i,double coef);
            void SetB(int i,double value);
        }
        interface ILine
        {
            double[] A { get; }
            object[] X { get; }
            double B { get; }
        }

        /// <summary>
        /// Абстрактний клас для ліній. Описує з чого складається лінія
        /// </summary>
        public abstract class Line : Randomizer, ILine  
        {
            public double[] a;
            public object[] x;
            public double b;

            public abstract double[] A { get; }
            public abstract object[] X { get; }
            public abstract double B { get; }
                              
        }

        /// <summary>
        /// Випадкова лінія в системі. Наслідується від простої лінії   
        /// </summary>
        public class RandomLine : Line
        {
            public RandomLine(int count)
            {
                x = new object[count];
                a = new double[count];

                // для виведення х, 
                //можна потім замінити на число і знайти корені
                x = x.Select(x => x = "x").ToArray();

                SetRandom();
            }

            public override double[] A => this.a;
            public override object[] X => this.x;
            public override double B => this.b;

            public void SetRandom()
            {
                a = a.Select(i => i = GetNext()).ToArray();
                b = GetNext();
            }
        }
        /// <summary>
        /// Абстрактна система
        /// </summary>
        abstract class BaseSystem : ISystem
        {
            protected RandomLine[] lines = null;
            public RandomLine[] System => this.lines;
            public BaseSystem(int rows)
            {
                var obj = new RandomLine[rows];
                this.lines = obj.Select(x => x = new RandomLine(rows)).ToArray();
            }
            public void SetB(int i,double value) => lines[i].b = value;
            public void SetCoef(int line,int i,double coef) => lines[line].a[i] = coef;
            public bool IsEqualTo(double[] x)
            {
                for (int i = 0; i < lines.Length; i++) {
                    double acc = 0;
                    for (int it = 0; it < lines[i].a.Length; it++)
                        acc += lines[i].a[it] * x[it];

                    if (acc != this.lines[i].b)
                        return false;
                }
                return true;
            }
            public abstract void Show();
        }

        interface IRandom
        {
            int GetRandomNumber(int min,int max);
            double GetNext();
        }
        /// <summary>
        /// Генерує випадкове число від -10 до 10
        /// </summary>
        public class Randomizer
        {
            private static Random rand = new Random();

            protected static int GetRandomNumber(int min,int max)
            {
                return rand.Next(min,max);
            }
            protected static double GetNext() => Convert.ToDouble(GetRandomNumber(-10,10));
        }  

         #region OLD

        class LinearSystem2
        {
            //тут зберігаються всі змінні системи
            //до цього поля є доступ з похідного класу
            protected LinearLine[] lines = null;
            //створення системи, генерування чисел
            public LinearSystem2(int rows = 2)
            {
                var obj = new LinearLine[rows];
                this.lines = obj.Select(x => x = new LinearLine(rows)).ToArray();
            }
            public virtual LinearLine[] System { get { return lines; } }
            //заміщення методу створення рядка, тут 2 змінні замість 3        

            public void Show()
            {
                for (int i = 0; i < lines.Length; i++) {
                    for (int j = 0; j < lines[i].a.Length; j++) {
                        Console.Write("{0}*{1}",lines[i].a[j],lines[i].x[j]);
                        if (j < lines[i].a.Length - 1) Console.Write("+");
                    }
                    Console.WriteLine("={0}",lines[i].b);
                }
            }


            public virtual void ShowSystem()
            {
                foreach (var x in System)
                    Console.WriteLine("{0}*{1}+{2}*{3}={4}",x.a[0],x.x[0],x.a[1],x.x[1],x.b);
            }

            //перевірка коренів рівняння
            public bool IsEqualTo(double[] x)
            {
                for (int i = 0; i < lines.Length; i++) {
                    double acc = 0;
                    for (int it = 0; it < lines[i].a.Length; it++)
                        acc += lines[i].a[it] * x[it];

                    if (acc != this.lines[i].b)
                        return false;
                }
                return true;
            }

            // Задання коецієнтів рівняння
            public void SetCoef(int line,int i,double coef)
            {
                lines[line].a[i] = coef;
            }
            // Задання вільних членів
            public void SetB(int i,double value)
            {
                lines[i].b = value;
            }

            // Лінія-вираз в системі
            public class LinearLine
            {
                public double[] a;
                public object[] x;
                public double b;
                public LinearLine(int count)
                {
                    x = new object[count];
                    a = new double[count];

                    // для виведення х, 
                    //можна потім замінити на число і знайти корені
                    x = x.Select(x => x = "x").ToArray();

                    SetRandom();
                }

                // той же рандом
                #region Randomize
                private static Random rand = new Random();
                private static int GetRandomNumber(int min,int max)
                {
                    return rand.Next(min,max);
                }
                private double GetNext() => Convert.ToDouble(GetRandomNumber(-10,10));
                #endregion

                public void SetRandom()
                {
                    a = a.Select(i => i = GetNext()).ToArray();
                    b = GetNext();
                }
            }
        }
        class LinearSystem3 : LinearSystem2
        {
            public LinearSystem3(int rows = 3)
            {
                var obj = new LinearLine[rows];
                this.lines = obj.Select(x => x = new LinearLine(rows)).ToArray();
            }
            //Властивість системи, повертає lines 
            public override LinearLine[] System { get { return lines; } }

            //віртуальний метод для виведення
            public override void ShowSystem()
            {
                foreach (var x in System)
                    Console.WriteLine("{0}*{1}+{2}*{3}+{4}*{5}={6}",x.a[0],x.x[0],x.a[1],x.x[1],x.a[2],x.x[2],x.b);
            }

        }

        #endregion
    }
}
