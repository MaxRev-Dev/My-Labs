using L10_Stuctural_Patterns.Models.Abstractions;
using L10_Stuctural_Patterns.Models.Helpers;
using L11_Behavioral_Patterns.Models.Observers;
using L11_Behavioral_Patterns.Models.Observers.Abstractions;

namespace L10_Stuctural_Patterns.Models.Cars
{
    // Adapter Pattern

    class CarVehicle : ObservableSubject, IVehicle
    {
        public void EngineStart() { Notify("Car engine start"); }
        public void EngineStop() { Notify("Car engine stop"); }
        public void Drive(GearboxPosition position)
        {
            Notify("Car is moving..");
            DelaySimulation.WaitDefault();
            Notify("Car stoped");
        }

        private void Notify(string message)
        {
            Status = message;
            (this as IObservableSubject).Notify();
        }

        public string Status { get; private set; }
    }
}
