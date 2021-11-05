using System;
using System.Collections.Generic;
using System.Text;
using System.Text.RegularExpressions;

namespace L8_Regex
{
    class Program
    { 
        static void Main(string[] args)
        {
            Console.OutputEncoding = Encoding.UTF8;
            string input = @"
Прохоров В.І.	1999	БГ-31
Вітчук Н.В.		1999	ПМ-21
Берестень С.П.	1998	КНІТ-21
Димидюк В.В.	1998	КНІТ-21
Присяжнюк С.І.	1999	АТ-21
";
            string pattern = @"(.*(?<=\..\.))\s*(?=\d)(\d*)\s*(.*(?=\s))";
            var reg = new Regex(pattern,RegexOptions.Multiline | RegexOptions.ECMAScript);
            var matches = reg.Matches(input);

            List<Student> list = new List<Student>();
            foreach (Match i in matches) {
                list.Add(new Student() {
                    Name = i.Groups[1].Value,
                    BirthYear = int.Parse(i.Groups[2].Value),
                    Group = i.Groups[3].Value
                });
            }            
            foreach (var item in list) {
                Console.WriteLine(
             "Ім'я: {0}\nГрупа: {1}\nР.н.: {2}\n\n",
             item.Name,item.Group,item.BirthYear);

            }                
            Console.ReadKey();
        }
        class Student
        {
            public int BirthYear { get; set; }
            public string Name { get; set; }
            public string Group { get; set; }
        }
    }
}
