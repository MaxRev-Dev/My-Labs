#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <iomanip>
#include <vector>
#include <fstream>
#include <stdio.h>
using namespace std;

struct Item {
	char *entertp_code,
		*shop_code,
		*empl_num,
		*b_date,
		*nat_code,
		*empl_surn,
		*maried,
		*all_exp,
		*unnint_exp,
		*prof_code,
		*_class;
	double salary;
};
size_t count=0;
Item*ReadFile() {
	ifstream ifs("data.dat", ios::in);
	char*buff = new char[100];
	if (!ifs.is_open()){
	cout<<"Р¤Р°Р№Р» РЅРµ Р·РЅР°Р№РґРµРЅРѕ. Р¦Рµ РјР°С” Р±СѓС‚Рё data.dat";_getch();
	exit(1);
	}
	vector<Item> all;
	while (!ifs.eof())
	{
		Item a;
		ifs.getline(buff, 500);
		if (buff[0] != '\0') {
			int j = 0, i = 0;
			a.entertp_code = new char[5];
			while (buff[i] != '|') a.entertp_code[j++] = buff[i++]; a.entertp_code[j] = '\0';
			i++;

			j = 0;
			a.shop_code = new char[2];
			while (buff[i] != '|') a.shop_code[j++] = buff[i++]; a.shop_code[j] = '\0';
			i++;

			j = 0;
			a.empl_num = new char[4];
			while (buff[i] != '|') a.empl_num[j++] = buff[i++]; a.empl_num[j] = '\0';
			i++;

			j = 0;
			a.empl_surn = new char[30];
			while (buff[i] != '|') a.empl_surn[j++] = buff[i++]; a.empl_surn[j] = '\0';
			i++;

			j = 0;
			a.b_date = new char[4];
			while (buff[i] != '|') a.b_date[j++] = buff[i++]; a.b_date[j] = '\0';
			i++;

			j = 0;
			a.nat_code = new char[2];
			while (buff[i] != '|') a.nat_code[j++] = buff[i++]; a.nat_code[j] = '\0';
			i++;

			j = 0;
			a.maried = new char[1];
			while (buff[i] != '|') a.maried[j++] = buff[i++]; a.maried[j] = '\0';
			i++;

			j = 0;
			a.all_exp = new char[2];
			while (buff[i] != '|') a.all_exp[j++] = buff[i++]; a.all_exp[j] = '\0';
			i++;

			j = 0;
			a.unnint_exp = new char[2];
			while (buff[i] != '|') a.unnint_exp[j++] = buff[i++]; a.unnint_exp[j] = '\0';
			i++;

			j = 0;
			a.prof_code = new char[4];
			while (buff[i] != '|') a.prof_code[j++] = buff[i++]; a.prof_code[j] = '\0';
			i++;

			j = 0;
			a._class = new char[1];
			while (buff[i] != '|') a._class[j++] = buff[i++]; a._class[j] = '\0';
			i++;

			j = 0;
			char*tmp = new char[10];
			while (true) {
				tmp[j++] = buff[i++];
				if (buff[i] == '\0')break;
			}tmp[j] = '\0';
			a.salary = atof(tmp);

			all.push_back(a);
		}
	}
	ifs.close();
	::count = all.size();
	cout << "РЈ С„Р°Р№Р»С– " << ::count << " Р·Р°РїРёСЃС–РІ\n";
	Item* allret = new Item[all.size()];
	for (int i = 0; i < all.size(); i++) {
		allret[i] = all.at(i);
	} return allret;
}
void printall(Item*all) {
	for (int i = 0; i < ::count; i++) {
		cout << endl <<
			"\nРљРѕРґ РїС–РґРїpРёС”РјСЃС‚РІР°: " << all[i].entertp_code <<
			"\nРљРѕРґ С†РµС…Сѓ: " << all[i].shop_code <<
			"\nРўР°Р±РµР»СЊРЅРёР№ РЅРѕРјРµp РїpР°С†С–РІРЅРёРєР°: " << all[i].empl_num <<
			"\nРџpС–Р·РІРёС‰Рµ РїpР°С†С–РІРЅРёРєР°: " << all[i].empl_surn <<
			"\nР С–Рє РЅР°pРѕРґР¶РµРЅРЅСЏ: " << all[i].b_date <<
			"\nРљРѕРґ РЅР°С†С–РѕРЅР°Р»СЊРЅРѕСЃС‚С–: " << all[i].nat_code <<
			"\nРЎС–РјРµР№РЅРёР№ СЃС‚Р°РЅ: " << all[i].maried <<
			"\nРЎС‚Р°Р¶ pРѕР±РѕС‚Рё Р·Р°РіР°Р»СЊРЅРёР№: " << all[i].all_exp <<
			"\nРЎС‚Р°Р¶ pРѕР±РѕС‚Рё РЅРµРїРµpРµpРІРЅРёР№ : " << all[i].unnint_exp <<
			"\nРљРѕРґ РїpРѕС„РµСЃС–С—: " << all[i].prof_code <<
			"\nР РѕР·pСЏРґ: " << all[i]._class <<
			"\nРћРєР»Р°Рґ : " << all[i].salary << endl;
	}
}
void tableHeader() {
	cout << endl << setw(18) << "|" << setw(28) << "| Р—Р°РіР°Р»СЊРЅРёР№ СЃС‚Р°Р¶ |" << " РџСЂР°С†С–РІРЅРёРєС–РІ Р·Р° СЂРѕР·СЂСЏРґР°РјРё |" << endl;
	cout << "РљРѕРґ РїС–РґРїСЂРёС”РјСЃС‚РІР° |"<<" РљРѕРґ С†РµС…Сѓ |  СЂРѕР±РѕС‚Рё, СЂРѕРєС–РІ |"<<"  1 | 2 | 3 | 4 | 5 | 6   |"<<endl;
}
void printClass(Item a,int*_class) {
	cout << setw(10) << a.entertp_code
		<< setw(9) << " | " << setw(5) << a.shop_code
		<< setw(6) << " | " << setw(7) << a.all_exp
		<< setw(11) << " |  "
		<< _class[0] << " | " << _class[1] << " | "
		<< _class[2] << " | " << _class[3] << " | "
		<< _class[4] << " | " << _class[5] << "   |" << endl;
	
}

