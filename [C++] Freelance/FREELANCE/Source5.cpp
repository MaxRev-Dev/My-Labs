#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string>
#include <sstream>

using namespace std;

int main() {
	SetConsoleOutputCP(1251);
	double a,b;
	cout << "������ ��������� �����: ";
	cin >> a;
	cout << "������ ��������� �����: ";
	cin >> b;

	double d = a / b;

	std::ostringstream sstream;
	sstream << d;
	string str = sstream.str();	// ������������� double to string (C++03)

	string last = str.substr(str.find_first_of('.')+1, str.length());
	for (int i = 1; i < last.length(); i++) {
		if (last.substr(0, i) == last.substr(i, i)) {
			last = last.substr(0, i);
		}
	}
	cout << "���������: " << str<<endl;
	cout << "����� �����  = "<<last;

	_getch();
	return 0;
}