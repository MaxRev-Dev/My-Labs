#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <vector>
#include <fstream>
#include <string>
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
	float salary;
};

void WriteToFile(Item*all, int count) {
	ofstream out("data.dat", ios::trunc);
	for (int i = 0; i < count; i++) {
		out <<
			all[i].entertp_code << "|" <<
			all[i].shop_code << "|" <<
			all[i].empl_num << "|"<<
			all[i].empl_surn << "|" <<
			all[i].b_date << "|" <<
			all[i].nat_code << "|" <<
			all[i].maried << "|" <<
			all[i].all_exp << "|" <<
			all[i].unnint_exp << "|" <<
			all[i].prof_code << "|" <<
			all[i]._class << "|" <<
			all[i].salary<<endl;
	}
	out.close();
}

char* checkInp(int count, bool num) {
	
	string str;  // РѕС‡РёС‰РµРЅРЅСЏ Р±СѓС„РµСЂР° РІРІРѕРґСѓ Сѓ СЂР°Р·С– РїРѕРјРёР»РѕРє
	if (num) { // РґР»СЏ С‡РёСЃРµР»
		getline(cin, str); // РІРІС–Рґ Сѓ СЃС‚СЂРѕРєСѓ
		if (atoi(str.c_str()) == 0||str.length()>count) { // СЏРєС‰Рѕ С†Рµ РЅРµ С‡РёСЃР»Рѕ 
			cout << "\nРџРѕРјРёР»РєР°: РЅРµРїСЂР°РІРёР»СЊРЅРёР№ РІРІС–Рґ. РџРѕРІС‚РѕСЂС–С‚СЊ СЃРїСЂРѕР±Сѓ\n";
			
			return checkInp(count, num); 
			//СЂРµРєСѓСЂСЃРёРІРЅРѕ РґС–СЃС‚Р°С”РјРѕ РІС–РґРїРѕРІС–РґСЊ, РїРѕРєРё РЅРµ Р±СѓРґРµ РїСЂР°РІРёР»СЊРЅР°)
		}
	}
	else {
		char* ch = new char[50];
		cin.getline(ch,30); 
		return ch;
	}
	char*buff =  new char[100];
	memcpy(buff,str.c_str(),sizeof(str.c_str()));
	return buff;
}

int count; // РіР»РѕР±Р°Р»СЊРЅР° Р·РјС–РЅРЅР° СЂРѕР·РјС–СЂСѓ Р±Р°Р·Рё
Item* InputItems() {
	cout << "РљС–Р»СЊРєС–СЃС‚СЊ РїСЂР°С†С–РІРЅРёРєС–РІ РґР»СЏ Р·Р°РїРёСЃСѓ Сѓ С„Р°Р№Р»: ";
	cin >> ::count; cin.get();
	Item *all = new Item[::count]; // РЅРѕРІР° Р±Р°Р·Р°
	for (int i = 0; i < ::count; i++) {	
		cout << endl << "РџСЂР°С†С–РІРЅРёРє " << i + 1 << endl;
		cout << "Р’РІРµРґС–С‚СЊ РєРѕРґ РїС–РґРїpРёС”РјСЃС‚РІР° [5]: ";
		all[i].entertp_code = checkInp(5,true);
		cout << "Р’РІРµРґС–С‚СЊ РєРѕРґ С†РµС…Сѓ [2]: ";
		all[i].shop_code = checkInp(2, true);
		cout << "Р’РІРµРґС–С‚СЊ С‚Р°Р±РµР»СЊРЅРёР№ РЅРѕРјРµp РїpР°С†С–РІРЅРёРєР° [4]: ";
		all[i].empl_num = checkInp(4, true);
		cout << "Р’РІРµРґС–С‚СЊ РїpС–Р·РІРёС‰Рµ РїpР°С†С–РІРЅРёРєР° [30]: ";
		all[i].empl_surn = checkInp(30, false);// С‚СѓС‚ РјР°С” Р±СѓС‚Рё СЃР»РѕРІРѕ
		cout << "Р’РІРµРґС–С‚СЊ СЂС–Рє РЅР°pРѕРґР¶РµРЅРЅСЏ [4]:";
		all[i].b_date = checkInp(4, true);
		cout << "Р’РІРµРґС–С‚СЊ РєРѕРґ РЅР°С†С–РѕРЅР°Р»СЊРЅРѕСЃС‚С– [2]: ";
		all[i].nat_code = checkInp(2, true);

		cout << "Р’РІРµРґС–С‚СЊ СЃС–РјРµР№РЅРёР№ СЃС‚Р°РЅ [1] 1/0: ";		
		int ism;
		cin >> ism; cin.get();
		all[i].maried =new char[2];			
		all[i].maried[0] = (ism == 0) ? '0' : '1';
		all[i].maried[1] = '\0';

		cout << "Р’РІРµРґС–С‚СЊ СЃС‚Р°Р¶ pРѕР±РѕС‚Рё Р·Р°РіР°Р»СЊРЅРёР№ [2]: ";
		all[i].all_exp = checkInp(2, true);
		cout << "Р’РІРµРґС–С‚СЊ СЃС‚Р°Р¶ pРѕР±РѕС‚Рё РЅРµРїРµpРµpРІРЅРёР№ [2]: ";
		all[i].unnint_exp = checkInp(2, true);
		cout << "Р’РІРµРґС–С‚СЊ РєРѕРґ РїpРѕС„РµСЃС–С— [4]: ";
		all[i].prof_code = checkInp(4, true);

		cout << "Р’РІРµРґС–С‚СЊ СЂРѕР·pСЏРґ [1]: "; 
		cin >> ism; cin.get();
		char*buff = new char[5]; itoa(ism, buff, 10);
		all[i]._class = buff;

		cout << "Р’РІРµРґС–С‚СЊ РѕРєР»Р°Рґ [float]: ";
		cin >> all[i].salary; cin.get(); cout << endl;
	}
	return all;
}

int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	Item*all_items = InputItems();
	WriteToFile(all_items, ::count);
	cout << "\nР¤Р°Р№Р» Р·Р°РїРёСЃР°РЅРѕ С‚Р° Р·Р±РµСЂРµР¶РµРЅРѕ, СЏРє data.dat\n";
	_getch();
	return 0;
}
