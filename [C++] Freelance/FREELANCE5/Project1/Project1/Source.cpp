#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <fstream>
#include <Windows.h>
#include <conio.h>

using namespace std;

int size = 0;
struct Item {
	string
		name = "",
		bplace = "",
		startdate = "",
		gender = "",
		state = "",
		educ = "";
};

void Print(const Item* arr) {
	cout << endl << "|" << "РџР†Р‘" << "|" << "РњС–СЃС†Рµ РЅР°СЂРѕРґР¶."
		<< "|" << "РўСЂСѓРґРѕРІРёР№ СЃС‚Р°Р¶ Р·"
		<< "|" << "РЎС‚Р°С‚СЊ"
		<< "|" << "РЎС–РµР№РЅРёР№ СЃС‚Р°РЅ"
		<< "|" << "РћСЃРІС–С‚Р°" << endl;
	for (int i = 0; i < ::size; i++) {
		auto  item = arr[i];
		cout << " [" << i + 1 << "] " <<
			"|" << setw(5) << item.name << setw(5) << "|" << setw(5) <<
			setw(5) << item.bplace << setw(5) << "|" << setw(5) <<
			setw(5) << item.startdate << setw(5) << "|" << setw(5) <<
			setw(5) << item.gender << setw(5) << "|" << setw(5) <<
			setw(10) << item.state << setw(5) << "|" << setw(5) <<
			setw(5) << item.educ << setw(5) << "|" << endl;
	} cout << endl<<endl;
}

Item* GetFromFile(string file) {
	Item *arr = new Item[50];

	ifstream ins(file.c_str(), ios::in);
	if (ins.is_open()) {
		char*buff = new char[256];
		while (!ins.eof()) {
			ins.getline(buff, 256);
			if (buff[0] != '\0') {
				int iter = 0;
				Item item;
				while (buff[iter] != '|') { // name
					item.name += buff[iter++];
				}iter++;
				while (buff[iter] != '|') { //bplace
					item.bplace += buff[iter++];
				}iter++;

				while (buff[iter] != '|') { //startdate
					item.startdate += buff[iter++];
				}iter++;
				while (buff[iter] != '|') {//gender
					item.gender += buff[iter++];
				}iter++;
				while (buff[iter] != '|') {//state
					item.state += buff[iter++];
				}iter++;
				while (true) { // educ
					if (buff[iter] == '\0') break;
					item.educ += buff[iter++];
				}
				if (::size < 50)
					arr[::size++] = item;
				else {
					cout << "РљС–Р»СЊРєС–СЃС‚СЊ Р·Р°РїРёСЃС–РІ РѕР±РјРµР¶РµРЅРѕ РІ 50";
					break;
				}
			}
		} ins.close();
		return arr;
	}
	return nullptr;
}

void CheckBPlace(const Item* arr){
	cout << endl << "РџСЂС–Р·РІРёС‰Р° С‚РёС… С…С‚Рѕ РЅР°СЂРѕРґРёРІСЃСЏ РІ РљРёС”РІС–" << endl;
	for (int i = 0; i < ::size; i++) 
		if (arr[i].bplace == "РљРёС—РІ") 
			cout << arr[i].name << endl;
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	Item* items = GetFromFile("./database.txt");
	Print(items);	
	CheckBPlace(items);	
	_getch();
	return 0;
}