#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
/*��������� ���������� ������ � �����*/
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
/*���� ���� ����������� ��'���� � ϲ�, ������� �� ������*/
class Person {
	string name, number,adr;
	static int currentSize; /*����� ������ �  ��'������*/
public:
	/*�����������*/
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
	/*������ ���������� ������� �������� ����*/
	string GetNumber() {
		return this->number;
	}
	string GetName() {
		return this->name;
	}
	string GetAdr() {
		return this->adr;
	}
	/*�������������� ��������� ��� ��������� ��'���� �� �������*/
	bool operator>(Person&b) {
		return (atoll(this->number.c_str())> atoll(b.number.c_str()));
	}
	bool operator==(Person&b) {
		return (atoll(this->number.c_str())> atoll(b.number.c_str()));
	}
	/*���������� ������ ������ � ��'������*/
	static int GetSize() {
		return currentSize;
	}
	/*���������� ��'����
	�� ��� ��� ����� ������ � ���������� �����
	������ ����� �������� �������	*/
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

int Person::currentSize = 0; //���������� �����
/*������� ����� �� ��������� ��'����*/
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
/*���� ���� �� ���� �� �� ���������� ���*/
void WriteTest()
{
	ofstream of("./test.txt", ios_base::out);
	for (int i = 0; i < 20; i++) {
		of << gen_random(true, 15)<<" " << gen_random(false,10)<<" "<<gen_random(true,20)<<"\n";
	}of << "\n";
	of.close();
}
/*���� ������ ��'����*/
void PrintAll(Person *a) {
	for (int i = 0; i < a->GetSize(); i++) {
		cout <<"["<<i+1<<"] "<< a[i].GetName() << " " << a[i].GetNumber() << " " << a[i].GetAdr() << endl;
	}cout << endl;
}

int main() {
	SetConsoleOutputCP(1251);

	WriteTest();
	Person *a = FileOpen();
	cout << "��'���� ��������: "<< a->GetSize() << endl;
	cout << "��'���� � �����: " << endl;
	PrintAll(a);
	Person::Sort(a);
	cout << "³����������: " << endl;
	PrintAll(a);

	_getch();
	return 0;
}