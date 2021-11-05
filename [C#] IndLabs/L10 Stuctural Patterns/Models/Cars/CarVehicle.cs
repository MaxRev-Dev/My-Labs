using System;
using System.Threading.Tasks;
using L10_Stuctural_Patterns.Models.Abstractions;

namespace L10_Stuctural_Patterns.Models.Cars
{
    // Adapter Pattern

    class CarVehicle : IVehicle
    {
        public void EngineStart() { Console.WriteLine("Car engine start"); }
        public void EngineStop() { Console.WriteLine("Car engine stop"); }
        public void Drive(GearboxPosition position)
        {
            Console.WriteLine("Car is moving..");
            Task.Delay(5000).Wait();
            Console.WriteLine("Car stoped");
        }
    }
}
