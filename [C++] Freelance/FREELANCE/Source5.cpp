#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string>
#include <sstream>

using namespace std;

int main() {
	SetConsoleOutputCP(1251);
	double a,b;
	cout << "¬вед≥ть чисельник дробу: ";
	cin >> a;
	cout << "¬вед≥ть знаменник дробу: ";
	cin >> b;

	double d = a / b;

	std::ostringstream sstream;
	sstream << d;
	string str = sstream.str();	// конвертуванн€ double to string (C++03)

	string last = str.substr(str.find_first_of('.')+1, str.length());
	for (int i = 1; i < last.length(); i++) {
		if (last.substr(0, i) == last.substr(i, i)) {
			last = last.substr(0, i);
		}
	}
	cout << "–езультат: " << str<<endl;
	cout << "ѕер≥од дробу  = "<<last;

	_getch();
	return 0;
}