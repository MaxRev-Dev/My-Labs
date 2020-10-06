#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string>

using namespace std;

int main() {
	SetConsoleOutputCP(1251);
	double a,b;
	cout << "Введіть чисельник дробу: ";
	cin >> a;
	cout << "Введіть знаменник дробу: ";
	cin >> b;

	double d = a / b;

	string str(to_string(d));
	string last = str.substr(str.find_first_of('.')+1, str.length());
	for (int i = 1; i < last.length(); i++) {
		if (last.substr(0, i) == last.substr(i, i)) {
			last = last.substr(0, i);
		}
	}
	cout << "Результат: " << str<<endl;
	cout << "Період дробу  = "<<last;

	_getch();
	return 0;
}