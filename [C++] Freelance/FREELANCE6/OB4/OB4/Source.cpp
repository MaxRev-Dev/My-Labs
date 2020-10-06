#include <iostream>
#include <Windows.h>
#include <algorithm>
#include <string>
#include <conio.h>

using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string str;
	cout << "Введіть текст (АБ): ";
	getline(cin, str);

	size_t n1 = count(str.begin(), str.end(), 'А'); // просто функція пошуку з algorithm
	cout << "Входжень А в тексті - "<<n1;
	size_t n2 = count(str.begin(), str.end(), 'Б');
	cout << "\nВходжень Б в тексті - "<<n2<<endl;
	cout << (n1 > n2 ? "TRUE" : "FALSE") << endl;
	_getch();
	return 0;
}