bool contains(vector<Item> all, Item x) {
	for (int i = 0; i < all.size(); i++) {
		if (atoi(all[i].entertp_code) == atoi(x.entertp_code) &&
			atoi(all[i].shop_code) == atoi(x.shop_code) &&
			atoi(all[i].all_exp) == atoi(x.all_exp))
			return true;
	}
	return false;
}

void uniteEnterp(vector<Item> all) {
	vector< vector< Item > > CLASSES;
	for (int i = all.size(); i >0; i--) {
		bool found = false;
		if (CLASSES.size() > 0) {
			for (int g = 0; g < CLASSES.size(); g++) {
				if (contains(CLASSES[g], all[all.size() - 1])) {
					CLASSES[g].push_back(all[all.size() - 1]); all.pop_back(); 
					found = true;
				}
			}

		}
		if (!found) {
			vector<Item> enterp;
			enterp.push_back(all[all.size() - 1]);
			all.pop_back();
			CLASSES.push_back(enterp);
		}
	}


	if (CLASSES.size() == 0) {
		cout << endl << "РќРµРјР°С” РїС–РґРїСЂРёС”РјСЃС‚РІ Р· С‚Р°РєРёРјРё РїСЂР°С†С–РІРЅРёРєР°РјРё" << endl << endl;
	}
	else {
		tableHeader();
	}
	for (int i = 0; i < CLASSES.size(); i++) {
		int *_class = new int[6];
		for (int f = 0; f < 6; f++) _class[f] = 0;
		for (int j = 0; j < CLASSES[i].size(); j++)
		{
			_class[atoi(CLASSES[i][j]._class) - 1] += 1;

		}
		printClass(CLASSES[i][0], _class);
	}
}

int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	Item*all_items = ReadFile();
	cout << "Р¤Р°Р№Р» СѓСЃРїС–С€РЅРѕ РїСЂРѕС‡РёС‚Р°РЅРѕ!" << endl;
	cout << "Р’РёРІРµСЃС‚Рё РІСЃС– Р·Р°РїРёСЃРё? 1/0 :";
	int x; cin >> x; cin.get();
	if (x ==1) printall(all_items);
	cout << endl;

	cout << "\n\n\nР”Рѕ 20 СЂРѕРєС–РІ :";
	vector <Item> sorted;

	for (int i = 0; i < ::count; i++)
	{
		if ((2017 - atoi(all_items[i].b_date)) < 20) {
			sorted.push_back(all_items[i]);
		}
	}
	uniteEnterp(sorted);
	sorted.clear();
	cout << "\n\n\nР’С–Рґ 20 РґРѕ 30 СЂРѕРєС–РІ :";
	
	for (int i = 0; i < ::count; i++)
	{
		int ys = 2017 - atoi(all_items[i].b_date);
		if (ys >= 20 && ys <= 30) {
			sorted.push_back(all_items[i]);
		}
	}
	uniteEnterp(sorted);
	sorted.clear();
	cout << "\n\n\nР‘С–Р»СЊС€Рµ 30 СЂРѕРєС–РІ :" ;

	for (int i = 0; i < ::count; i++)
	{
		if ((2017 - atoi(all_items[i].b_date)) > 30) {
			sorted.push_back(all_items[i]);
		}
	}
	uniteEnterp(sorted);
	sorted.clear();
	_getch();
	return 0;
}
