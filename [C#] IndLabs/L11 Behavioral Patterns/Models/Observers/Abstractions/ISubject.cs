namespace L11_Behavioral_Patterns.Models.Observers.Abstractions
{
    public interface IObservableSubject
    {
        void Attach(IObserver observer);
        void DetachAll();

        void Detach(IObserver observer);

        void Notify();
    }
}
