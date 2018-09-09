using System;

namespace Vec
{
    // Abstract Product 
    public abstract class Product
    {
        public abstract void FindMAx(int size);
        public abstract void Input(int size);
        public abstract void Print(int size);
    }

    // Concrete Product 1
    public class Vec : Product
    {
        public int k;
        public int v;
        public int size;

        private int[] _arr;

        public Vec(int size)
        {
            this._arr = new int[size];
        }

        public override void Input(int size)
        {
            Random rand = new Random();
            for (int i = 0; i < _arr.Length; i++)
            {
                _arr[i] = rand.Next(-100, 100);
            }

        }

        public override void Print(int size)
        {
            Console.WriteLine("Your vector:");
            for (int i = 0; i < _arr.Length; i++)
            {
                Console.Write("{0} ", _arr[i]);
            }
            Console.WriteLine();
        }

        public override void FindMAx(int size)
        {
            int max = _arr[0];
            for (int i = 0; i < _arr.Length; i++)
            {
                if (max < _arr[i])
                {
                    max = _arr[i];
                    k = i;
                }
            }
            Console.WriteLine("Max element is number: " + (k + 1));
        }

    }

    // Concrete Product 2
    public class Matrix : Vec
    {
        private int[,] _arr;

        public Matrix(int size) : base(size)
        {
            this._arr = new int[size, size];
        }

        public override void Input(int size)
        {
            Random rand = new Random();
            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    _arr[i, j] = rand.Next(-100, 100);
                }
            }
        }

        public override void Print(int size)
        {
            Console.WriteLine("Your matrix: ");
            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    Console.Write(_arr[i, j] + "\t");
                }
                Console.WriteLine();
            }
        }

        public override void FindMAx(int size)
        {
            int max = _arr[0, 0];
            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    if (max < _arr[i, j])
                    {
                        max = _arr[i, j];
                        k = i;
                        v = j;
                    }
                }
            }
            Console.WriteLine("Max element in " + (k + 1) + " row  and " + (v + 1) + " colomn.");
        }

    }

    // Abstract Creator
    interface IArrayCreator
    {
        Matrix GetMatrix(int size);
        Vec GetVector(int size);
    }
    // Concrete Creator
    class Creator : IArrayCreator
    {
        //Fabric methods
        public Matrix GetMatrix(int size) => new Matrix(size);
        public Vec GetVector(int size) => new Vec(size);
    }
}

class Program
{
    static void Main(string[] args)
    {
        int size = 0;
        Console.Write("How many elements you need? ");
        size = Convert.ToInt32(Console.ReadLine());
        Console.WriteLine();

        Vec.Creator creator = new Vec.Creator();

        Vec.Product obj = creator.GetVector(size);

        do
        {
            //якщо ввести 0, то отримаємо вектор, а якщо 1 - матрицю
            Console.Write("Enter '0' if you want to work with vector and '1' - with matrix: ");
            int userSelect = Convert.ToInt32(Console.ReadLine());
            if (userSelect == 0)
            {
                obj = creator.GetVector(size);
            }
            else if (userSelect == 1)
            {
                obj = creator.GetMatrix(size);
            }
            else
            {
                return;
            }

            obj.Input(size);
            obj.Print(size);
            obj.FindMAx(size);
            Console.WriteLine();

            Console.ReadKey();

        } while (true);

    }

}

