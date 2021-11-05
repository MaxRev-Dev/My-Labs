
namespace L11_Behavioral_Patterns.Models.Observers.Abstractions
{
    public interface IObserver
    {
        void Update(IObservableSubject subject);
    }
}
