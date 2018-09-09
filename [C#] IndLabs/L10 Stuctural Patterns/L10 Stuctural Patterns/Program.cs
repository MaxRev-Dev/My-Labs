using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace L10_Stuctural_Patterns
{
    // Adapter Pattern

    using TrainCollection;
    class Program
    {
        static   void Main(string[] args)
        {
            var train = new TrainSD40();
            var car = new CarVehicle();
            var adapt = new TrainDrivingSkillAdapter(train);
            var worker = new Worker();
             worker.Drive(car, GearboxPosition.Forward);

             worker.Drive(adapt,GearboxPosition.Forward);
            Console.ReadKey();
        }
    }
    class Worker
    {
        public void Drive(IVehicle car,GearboxPosition direction)
        {
             car.Drive(direction);
        }
    }
    public enum GearboxPosition { Forward, Reverse, Neutral }
    interface IVehicle
    {
        void EngineStart();
        void EngineStop();
        void Drive(GearboxPosition position);
    }
    class CarVehicle : IVehicle
    {
        public void EngineStart() { Console.WriteLine("Car engine start"); }
        public void EngineStop() { Console.WriteLine("Car engine stop"); }
        public void Drive(GearboxPosition position)
        {
            Console.WriteLine("Car is moving..");
              Task.Delay(5000).Wait();
            Console.WriteLine("Car stoped");
        }
    }

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
        public new   void Drive(GearboxPosition position)
        { 
            train.EngineStart();
            train.BrakesRelease();
              IdleCommandTrack().Wait();
            train.EnginePowerOff();
        }

    }
}
namespace TrainCollection
{
    interface IThrottle
    {
        void ThrottleHQ();
        void ThrottleMinimal();
        void ThrottleSupport();
        void ThrottleFull();
        void ThrottleRelease();
    }
    interface IReverser
    {
        void ReverserForward();
        void ReverserReverse();
        void ReverserNeutral();
    }
    interface IIndependentBrake //Locomotive brake
    {
        void IBApply(int HForce);
        void IBRelease();
    }
    interface IGeneralBrake //Full train linkage brake
    {
        void BrakesEmergency();
        void BrakesFullService();
        void BrakesRelease();
        void BrakesMinimum();
        void BrakesMedium();
    }
    interface IDynamicBrake //Реостат (Rheostatic brake)
    {
        void DynamicBrakeRelease();
        void DynamicBrakeApply20();
        void DynamicBrakeApply50();
        void DynamicBrakeApplyFull();
    }
    interface IEngine
    {
        void EngineStart();
        void EnginePowerOff();
    }

    class TrainSD40 : IEngine, IReverser, IThrottle, IIndependentBrake, IGeneralBrake, IDynamicBrake
    {
        #region Service Basic
        public void SystemCheck() { Console.WriteLine("Locomotive prestart system checking"); Task.Delay(2300).Wait(); }
        public void PantographRise() { Console.WriteLine("Locomotive pantograph rised"); Task.Delay(2300).Wait(); }
        public void PantographDetach() { Console.WriteLine("Locomotive panthograph detached"); Task.Delay(2300).Wait(); }
        #endregion

        #region Service Logic
        public void EngineStart()
        {
            SystemCheck();
            PantographRise();
        }
        public void EnginePowerOff()
        {
            PantographDetach();
        }
        #endregion

        #region Throttle
        public void ThrottleFull() { Console.WriteLine("Throttle Full"); Task.Delay(2300).Wait(); }
        public void ThrottleRelease() { Console.WriteLine("Throttle Release"); Task.Delay(2300).Wait(); }
        public void ThrottleHQ() { Console.WriteLine("Throttle HQ"); Task.Delay(2300).Wait(); }
        public void ThrottleIdle() { Console.WriteLine("Throttle Idle"); Task.Delay(2300).Wait(); }
        public void ThrottleMinimal() { Console.WriteLine("Throttle Minimal"); Task.Delay(2300).Wait(); }
        public void ThrottleSupport() { Console.WriteLine("Throttle Support"); Task.Delay(2300).Wait(); }
        #endregion

        #region Reverser
        public void ReverserForward() { Console.WriteLine("Reverser is set to forward"); Task.Delay(700).Wait(); }
        public void ReverserReverse() { Console.WriteLine("Reverser is set to reverse"); Task.Delay(600).Wait(); }
        public void ReverserNeutral() { Console.WriteLine("Reverser neutral"); Task.Delay(700).Wait(); }
        #endregion

        #region Brakes
        public void BrakesEmergency() { Console.WriteLine("Brakes Emergrncy. Hold On!"); Task.Delay(2300).Wait(); }
        public void BrakesFullService() { Console.WriteLine("Brakes Full Service"); Task.Delay(2300).Wait(); }
        public void BrakesRelease() { Console.WriteLine("Brakes release"); Task.Delay(2300).Wait();  }
        public void BrakesMinimum() { Console.WriteLine("Brakes minimal"); Task.Delay(2300).Wait(); }
        public void BrakesMedium() { Console.WriteLine("Brakes medium"); Task.Delay(2300).Wait(); }
        #endregion

        #region IndependentBrakes
        public void IBApply(int HForce) { Console.WriteLine("Independent brake apply at {0}",HForce); Task.Delay(800).Wait(); }
        public void IBRelease() { Console.WriteLine("Independent brake release"); Task.Delay(2300).Wait(); }
        #endregion

        #region DynamicBrakes
        private void BrackingResistorsCoolerStart() { Console.WriteLine("Braking resistors cooling is started"); }
        private void BrackingResistorsCoolerStop() { Console.WriteLine("Braking resistors cooling is stoped"); }

        public void DynamicBrakeRelease()
        {
            Console.WriteLine("Locomotive dynamic brake released");
            BrackingResistorsCoolerStop();
        }
        public void DynamicBrakeApply20()
        {
            Console.WriteLine("Locomotive dynamic brake apply 20%");
            BrackingResistorsCoolerStart();
        }
        public void DynamicBrakeApply50()
        {
            Console.WriteLine("Locomotive dynamic brake apply 50%");
            BrackingResistorsCoolerStart();
        }
        public void DynamicBrakeApplyFull()
        {
            Console.WriteLine("Locomotive dynamic brake full apply");
            BrackingResistorsCoolerStart();
        }
        #endregion
    }

}
