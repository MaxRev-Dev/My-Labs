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
	cout << "Р’РІРµРґС–С‚СЊ С‚РµРєСЃС‚ (РђР‘): ";
	getline(cin, str);

	size_t n1 = count(str.begin(), str.end(), 'Рђ'); // РїСЂРѕСЃС‚Рѕ С„СѓРЅРєС†С–СЏ РїРѕС€СѓРєСѓ Р· algorithm
	cout << "Р’С…РѕРґР¶РµРЅСЊ Рђ РІ С‚РµРєСЃС‚С– - "<<n1;
	size_t n2 = count(str.begin(), str.end(), 'Р‘');
	cout << "\nР’С…РѕРґР¶РµРЅСЊ Р‘ РІ С‚РµРєСЃС‚С– - "<<n2<<endl;
	cout << (n1 > n2 ? "TRUE" : "FALSE") << endl;
	_getch();
	return 0;
}