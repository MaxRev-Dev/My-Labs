using System;
using L10_Stuctural_Patterns.Models.Abstractions;
using L10_Stuctural_Patterns.Models.Adapters;
using L10_Stuctural_Patterns.Models.Cars;
using L10_Stuctural_Patterns.Models.Trains;
using L11_Behavioral_Patterns.Models.Observers;
using L11_Behavioral_Patterns.Models.Observers.Abstractions;

namespace L11_Behavioral_Patterns
{
    class Program
    {
        static void Main(string[] args)
        {
            var train = new TrainSD40();
            var car = new CarVehicle();
            var trainAdapter = new TrainDrivingSkillAdapter(train);
            var worker = new Worker();

            var consoleObserver = new ConsoleLoggerObserver();
            using (var fileLoggerObserver = new FileLoggerObserver("./logger-output.log"))
            {
                if (car is IObservableSubject s1)
                {
                    s1.Attach(consoleObserver);
                    s1.Attach(fileLoggerObserver);
                }

                if (train is IObservableSubject s2)
                {
                    s2.Attach(consoleObserver);
                    s2.Attach(fileLoggerObserver);
                }

                worker.Drive(car, GearboxPosition.Forward);
                worker.Drive(trainAdapter, GearboxPosition.Forward);
 
            }
            
            car.DetachAll();
            train.DetachAll();

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
