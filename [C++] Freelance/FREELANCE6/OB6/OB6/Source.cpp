#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <string>

using namespace std;
char* ToUpper(char *ch, int len)
{
	for (int i = 0; i<len; i++) {
		*(ch + i) = *(ch + i) - 32;
	}
	return ch;
}
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string str,res;
	getline(cin, str);
	
	cout << ToUpper((char*)str.c_str(), strlen(str.c_str()));

	_getch();
	return 0;
}