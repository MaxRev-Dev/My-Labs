using System;
using L10_Stuctural_Patterns.Models.Abstractions;
using L10_Stuctural_Patterns.Models.Adapters;
using L10_Stuctural_Patterns.Models.Cars;
using L10_Stuctural_Patterns.Models.Trains;

namespace L10_Stuctural_Patterns
{
    // Adapter Pattern

    class Program
    {
        static void Main(string[] args)
        {
            var train = new TrainSD40();
            var car = new CarVehicle();
            var trainAdapter = new TrainDrivingSkillAdapter(train);
            var worker = new Worker();

            worker.Drive(car, GearboxPosition.Forward);
            worker.Drive(trainAdapter, GearboxPosition.Forward);

            Console.ReadKey();
        }
    }
    class Worker
    {
        public void Drive(IVehicle car, GearboxPosition direction)
        {
            car.Drive(direction);
        }
    }
}