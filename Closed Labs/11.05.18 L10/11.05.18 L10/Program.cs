using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Decorator
{
    class Program
    {
        static void Main(string[] args)
        {

            //створення об'єків систем             
            SystemFactory factory = new SystemFactory();

            ISystem system2 = factory.CreateLinearSystem2();
            ISystem system3 = factory.CreateLinearSystem3();

            Console.WriteLine("\nSystem 1 (2 rows 2 vars): ");
            system2.Show();    //вивід через перевантажений метод 
            Console.WriteLine("\nSystem 1 (3 rows 3 vars): ");
            system3.Show();      //вивід системи в консоль


            Console.WriteLine("Enter x1 x2");
            var x = Console.ReadLine()
                .Split(new char[] { ' ', '\t' }, StringSplitOptions.RemoveEmptyEntries)
                .Select(f => double.Parse(f)).ToArray();
            Console.WriteLine("X is " + (
                // notify wrapper   -> comparison  -  system   -> method
                new ComparableNotifier(new Comparable(system2)).IsEqualTo(x)
                ? "the root" : "not root") + " of equatation");

            Console.WriteLine("Enter x1 x2 x3");
            x = Console.ReadLine().Split(new char[] { ' ', '\t' }, StringSplitOptions.RemoveEmptyEntries).Select(f => double.Parse(f)).ToArray();
            Console.WriteLine("X is " + (new Comparable(system3).IsEqualTo(x) ? "the root" : "not root") + " of equatation");

            system2 = new LSystem2();

            //ввід вручну
            //для правильної системи 
            // 5*1+5+1=10
            for (int i = 0; i < 2; i++)
            {
                for (int j = 0; j < 2; j++)
                {
                    Console.Write("Enter line[" + (i + 1) + "] coef[" + (j + 1) + "]: ");
                    system2.SetCoef(i, j, double.Parse(Console.ReadLine()));
                }
                Console.Write("Enter line[" + (i + 1) + "] -> B: ");
                system2.SetB(i, double.Parse(Console.ReadLine()));
            }

            Console.WriteLine("Enter x1 x2");
            x = Console.ReadLine().Split(new char[] { ' ', '\t' }, StringSplitOptions.RemoveEmptyEntries).Select(f => double.Parse(f)).ToArray();
            Console.WriteLine("X is " + (new Comparable(system2).IsEqualTo(x) ? "the root" : "not root") + " of equatation");

            Console.ReadLine();
        }

        // Decorating with comparable function
        interface ISystemComparable
        {
            bool IsEqualTo(double[] x);
        }
        // Abstract decorator
        abstract class Decorator : ISystemComparable
        {
            protected ISystem system;
            public Decorator() { }
            public Decorator(ISystem system)
            {
                this.system = system;
            }

            public abstract bool IsEqualTo(double[] x);
        }
        // Concrete decorator 1
        class Comparable : Decorator
        {
            protected ISystem System;
            public Comparable() { }
            public Comparable(ISystem system) : base(system) { this.System = system; }

            public override bool IsEqualTo(double[] x)
            {
                for (int i = 0; i < system.System.Length; i++)
                {
                    double acc = 0;
                    for (int it = 0; it < system.System[i].a.Length; it++)
                        acc += system.System[i].a[it] * x[it];

                    if (acc != this.system.System[i].b)
                        return false;
                }
                return true;
            }

        }
        // Concrete decorator 2
        // On Comparison Notifier Wrapper
        class ComparableNotifier : Comparable
        {
            Comparable comparable;
            public ComparableNotifier(ISystem system) : base(system) { }
            public ComparableNotifier(Comparable system) { this.comparable = system; }
            public override bool IsEqualTo(double[] x)
            {
                Console.WriteLine("Comparing vector and system");
                return comparable.IsEqualTo(x);
            }
        }

        #region System
        // Abstract Factory
        interface ISystemCreator
        {
            ISystem CreateLinearSystem2();
            ISystem CreateLinearSystem3();
        }
        // Concrete Factory
        class SystemFactory : ISystemCreator
        {
            public ISystem CreateLinearSystem2() { return new LSystem2(); }
            public ISystem CreateLinearSystem3() { return new LSystem3(); }
        }
        // Concrete Product A
        sealed class LSystem2 : BaseSystem
        {
            public LSystem2() : base(2) { }

            public override void Show()
            {
                foreach (var x in System)
                    Console.WriteLine("{0}*{1}+{2}*{3}={4}", x.a[0], x.x[0], x.a[1], x.x[1], x.b);
            }
        }
        // Concrete Product B
        sealed class LSystem3 : BaseSystem
        {
            public LSystem3() : base(3) { }

            public override void Show()
            {
                foreach (var x in System)
                    Console.WriteLine("{0}*{1}+{2}*{3}+{4}*{5}={6}", x.a[0], x.x[0], x.a[1], x.x[1], x.a[2], x.x[2], x.b);
            }
        }
        // Abstract Product
        interface ISystem
        {
            void Show();
            void SetCoef(int line, int i, double coef);
            void SetB(int i, double value);
            RandomLine[] System { get; }
        }
        #endregion

        #region Other

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
            public void SetB(int i, double value) => lines[i].b = value;
            public void SetCoef(int line, int i, double coef) => lines[line].a[i] = coef;

            public abstract void Show();
        }

        interface IRandom
        {
            int GetRandomNumber(int min, int max);
            double GetNext();
        }
        /// <summary>
        /// Генерує випадкове число від -10 до 10
        /// </summary>
        public class Randomizer
        {
            private static Random rand = new Random();

            protected static int GetRandomNumber(int min, int max)
            {
                return rand.Next(min, max);
            }
            protected static double GetNext() => Convert.ToDouble(GetRandomNumber(-10, 10));
        }
        #endregion

    }
}
