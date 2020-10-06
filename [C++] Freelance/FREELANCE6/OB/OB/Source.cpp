#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string>

using namespace std;

int HexToInt(const char* str)
{
	int r;
	// С„СѓРЅРєС†С–СЏ РїРµСЂРµРІРµРґРµРЅСЏ hex - int
	// x - hex С„РѕСЂРјР°С‚
	sscanf_s(str, "%x", &r); 
	return r;
}
// РїРµСЂРµРІС–СЂРєР° РЅР° СЃРёРјРІРѕР»Рё hex С‡РёСЃР»Р°
bool ishex(string str) {
	string hex = "123456789abcdef";
	for (int i= 0; i < str.length(); i++) {
		//РїРѕС€СѓРє Сѓ СЃС‚СЂС–С‡С†С–
		if (hex.find(str[i]) == string::npos) 
			return false;
	} 
	return true;
}
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	while (true) {
		string str; cout << "Р’РІРµРґС–С‚СЊ С‡РёСЃР»Рѕ РІ HEX С„РѕСЂРјР°С‚С–: ";
		getline(cin, str); 
		int num = MININT; 
		
		if (ishex(str)) { 
			// С‡РёСЃР»Рѕ РІ РїРѕСЂСЏРґРєСѓ. РєРѕРЅРІРµСЂС‚СѓС”РјРѕ..
			num = HexToInt(str.c_str());			// РѕСЃС‚Р°С‡Р° РґС–Р»РµРЅРЅСЏ РЅР° 5 РјР°С” Р±СѓС‚Рё 0
			cout << "Р§РёСЃР»Рѕ (OCT) " << num << " " << ((num % 5 == 0) ? "С”" : "РЅРµ С”") << " РєСЂР°С‚РЅРёРј 5";
		}
		else {
			cout << "Р§РёСЃР»Рѕ РЅРµ С” С€С–СЃРЅР°РґС†СЏС‚РєРѕРІРёРј";
		} 
		cout << endl<<endl;
	}
}