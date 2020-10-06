#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

int main() {
	SetConsoleOutputCP(1251);

	cout << "Р’РІРµРґРёС‚Рµ РїРѕСЃР»РµРґРѕРІР°С‚РµР»СЊРЅРѕСЃС‚СЊ С‡РёСЃРµР» С‡РµСЂРµР· РїСЂРѕР±РµР» Рё Р·Р°РєРѕРЅС‡РёС‚Рµ 0"<<endl;
	int n, even = 0, odd = 0;
	while (true) { //РїРѕРєР° РјС‹ РЅРµ РїСЂРµСЂРІРµРј С†РёРєР»
		cin >> n;
		if (n == 0)break; //РєРѕРЅРµС† РїРѕСЃР»РµРґРѕРІР°С‚РµР»СЊРЅРѕСЃС‚Рё
		if (n % 2 == 1) odd++; // РѕСЃС‚Р°С‡Р° РѕС‚ РґРµР»РµРЅРёСЏ = 1, С‡РёСЃР»Рѕ РЅРµС‡С‘С‚РЅРѕРµ
		else even++; //
	}
	cout << "Р§С‘С‚РЅС‹С…: " << even << "\n" << "РќРµС‡С‘С‚РЅС‹С…: " << odd;

	_getch();
	return 0;
}