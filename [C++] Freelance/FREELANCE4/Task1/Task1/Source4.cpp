#include <iostream>
#include <Windows.h>
#include <vector>
#include <conio.h>
#include <fstream>
#include <iomanip>
#include "Item.h"

using namespace std;

//Р—Р°РґР°С‡Р° 4
void CorrectPrint(const Item p) {
	cout <<
		"\n| [1]" << setw(5) << p.fcode << setw(5) << "| [2]" << setw(5) <<
		setw(5) << p.scode << setw(5) << "| [3]" << setw(5) <<
		setw(5) << p.course << setw(5) << "| [4]" << setw(5) <<
		setw(10) << p.group << setw(5) << "| [5]" << setw(5) <<
		setw(5) << p.dpcode << setw(5) << "| [6]" << setw(5) <<
		setw(10) << p.nick << setw(5) << "| [7]" << setw(5) <<
		setw(5) << p.gradebook_id << setw(5) << "| [8]" << setw(5) <<
		setw(5) << p.mark << "|" << endl;
}
void CorrectItems(vector<Item> *v) {
	while (true)
	{
		PrintAll(*v);
		cout << "Р’РІРµРґС–С‚СЊ РЅРѕРјРµСЂ Р·Р°РїРёСЃСѓ РґР»СЏ РєРѕСЂРёРіСѓРІР°РЅРЅСЏ (-1 РІС–РґРјС–РЅР°): ";
		int x, y;  cin >> x; cin.get();
		if (x == -1) break;
		Item tmp = v->at(x - 1);
		while (true)
		{
			cout << "Р’РІРµРґС–С‚СЊ РЅРѕРјРµСЂ РїРѕР»СЏ РґР»СЏ РєРѕСЂРёРіСѓРІР°РЅРЅСЏ (-1 РІС–РґРјС–РЅР°): ";
			CorrectPrint(tmp);
			cin >> y; cin.get();
			if (x == -1) break;
			cout << ">> Р РµРґР°РіСѓС”РјРѕ ";
			switch (y)
			{
			case 1: {
				cout << "РєРѕРґ С„Р°РєСѓР»СЊС‚РµС‚Сѓ: "; cin >> tmp.fcode; cin.get();
				break;
			}
			case 2: {
				cout << "РєРѕРґ СЃРїРµС†С–Р°Р»СЊРЅРѕСЃС‚С–: "; cin >> tmp.scode; cin.get();
				break;
			}
			case 3: {
				cout << "РєСѓСЂСЃ: "; cin >> tmp.course;
				break;
			}
			case 4: {
				cout << "РіСЂСѓРїСѓ: "; cin >> tmp.group;
				break;
			}
			case 5: {
				cout << "РєРѕРґ РґРёСЃС†РёРїР»С–РЅРё: "; cin >> tmp.dpcode; cin.get();
				break;
			}
			case 6: {
				cout << "РїСЂС–Р·РІРёС‰Рµ СЃС‚СѓРґРµРЅС‚Р°: "; cin >> tmp.nick;
				break;
			}
			case 7: {
				cout << "РЅРѕРјРµСЂ Р·Р°Р».РєРЅ.: "; cin >> tmp.gradebook_id; cin.get();
				break;
			}
			case 8: {
				cout << "РѕС†С–РЅРєСѓ: "; cin >> tmp.mark; cin.get();
				break;
			}
			default:
				break;
			}
			CorrectPrint(tmp);
			cout << endl << "РЎРєРѕСЂРµРіСѓРІР°С‚Рё С‰Рµ РїРѕР»Рµ [1/0]: ";
			int fg;  cin >> fg;	if (fg != 1) break;

		}

		v->at(x - 1) = tmp;
		cout << endl << "РЎРєРѕСЂРµРіСѓРІР°С‚Рё С‰Рµ Р·Р°РїРёСЃ [1/0]: ";
		int fg;  cin >> fg;	if (fg != 1) break;
	}
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//Р·Р°РґР°С‡Р° 4
	auto f4 = ReadFile("./data.txt");
	CorrectItems(f4);
	WriteItems("./data.txt", *f4);

	_getch();
	return 0;
}