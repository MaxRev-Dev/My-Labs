namespace L10_Stuctural_Patterns.Models.Trains.Abstractions
{
    interface IThrottle
    {
        void ThrottleHQ();
        void ThrottleMinimal();
        void ThrottleSupport();
        void ThrottleFull();
        void ThrottleRelease();
    }

}
