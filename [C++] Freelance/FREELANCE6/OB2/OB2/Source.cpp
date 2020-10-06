#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;
 
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int x;
	cout << "Р’РІРµРґС–С‚СЊ РєС–Р»СЊРєС–СЃС‚СЊ РІС–РґСЂС–Р·РєС–РІ: ";
	cin >> x;
	int **a = new int*[x]; //РІРёРґС–Р»СЏС”РјРѕ РїР°Рј'СЏС‚СЊ РїС–Рґ РІС–РґСЂС–Р·РєРё
	for (int i = 0; i < x; i++) {
		a[i] = new int[2];
		cout << "Р’С–РґСЂС–Р·РѕРє [1] => С‚РѕС‡РєР° " << i + 1 << ": ";
		cin >> a[i][0];
		cout << "Р’С–РґСЂС–Р·РѕРє [2] => С‚РѕС‡РєР° " << i + 1 << ": ";
		cin >> a[i][1];
	}
	
	/* 
	       2|-----|4 MinT
		1|--------------|5
		 MaxB 3|----------|6
		       |--| result 
	*/


	int  minT = MAXINT, maxB = MININT; // Р±РµСЂРµРјРѕ РїСЂРѕС‚РёР»РµР¶РЅРµ РїРѕС‡Р°С‚РєРѕРІРµ Р·РЅР°С‡РµРЅРЅСЏ
	for (int i = 0; i < x; i++) { 
		if (a[i][0] > maxB) maxB = a[i][0]; //max of bottom
		if (a[i][1] < minT) minT = a[i][1]; //min of top
	}
	if (maxB < minT) {
		cout << "Р’С–РґСЂС–Р·РєРё РїРµСЂРµС‚РёРЅР°СЋС‚СЊСЃСЏ: Рђ(" << maxB << ") B(" << minT << ")";
	} else cout << "Р’С–РґСЂС–Р·РєРё РќР• РїРµСЂРµС‚РёРЅР°СЋС‚СЊСЃСЏ";

	_getch();
	return 0;
}