using System;
using L10_Stuctural_Patterns.Models.Cars;
using L10_Stuctural_Patterns.Models.Trains;
using L11_Behavioral_Patterns.Models.Observers.Abstractions;

namespace L11_Behavioral_Patterns.Models.Observers
{
    class ConsoleLoggerObserver : IObserver
    { 
        public void Update(IObservableSubject state)
        { 
            if (state is CarVehicle car)
            {
                Console.WriteLine(GetType().Name + ": Car status > " + car.Status);
            }

            if (state is TrainSD40 train)
            {
                Console.WriteLine(GetType().Name + ": Train status > " + train.CurrentState);
            } 
        }
    }
}
