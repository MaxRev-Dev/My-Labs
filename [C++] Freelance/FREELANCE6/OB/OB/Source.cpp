#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string>

using namespace std;

int HexToInt(const char* str)
{
	int r;
	// функція переведеня hex - int
	// x - hex формат
	sscanf_s(str, "%x", &r); 
	return r;
}
// перевірка на символи hex числа
bool ishex(string str) {
	string hex = "123456789abcdef";
	for (int i= 0; i < str.length(); i++) {
		//пошук у стрічці
		if (hex.find(str[i]) == string::npos) 
			return false;
	} 
	return true;
}
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	while (true) {
		string str; cout << "Введіть число в HEX форматі: ";
		getline(cin, str); 
		int num = MININT; 
		
		if (ishex(str)) { 
			// число в порядку. конвертуємо..
			num = HexToInt(str.c_str());			// остача ділення на 5 має бути 0
			cout << "Число (OCT) " << num << " " << ((num % 5 == 0) ? "є" : "не є") << " кратним 5";
		}
		else {
			cout << "Число не є шіснадцятковим";
		} 
		cout << endl<<endl;
	}
}