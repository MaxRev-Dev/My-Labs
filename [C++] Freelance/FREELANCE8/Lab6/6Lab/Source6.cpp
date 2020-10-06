#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <iomanip>

using namespace std;

int main() {
	SetConsoleOutputCP(1251);//РґР»СЏ РІС‹РІРѕРґР° РєРёСЂРёР»Р»РёС†С‹
	int N;
	cout << "Р’РІРµРґРёС‚Рµ СЂР°Р·РЅРёС†Сѓ РІ Р·РЅР°С‡РµРЅРёСЏС…:";
	cin >> N;

	cout << setw(2) << "РњРµС‚СЂС‹" << setw(2) << "|" << setw(12) << "РљРёР»РѕРјРµС‚СЂС‹" << endl;
	for (int i = 100; i <= 1000; i += N) {
		// СѓСЃС‚Р°РЅР°РІР»РёРІР°РµРј "СЃРµС‚РєСѓ" С‚Р°Р±Р»РёС†С‹		//С„РёРєСЃРёСЂРѕРІР°РЅС‹Р№ РІС‹РІРѕРґ 3 Р·РЅР°РєРѕРІ РїРѕСЃР»Рµ РїР»Р°РІР°СЋС‰РµР№ С‚РѕС‡РєРё .С…С…С…
		cout << setw(5) << i << setw(2) << "|" << setw(10) << setprecision(3) << fixed << i / 1000.0 << endl;
	}
	_getch(); //РїР°СѓР·Р° РІ РєРѕРЅСЃРѕР»Рё
	return 0;
}