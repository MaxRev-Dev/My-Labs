using System;
using System.Collections.Generic;

namespace Vec
{
    // Abstract Product 
    public abstract class Product
    {
        public abstract void FindMAx(int size);
        public abstract void Input(int size);
        public abstract void Print(int size);
        protected string Name { get; }
        public abstract void Add(Product c);
        public abstract void Remove(Product c);
        public abstract void Display(int depth = 1);
    }

    // Concrete Product 1
    public class Vec : Product
    {
        private int k;
        readonly public int size;

        private int[] _arr;

        public Vec(int size) => this._arr = new int[this.size = size];

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

        public override void Add(Product c)
        {
            string errormsg = "Add Error: Vector can`t have siblings";
            Console.WriteLine(errormsg); 
            throw new Exception(errormsg);
        }

        public override void Remove(Product c)
        {
            string errormsg = "Remove Error: Vector doesn`t contain siblings";
            Console.WriteLine(errormsg); 
            throw new Exception(errormsg);
        }

        public override void Display(int depth)
        {
            Console.WriteLine("[leaf]>" + new String('*', depth) + "Vector[" + size + "]");
        }
    }

    // Composite - matrix. Can contain vectors and matrixes
    public class Matrix : Product
    {
        public int k;
        public int v;
        public int size;
        private readonly int[,] _arr;

        public Matrix(int size) { this._arr = new int[this.size = size, size]; }

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
        private List<Product> _children = new List<Product>();

        public override void Add(Product component) => _children.Add(component);

        public override void Remove(Product component) => _children.Remove(component);

        public override void Display(int depth = 1)
        {
            Console.WriteLine(
                (depth == 1 ? "[root]>" : "[comp]>")
                   + new String('*', depth) + "Matrix[" + size + "]");

            // Recursively display child nodes
            foreach (Product component in _children)
                component.Display(depth + 2);
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

        //creator for fabric objects access
        Vec.Creator creator = new Vec.Creator();

        // creating branch with 1 composite leaf
        Vec.Product comp = creator.GetMatrix(5);
        comp.Add(creator.GetMatrix(4));

        // creating branch with 2 leaves
        var comp2 = creator.GetMatrix(4);
        comp2.Add(creator.GetMatrix(4));
        comp2.Add(creator.GetVector(10));
        comp.Add(comp2);

        // Creating root object
        Vec.Product obj = creator.GetMatrix(size);
        obj.Add(comp);
        obj.Display();

        try
        {
            //Trying to add to and remove leaf from leaf. Assert error
            var leaf = creator.GetVector(10);
            var leaf2 = creator.GetVector(5);
            leaf.Add(leaf2);
        }
        catch { Console.WriteLine("You tried to add leaf to another leaf!!!"); }

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

