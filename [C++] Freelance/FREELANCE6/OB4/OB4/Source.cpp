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
	cout << "������ ����� (��): ";
	getline(cin, str);

	size_t n1 = count(str.begin(), str.end(), '�'); // ������ ������� ������ � algorithm
	cout << "�������� � � ����� - "<<n1;
	size_t n2 = count(str.begin(), str.end(), '�');
	cout << "\n�������� � � ����� - "<<n2<<endl;
	cout << (n1 > n2 ? "TRUE" : "FALSE") << endl;
	_getch();
	return 0;
}