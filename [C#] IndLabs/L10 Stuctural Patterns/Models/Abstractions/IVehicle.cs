namespace L10_Stuctural_Patterns.Models.Abstractions
{
    // Adapter Pattern

    interface IVehicle
    {
        void EngineStart();
        void EngineStop();
        void Drive(GearboxPosition position);
    }
}
