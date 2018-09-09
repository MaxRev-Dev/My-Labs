using System;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;

namespace L8
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.InputEncoding = Encoding.Unicode;
            Console.OutputEncoding = Encoding.Unicode;
            string rawUkr = @"а, б, в, г, ґ, д, е, є, ж, з, и, і, ї, й, к, л, м, н, о, п, р, с, т, у, ф, х, ц, ч, ш, щ, ь, ю, я";
            var ci = new CultureInfo("uk-UA");
            rawUkr = string.Join("", rawUkr.Split(new char[] { ',', ' ' }).Select(x => x.ToUpper(ci) + x));

            string pattern = @"[^\s" + rawUkr + "]";
            while (true)
            {
                Console.WriteLine("Please input string: ");
                string inp = Console.ReadLine();
                Regex r = new Regex(pattern);
                if (r.IsMatch(inp))
                {
                    Console.WriteLine("This characters are not from ukrainian alphabet");
                    foreach (Match i in r.Matches(inp))
                    {
                        Console.Write(" {0}", i.Groups[0].Value);
                    }
                    Console.WriteLine();
                }
                else Console.WriteLine("This is ukrainian!! Українська!!");
            }
        }
    }
}
