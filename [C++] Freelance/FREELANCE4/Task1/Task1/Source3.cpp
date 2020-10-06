#include <iostream>
#include <Windows.h>
#include <vector>
#include <conio.h>
#include <fstream>
#include <iomanip>
#include "Item.h"

using namespace std;
//Р—Р°РґР°С‡Р° 3
vector<Item>* GetItems() {
	vector<Item> *v = new vector<Item>();
	while (true)
	{
		Item it;
		cout << "Р’РІРµРґС–С‚СЊ РєРѕРґ С„Р°РєСѓР»СЊС‚РµС‚Сѓ: ";
		cin >> it.fcode; cin.get();
		cout << "Р’РІРµРґС–С‚СЊ РєРѕРґ СЃРїРµС†С–Р°Р»СЊРЅРѕСЃС‚С–: ";
		cin >> it.scode; cin.get();
		cout << "Р’РІРµРґС–С‚СЊ РєСѓСЂСЃ: ";
		cin >> it.course;
		cout << "Р’РІРµРґС–С‚СЊ РіСЂСѓРїСѓ: ";
		cin >> it.group;
		cout << "Р’РІРµРґС–С‚СЊ РєРѕРґ РґРёСЃС†РёРїР»С–РЅРё: ";
		cin >> it.dpcode; cin.get();
		cout << "Р’РІРµРґС–С‚СЊ РїСЂС–Р·РІРёС‰Рµ СЃС‚СѓРґРµРЅС‚Р°: ";
		cin >> it.nick;
		cout << "Р’РІРµРґС–С‚СЊ РЅРѕРјРµСЂ Р·Р°Р»С–РєРѕРІРѕС— РєРЅРёР¶РєРё: ";
		cin >> it.gradebook_id; cin.get();
		cout << "Р’РІРµРґС–С‚СЊ РѕС†С–РЅРєСѓ: ";
		cin >> it.mark; cin.get();
		v->push_back(it);
		cout << endl << "Р”РѕРґР°С‚Рё С‰Рµ Р·Р°РїРёСЃ [1/0]: ";
		int fg;  cin >> fg;
		if (fg != 1) break;
	} return v;
}
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	//Р·Р°РґР°С‡Р° 3
	auto f3 = GetItems();
	PrintAll(*f3);
	WriteItems("./data.txt", *f3);
	
	_getch();
	return 0;
}