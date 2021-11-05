using System.Threading.Tasks;
namespace L10_Stuctural_Patterns.Models.Helpers
{
    class DelaySimulation
    {
        public static void WaitDefault()
        {
            Wait(2300);
        }

        public static void Wait(int msToWait)
        {
            Task.Delay(msToWait).Wait();
        }
    }

}
