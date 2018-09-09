using System;
using System.Text;
using System.Text.RegularExpressions;
namespace Regex8
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.OutputEncoding = Encoding.UTF8;
            while (true)
            {
                Console.Write("Введіть текст: ");
                string str = Console.ReadLine();
                Regex r = new Regex(@"[\d]+");
                if (r.IsMatch(str))
                {
                    Console.WriteLine("Знайдено {0} входжень чисел", r.Matches(str).Count);
                    foreach (Match i in r.Matches(str))
                        Console.WriteLine(i.Groups[0].Value);
                }
                else Console.WriteLine("Текст не містить чисел");
            }
        }
    }
}
