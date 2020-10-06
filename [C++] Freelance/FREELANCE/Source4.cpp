#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string>

using namespace std;

string compare(string str, string str2) {
	string *sizes = new string[str.length()];
	int iter = 0;
	for (int i = 0; i < str.length();i++) {
		for (int j = i; j < str.length(); j++) {
			if (str2.find(str.substr(i, j)) != string::npos) {
				sizes[iter++] = str.substr(i, j);
			}
		}
	}
	int max=0,index;
	for (int i = 0; i < iter; i++) {
		if (sizes[i].length() > max) { max = sizes[i].length(); index = i; }
	}
	return sizes[index];

}

int main() {
	SetConsoleOutputCP(1251);
	string str1, str2;
	cout << "Введіть 1 рядок: ";
	getline(cin, str1);
	cout << "Введіть 2 рядок: ";
	getline(cin, str2);

	cout << "Найдовше входження 1 рядка в 2: "<< compare(str1, str2);

	_getch();
	return 0;
}