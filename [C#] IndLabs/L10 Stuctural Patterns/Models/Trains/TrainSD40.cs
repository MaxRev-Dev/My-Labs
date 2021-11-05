using System;
using System.Threading.Tasks;
using L10_Stuctural_Patterns.Models.Abstractions;
using L10_Stuctural_Patterns.Models.Helpers;
using L10_Stuctural_Patterns.Models.Trains.Abstractions;

namespace L10_Stuctural_Patterns.Models.Trains
{
    class TrainSD40 : IEngine, IReverser, IThrottle, IIndependentBrake, IGeneralBrake, IDynamicBrake
    {
        #region Service Basic
        public void SystemCheck() { Console.WriteLine("Locomotive prestart system checking"); DelaySimulation.WaitDefault(); }
        public void PantographRise() { Console.WriteLine("Locomotive pantograph rised"); DelaySimulation.WaitDefault(); }
        public void PantographDetach() { Console.WriteLine("Locomotive panthograph detached"); DelaySimulation.WaitDefault(); }
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
        public void ThrottleFull() { Console.WriteLine("Throttle Full"); DelaySimulation.WaitDefault(); }
        public void ThrottleRelease() { Console.WriteLine("Throttle Release"); DelaySimulation.WaitDefault(); }
        public void ThrottleHQ() { Console.WriteLine("Throttle HQ"); DelaySimulation.WaitDefault(); }
        public void ThrottleIdle() { Console.WriteLine("Throttle Idle"); DelaySimulation.WaitDefault(); }
        public void ThrottleMinimal() { Console.WriteLine("Throttle Minimal"); DelaySimulation.WaitDefault(); }
        public void ThrottleSupport() { Console.WriteLine("Throttle Support"); DelaySimulation.WaitDefault(); }
        #endregion

        #region Reverser
        public void ReverserForward() { Console.WriteLine("Reverser is set to forward"); Task.Delay(700).Wait(); }
        public void ReverserReverse() { Console.WriteLine("Reverser is set to reverse"); Task.Delay(600).Wait(); }
        public void ReverserNeutral() { Console.WriteLine("Reverser neutral"); Task.Delay(700).Wait(); }
        #endregion

        #region Brakes
        public void BrakesEmergency() { Console.WriteLine("Brakes Emergrncy. Hold On!"); DelaySimulation.WaitDefault(); }
        public void BrakesFullService() { Console.WriteLine("Brakes Full Service"); DelaySimulation.WaitDefault(); }
        public void BrakesRelease() { Console.WriteLine("Brakes release"); DelaySimulation.WaitDefault(); }
        public void BrakesMinimum() { Console.WriteLine("Brakes minimal"); DelaySimulation.WaitDefault(); }
        public void BrakesMedium() { Console.WriteLine("Brakes medium"); DelaySimulation.WaitDefault(); }
        #endregion

        #region IndependentBrakes
        public void IBApply(int HForce) { Console.WriteLine("Independent brake apply at {0}", HForce); DelaySimulation.Wait(500); }
        public void IBRelease() { Console.WriteLine("Independent brake release"); DelaySimulation.WaitDefault(); }
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
