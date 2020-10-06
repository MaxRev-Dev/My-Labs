#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string>

using namespace std;
int main() {
	SetConsoleOutputCP(1251);
	string str1, str2;
	cout << "Введіть 1 рядок: ";
	getline(cin, str1);
	cout << "Введіть 2 рядок: ";
	getline(cin, str2);


	_getch();
	return 0;
}


