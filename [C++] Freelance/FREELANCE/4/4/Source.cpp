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
	cout << "Р вЂ™Р Р†Р ВµР Т‘РЎвЂ“РЎвЂљРЎРЉ 1 РЎР‚РЎРЏР Т‘Р С•Р С”: ";
	getline(cin, str1);
	cout << "Р вЂ™Р Р†Р ВµР Т‘РЎвЂ“РЎвЂљРЎРЉ 2 РЎР‚РЎРЏР Т‘Р С•Р С”: ";
	getline(cin, str2);

	cout << "Р СњР В°Р в„–Р Т‘Р С•Р Р†РЎв‚¬Р Вµ Р Р†РЎвЂ¦Р С•Р Т‘Р В¶Р ВµР Р…Р Р…РЎРЏ 1 РЎР‚РЎРЏР Т‘Р С”Р В° Р Р† 2: "<< compare(str1, str2);

	_getch();
	return 0;
}