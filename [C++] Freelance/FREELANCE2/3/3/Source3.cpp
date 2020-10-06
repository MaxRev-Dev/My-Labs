#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <math.h>

using namespace std;

struct Polinom { //РІРёРєРѕСЂРёСЃС‚РѕРІСѓС”РјРѕ РєРѕРґ РїРѕРїРµСЂРµРґРЅСЊРѕРіРѕ Р·Р°РІРґР°РЅРЅСЏ
	double*allNums;// РјР°СЃРёРІ РєРѕРµС„С–С†С–С”РЅС‚С–РІ
	int power;
	int c;// СЃС‚РµРїС–РЅСЊ РїРѕР»С–РЅРѕРјР° + РЎ

	void inputPolinom(int powerX) {
		this->power = powerX; //Р·Р±РµСЂС–РіР°С”РјРѕ СЂРѕР·РјС–СЂ
		allNums = new double[this->power];
		for (int i = this->power - 1; i > 0; i--) {	// РІРІРѕРґРёРјРѕ РїРѕР»С–РЅРѕРј РІС–Рґ РјР°РєСЃРёРјР°Р»СЊРЅРѕ СЃС‚РµРїРµРЅСЏ РґРѕ 1
			cout << "Р’РІРµРґС–С‚СЊ РєРѕРµС„С–С†С–С”РЅС‚ " << i + 1 << " СЃС‚РµРїРµРЅСЏ: ";
			cin >> allNums[i];
		}
		cout << "Р’РІРµРґС–С‚СЊ РєРѕРµС„С–С†С–С”РЅС‚ 1 СЃС‚РµРїРµРЅСЏ: ";
		cin >> allNums[0];
		cout << "Р’РІРµРґС–С‚СЊ РЎ(РІС–Р»СЊРЅРёР№ С‡Р»РµРЅ): ";
		cin >> this->c;
	}
	double getValueInPoint(double x) {	//С€СѓРєР°С”РјРѕ Р·РЅР°С‡РµРЅРЅСЏ РїРѕР»С–РЅРѕРјР° РІ С‚РѕС‡С†С–
		double res = 0; //СЃСѓРјР° РІСЃС–С… С‡Р°СЃС‚РёРЅ
		for (int i = 0; i < this->power; i++) {
			res += allNums[i] * pow(x, i + 1);	// РЎС…^i
		}
		return res;
	}
	static Polinom powerTo(Polinom a,int powerSt) {		
		if (powerSt == 1)
			return a;
		return powerTo(a*a,powerSt-1);
	}

	Polinom operator*(Polinom& b) {	//РїРµСЂРµРІР°РЅС‚Р°Р¶РµРЅРЅСЏ РѕРїРµСЂР°С‚РѕСЂР° РјРЅРѕР¶РµРЅРЅСЏ
		Polinom x;
		x.allNums = new double[this->power*b.power+b.power];//РЅРµР·Р°Р±СѓРІР°С”РјРѕ РІРёРґС–Р»РёС‚Рё Р±С–Р»СЊС€Рµ РїР°Рј'СЏС‚С–
		int newPower = 0;
		for (int i = 0; i < this->power; i++) {
			for (int j = 0; j < b.power; j++) {
				x.allNums[newPower++] = this->allNums[i] * b.allNums[j];
			}
		}
		for (int j = 0; j < b.power; j++) {
			x.allNums[newPower++] = c * b.allNums[j];
		}
		x.power = newPower; x.c = this->c*b.c;
		return x;
	}
};
ostream& operator<<(ostream&o, Polinom&p) {
	//РїРµСЂРµРІР°РЅС‚Р°Р¶РµРЅРЅСЏ РѕРїРµСЂР°С‚РѕСЂР° Р·СЃСѓРІСѓ РІР»С–РІРѕ РґР»СЏ Р»РµРіРєРѕРіРѕ РІРёРІРѕРґСѓ РІ РєРѕРЅСЃРѕР»СЊ
	for (int i = p.power - 1; i > 0; i--) {// РІРёРІРѕРґРёРјРѕ СѓСЃС– РєРѕРµС„. Р· "РҐ" С‚Р° СЃС‚РµРїРµРЅРµРј 
		o << " " << p.allNums[i] << "x" << i + 1 <<
			((fabs(p.allNums[i - 1]) == p.allNums[i - 1]) ? " + " : " ");//РґРѕРґР°С”РјРѕ + С‚Р°Рј РґРµ РґРѕРґР°С‚РЅС–Р№ РєРѕРµС„
	} o << p.allNums[0] << "x" << ((abs(p.c) == p.c) ? " + " : " ") << p.c << endl;// С– РѕСЃС‚Р°РЅРЅС–..
	return o;
}
int main() {
	SetConsoleOutputCP(1251);

	Polinom a, b;
	int power;
	cout << "Р’РІРµРґС–С‚СЊ РїРѕР»С–РЅРѕРј: \n";
	a.inputPolinom(2);
	cout << "Р’РІРµРґС–С‚СЊ СЃС‚РµРїС–РЅСЊ: \n";
	cin>> power;
	Polinom p = Polinom::powerTo(a, power);
	cout << p; // РІРёРєРѕСЂРёСЃС‚РѕРІСѓС”РјРѕ СЃС‚Р°С‚РёС‡РЅСѓ С„СѓРЅРєС†С–СЋ Р±РµР· СЃС‚РІРѕСЂРµРЅРЅСЏ РЅРѕРІРѕРіРѕ РѕР±'С”РєС‚Сѓ
	_getch();
	return 0;
}