
using System.Text;
using System.IO;
using System;
using L10_Stuctural_Patterns.Models.Cars;
using L10_Stuctural_Patterns.Models.Trains;
using L11_Behavioral_Patterns.Models.Observers.Abstractions;

namespace L11_Behavioral_Patterns.Models.Observers
{
    class FileLoggerObserver : IObserver, IDisposable
    {
        private readonly FileStream _fs;
        private readonly StreamWriter _writer;

        public FileLoggerObserver(string fileName)
        {
            _fs = File.Open(fileName, FileMode.Create, FileAccess.Write);
            _writer = new StreamWriter(_fs, Encoding.UTF8);
        }

        public void Dispose()
        {
            _writer.Dispose();
            _fs.Close();
            _fs.Dispose();
        }

        public void Update(IObservableSubject state)
        {
            if (state is CarVehicle car)
            {
                _writer.WriteLine(GetType().Name + ": Car status > " + car.Status);
            }

            if (state is TrainSD40 train)
            {
                _writer.WriteLine(GetType().Name + ": Train status > " + train.CurrentState);
            }
        }
    }
}
