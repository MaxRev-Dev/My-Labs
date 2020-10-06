#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
	SetConsoleOutputCP(1251);

	ifstream ifs("./test.cpp", ios::in);//Р’С–РґРєСЂРёРІР°С”РјРѕ С„Р°Р№Р» РЅР° С‡РёС‚Р°РЅРЅСЏ
	vector<string> data; //Р’РёРєРѕСЂРёСЃС‚РѕРІСѓС”РјРѕ РІРµРєС‚РѕСЂ. 
	//Р¦Рµ РЅС–Р±Рё С‚РѕР№ Р¶Рµ РјР°СЃРёРІ string[] РїСЂРѕС‚Рµ РєРѕРЅС‚РµР№РЅРµСЂ С– РІС–РЅ РјР°С” СЂРѕР·РјС–СЂ С‚Р° СЃРІРѕС— РјРµС‚РѕРґРё
	string pure = "";
	while (!ifs.eof()) { // РїРѕРєРё РЅРµ РєС–РЅРµС†СЊ С„Р°Р№Р»Сѓ
		string str;
		getline(ifs, str); // С‡РёС‚Р°С”РјРѕ СЂСЏРґРѕРє
		if (str.find("/*") != string::npos) {//С€СѓРєР°С”РјРѕ Сѓ РЅСЊРѕРјСѓ РїРѕС‡Р°С‚РѕРє РєРѕРјРµРЅС‚Р°СЂСЏ
			string comment = "";
			comment += str += "\n";

			while (!ifs.eof()) {	// Р§РёС‚Р°С”РјРѕ РєРѕРјРµРЅС‚Р°СЂ
				getline(ifs, str);
				if (str.find("*/") != string::npos) { //СЏРєС‰Рѕ Р·РЅР°Р№РґРµРЅРѕ РєС–РЅРµС†СЊ РєРѕРјРµРЅС‚Сѓ
					comment += str += "\n";
					data.push_back(comment);	//РљС–РЅРµС†СЊ РєРѕРјРµРЅС‚Р°СЂСЏ.
					// Р”РѕРґР°С”РјРѕ Р·Р°Р»РёС€РѕРє Сѓ РјР°СЃРёРІ(РІРµРєС‚РѕСЂ) 
					break; //РїРѕРІРµСЂС‚Р°С”РјРѕСЃСЊ РґРѕ Р·РІРёС‡Р°Р№РЅРѕРіРѕ С‡РёС‚Р°РЅРЅСЏ С„Р°Р№Р»Сѓ
				}
				comment += str += "\n";
				// Р”РѕРґР°С”РјРѕ Р№РѕРіРѕ Сѓ РјР°СЃРёРІ(РІРµРєС‚РѕСЂ) 
			}

		}
		else {
			pure += str += "\n";
		}
	}
	ifs.close();//Р·Р°РєСЂРёРІР°С”РјРѕ С„Р°Р№Р»

	ofstream ofs("./test.cpp", ios::trunc);
	ofs << pure;// Р·Р°РїРёСЃСѓС”РјРѕ С‡РёСЃС‚РёР№ РєРѕРґ Р±РµР· РєРѕРјРµРЅС‚Р°СЂС–РІ
	ofs.close();

	cout << "Р¤Р°Р№Р» РїСЂРѕС‡РёС‚Р°РЅРѕ С– РїРµСЂРµР·Р°РїРёСЃР°РЅРѕ. Р’РёРІРѕРґРёРјРѕ РєРѕРјРµРЅС‚Р°СЂС–..";
	if (data.capacity() == 0)cout << "\nРљРѕРјРµРЅС‚Р°СЂС–РІ РЅРµ Р·РЅР°Р№РґРµРЅРѕ\n";
	else {
		cout << ">> start" << endl;
		for (int i = 0; i < data.capacity(); i++) {
			cout << "РљРѕРјРµРЅС‚Р°СЂ: " << i + 1 << endl << data.at(i) << endl << endl;
		}
		cout << ">> end" << endl;
	}
	_getch();
	return 0;
}