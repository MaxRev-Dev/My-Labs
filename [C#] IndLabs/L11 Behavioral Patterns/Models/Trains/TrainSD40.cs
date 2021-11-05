using System.Threading.Tasks;
using L10_Stuctural_Patterns.Models.Abstractions;
using L10_Stuctural_Patterns.Models.Helpers;
using L10_Stuctural_Patterns.Models.Trains.Abstractions;
using L11_Behavioral_Patterns.Models.Observers;
using L11_Behavioral_Patterns.Models.Observers.Abstractions;

namespace L10_Stuctural_Patterns.Models.Trains
{
    class TrainSD40 : ObservableSubject,
        IEngine, IReverser, IThrottle, IIndependentBrake, IGeneralBrake, IDynamicBrake,
        IObservableSubject
    {
        private static string _defaultState = "Off";
        public string CurrentState { get; private set; } = _defaultState;

        #region Service Basic
        public void SystemCheck() { Notify("Locomotive prestart system checking"); DelaySimulation.WaitDefault(); }
        public void PantographRise() { Notify("Locomotive pantograph rised"); DelaySimulation.WaitDefault(); }
        public void PantographDetach()
        {
            Notify("Locomotive panthograph detached");
            Notify(CurrentState = _defaultState);
            DelaySimulation.WaitDefault();
        }
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
        public void ThrottleFull() { Notify("Throttle Full"); DelaySimulation.WaitDefault(); }
        public void ThrottleRelease() { Notify("Throttle Release"); DelaySimulation.WaitDefault(); }
        public void ThrottleHQ() { Notify("Throttle HQ"); DelaySimulation.WaitDefault(); }
        public void ThrottleIdle() { Notify("Throttle Idle"); DelaySimulation.WaitDefault(); }
        public void ThrottleMinimal() { Notify("Throttle Minimal"); DelaySimulation.WaitDefault(); }
        public void ThrottleSupport() { Notify("Throttle Support"); DelaySimulation.WaitDefault(); }
        #endregion

        #region Reverser
        public void ReverserForward() { Notify("Reverser is set to forward"); DelaySimulation.Wait(70); }
        public void ReverserReverse() { Notify("Reverser is set to reverse"); DelaySimulation.Wait(60); }
        public void ReverserNeutral() { Notify("Reverser neutral"); DelaySimulation.Wait(70); }
        #endregion

        #region Brakes
        public void BrakesEmergency() { Notify("Brakes Emergrncy. Hold On!"); DelaySimulation.WaitDefault(); }
        public void BrakesFullService() { Notify("Brakes Full Service"); DelaySimulation.WaitDefault(); }
        public void BrakesRelease() { Notify("Brakes release"); DelaySimulation.WaitDefault(); }
        public void BrakesMinimum() { Notify("Brakes minimal"); DelaySimulation.WaitDefault(); }
        public void BrakesMedium() { Notify("Brakes medium"); DelaySimulation.WaitDefault(); }
        #endregion

        #region IndependentBrakes
        public void IBApply(int HForce) { Notify($"Independent brake apply at {HForce}"); DelaySimulation.Wait(50); }
        public void IBRelease() { Notify("Independent brake release"); DelaySimulation.WaitDefault(); }
        #endregion

        #region DynamicBrakes
        private void BrackingResistorsCoolerStart() { Notify("Braking resistors cooling is started"); }
        private void BrackingResistorsCoolerStop() { Notify("Braking resistors cooling is stoped"); }

        public void DynamicBrakeRelease()
        {
            Notify("Locomotive dynamic brake released");
            BrackingResistorsCoolerStop();
        }
        public void DynamicBrakeApply20()
        {
            Notify("Locomotive dynamic brake apply 20%");
            BrackingResistorsCoolerStart();
        }
        public void DynamicBrakeApply50()
        {
            Notify("Locomotive dynamic brake apply 50%");
            BrackingResistorsCoolerStart();
        }
        public void DynamicBrakeApplyFull()
        {
            Notify("Locomotive dynamic brake full apply");
            BrackingResistorsCoolerStart();
        }

        private void Notify(string message)
        {
            CurrentState = message;
            (this as IObservableSubject).Notify();
        } 
        

        #endregion
    }

}
