namespace L10_Stuctural_Patterns.Models.Trains.Abstractions
{
    interface IIndependentBrake //Locomotive brake
    {
        void IBApply(int HForce);
        void IBRelease();
    }

}
