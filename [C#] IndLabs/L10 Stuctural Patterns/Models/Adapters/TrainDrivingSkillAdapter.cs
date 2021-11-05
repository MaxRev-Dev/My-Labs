using System;
using System.Threading.Tasks;

namespace L10_Stuctural_Patterns.Models.Adapters
{
    using L10_Stuctural_Patterns.Models.Abstractions;
    using L10_Stuctural_Patterns.Models.Cars;
    using L10_Stuctural_Patterns.Models.Trains;
    // Adapter Pattern 

    class TrainDrivingSkillAdapter : CarVehicle, IVehicle
    {
        private TrainSD40 train;
        public TrainDrivingSkillAdapter(TrainSD40 obj)
        {
            train = obj;
            Console.WriteLine("Now I can drive a train!");
        }
        enum Command { MoveForward, FastForward, Stop, Reverse }
        private async Task IdleCommandTrack()
        {
            train.ThrottleMinimal();
            train.ThrottleSupport();
            train.ThrottleIdle();
            await Task.Delay(5000);
            train.ThrottleRelease();
            train.DynamicBrakeApply50();
            await Task.Delay(2000);
            train.DynamicBrakeRelease();
            train.BrakesFullService();
        }
        public new void Drive(GearboxPosition position)
        {
            train.EngineStart();
            train.BrakesRelease();
            IdleCommandTrack().Wait();
            train.EnginePowerOff();
        }

    }
}
