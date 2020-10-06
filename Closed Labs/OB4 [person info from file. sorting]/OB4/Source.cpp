#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
/*Генератор випадкових стрічок і чисел*/
char* gen_random(bool withAlfa,const int len) {
	char* alphanum = ((!withAlfa)?
		"0123456789": "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");
	char* s = new char[len];
	for (int i = 0; i < len; ++i) {
		s[i] = alphanum[rand() % (strlen(alphanum) - 1)]; 
	}
	s[len] = 0;
	return s;
}
/*Клас який представляє об'єкти з ПІБ, номером та адесою*/
class Person {
	string name, number,adr;
	static int currentSize; /*Розмір масиву з  об'єктами*/
public:
	/*Коструктори*/
	Person() {}
	Person(string name, string number,string adr) {
		this->name = name;
		this->number = number;
		this->adr = adr;
		currentSize++;
	}
	Person(string name, int number, string adr) {
		this->name = name;
		this->number = number;
		this->adr = adr;
		currentSize++;
	}
	/*Методи повернення значень закритих полів*/
	string GetNumber() {
		return this->number;
	}
	string GetName() {
		return this->name;
	}
	string GetAdr() {
		return this->adr;
	}
	/*Перевантаження операторів для порівняння об'єктів за номером*/
	bool operator>(Person&b) {
		return (atoll(this->number.c_str())> atoll(b.number.c_str()));
	}
	bool operator==(Person&b) {
		return (atoll(this->number.c_str())> atoll(b.number.c_str()));
	}
	/*Повернення розміру масиву з об'єктами*/
	static int GetSize() {
		return currentSize;
	}
	/*Сортування об'єктів
	По суті цей метод взятий з попередньої лабки
	Змінено тільки прототип функції	*/
	static void Sort(Person *a) {
		for (int i = 1; i <currentSize; i++)
		{
			for (int j = 0; j < currentSize - i; j++)
			{
				if (a[j]>a[j+1])
				{
					Person temp = a[j];
					a[j] = a[j + 1];
					a[j + 1] = temp;
				}
			}
		}
	}
};

int Person::currentSize = 0; //Початковий розмір
/*Читання файлу та створення об'єктів*/
Person * FileOpen() {
	ifstream inp("./test.txt");
	vector<string> str;
	string g = "";
	while (true) {
		getline(inp,g);
		if (g == "")break;
		str.push_back(g);
	}
	inp.close();
	Person*a = new Person[str.size()];
	for (size_t i = 0; i < str.size(); i++) {
		string cur = str[i];
		size_t p1 = cur.find_first_of(' ');
		string name =cur.substr(0,p1);
		size_t p2 = (cur.substr(p1+1)).find_first_of(' ');
		string num = cur.substr(p1 + 1, p2);
		string adr = cur.substr(cur.find_last_of(' ')+1);
		a[i] = Person(name,num,adr);
	}
	return a;
}
/*Якщо файл не існує то він сворюється тут*/
void WriteTest()
{
	ofstream of("./test.txt", ios_base::out);
	for (int i = 0; i < 20; i++) {
		of << gen_random(true, 15)<<" " << gen_random(false,10)<<" "<<gen_random(true,20)<<"\n";
	}of << "\n";
	of.close();
}
/*Вивід масиву об'єктів*/
void PrintAll(Person *a) {
	for (int i = 0; i < a->GetSize(); i++) {
		cout <<"["<<i+1<<"] "<< a[i].GetName() << " " << a[i].GetNumber() << " " << a[i].GetAdr() << endl;
	}cout << endl;
}

int main() {
	SetConsoleOutputCP(1251);

	WriteTest();
	Person *a = FileOpen();
	cout << "Об'єктів знайдено: "<< a->GetSize() << endl;
	cout << "Об'єкти з файлу: " << endl;
	PrintAll(a);
	Person::Sort(a);
	cout << "Відсортоване: " << endl;
	PrintAll(a);

	_getch();
	return 0;
}