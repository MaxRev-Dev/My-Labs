using System;
using System.Collections.Generic;

namespace L9_Creational_Patterns
{
    class Program
    {
        // Factory Pattern
        static void Main(string[] args)
        {
            var builder = new HouseBuilder();
            var house = builder.GetLivingHouse();
            house.Build();
            var garage = builder.GetGarage();
            garage.Build();
            Console.ReadKey();
        }
    }

    // Abdstract Factory
    interface IHouseList
    {
        LivingHouse GetLivingHouse();
        Garage GetGarage();
    }
    // Concrete Factory
    class HouseBuilder : IHouseList
    {
        public LivingHouse GetLivingHouse() => new LivingHouse();
        public Garage GetGarage() => new Garage();
    }
    // Abstract Product
    abstract class Building
    {
        public Building() { Components = new List<string>(); }
        protected List<string> Components { get; set; }
        public abstract void SetBasement();
        public abstract void SetWalls();
        public abstract void SetWindows();
        public abstract void SetRoot();
        public string Type { get; set; }
        public void Build()
        {
            Console.WriteLine();

            Console.WriteLine("Building started");
            Console.WriteLine("Setting up basement...");
            SetBasement();
            Console.WriteLine("Staging walls...");
            SetWalls();
            Console.WriteLine("Pulling the root...");
            SetRoot();
            Console.WriteLine("Adding windows...");
            SetWindows();
            Console.WriteLine("Building completed");
            Summary();

            Console.WriteLine();
        }
        public void Summary()
        {
            Console.WriteLine("Building type: {0}", Type);
            Console.WriteLine("This building has:");
            foreach (var i in Components)
                Console.WriteLine(i);
        }
    }
    //Concrete Product 1
    class LivingHouse : Building
    {
        public LivingHouse() { Type = typeof(LivingHouse).Name; }
        public override void SetBasement()
        {
            Components.Add("Protected cement basement with vault");
        }

        public override void SetRoot()
        {
            Components.Add("Slate covered root");
        }

        public override void SetWalls()
        {
            Components.Add("50cm walls");
        }

        public override void SetWindows()
        {
            Components.Add("Huge glass windows");
        }
    }
    // Concrete Product 2
    class Garage : Building
    {
        public Garage()
        {
            Type = typeof(Garage).Name;
        }
        public override void SetBasement()
        {
            Components.Add("Ground basement");
        }

        public override void SetRoot()
        {
            Components.Add("Flat rubberoid covered root");
        }

        public override void SetWalls()
        {
            Components.Add("10cm walls");
        }

        public override void SetWindows()
        {
            Components.Add("1 small window");
        }
    }
}
