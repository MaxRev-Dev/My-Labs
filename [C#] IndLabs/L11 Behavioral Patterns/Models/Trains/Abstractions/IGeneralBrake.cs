namespace L10_Stuctural_Patterns.Models.Trains.Abstractions
{
    interface IGeneralBrake //Full train linkage brake
    {
        void BrakesEmergency();
        void BrakesFullService();
        void BrakesRelease();
        void BrakesMinimum();
        void BrakesMedium();
    }

}
