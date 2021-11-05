namespace L10_Stuctural_Patterns.Models.Trains.Abstractions
{
    interface IDynamicBrake //Реостат (Rheostatic brake)
    {
        void DynamicBrakeRelease();
        void DynamicBrakeApply20();
        void DynamicBrakeApply50();
        void DynamicBrakeApplyFull();
    }

}
