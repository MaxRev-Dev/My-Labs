
using System;
using System.Collections.Generic;
using L11_Behavioral_Patterns.Models.Observers.Abstractions;

namespace L11_Behavioral_Patterns.Models.Observers
{
    public class ObservableSubject : IObservableSubject
    {
        public NotificationType State { get; set; } = NotificationType.NewEvent;

        private List<IObserver> _observers = new List<IObserver>();

        public void Attach(IObserver observer)
        {
            Console.WriteLine($"{GetType().Name}Subject: Attached an observer {observer.GetType().Name}.");
            _observers.Add(observer);
        }

        public void DetachAll()
        {
            foreach (var observer in _observers)
            {
                Console.WriteLine($"{GetType().Name}Subject: Detached {observer.GetType().Name}.");
            }
            _observers.Clear();
        }
        public void Detach(IObserver observer)
        {
            _observers.Remove(observer);
            Console.WriteLine($"{GetType().Name}Subject: Detached {observer.GetType().Name}.");
        }

        public void Notify()
        {
            foreach (var observer in _observers)
            {
                observer.Update(this);
            }
        }
    }
}
