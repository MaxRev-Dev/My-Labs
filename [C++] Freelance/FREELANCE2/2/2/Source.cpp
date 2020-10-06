#include <iostream>
#include <Windows.h>
#include <conio.h>


using namespace std;

struct Polinom {
	double*allNums;// РјР°СЃРёРІ РєРѕРµС„С–С†С–С”РЅС‚С–РІ
	int power;// СЃС‚РµРїС–РЅСЊ РїРѕР»С–РЅРѕРјР°
	void inputPolinom(int power) {	
		this->power = power; //Р·Р±РµСЂС–РіР°С”РјРѕ СЂРѕР·РјС–СЂ
		allNums = new double[power];
		for (int i = power-1; i > 0; i--) {	// РІРІРѕРґРёРјРѕ РїРѕР»С–РЅРѕРј РІС–Рґ РјР°РєСЃРёРјР°Р»СЊРЅРѕ СЃС‚РµРїРµРЅСЏ РґРѕ 1
			cout << "Р’РІРµРґС–С‚СЊ РєРѕРµС„С–С†С–С”РЅС‚ " << i+1 << " СЃС‚РµРїРµРЅСЏ: ";
			cin >> allNums[i];
		}
		cout << "Р’РІРµРґС–С‚СЊ РєРѕРµС„С–С†С–С”РЅС‚ 1 СЃС‚РµРїРµРЅСЏ: ";
		cin >> allNums[0];
	}
	double getValueInPoint(double x) {	//С€СѓРєР°С”РјРѕ Р·РЅР°С‡РµРЅРЅСЏ РїРѕР»С–РЅРѕРјР° РІ С‚РѕС‡С†С–
		double res=0; //СЃСѓРјР° РІСЃС–С… С‡Р°СЃС‚РёРЅ
		for (int i = 0; i < power; i++) {
			res += allNums[i] * pow(x,i+1);	// РЎС…^i
		}
		return res;
	}
	Polinom operator+(Polinom& b) {		//РїРµСЂРµРІР°РЅС‚Р°Р¶РµРЅРЅСЏ РѕРїРµСЂР°С‚РѕСЂР° РґРѕРґР°РІР°РЅРЅСЏ 
		Polinom x; x.power = this->power;
		x.allNums = new double[this->power];
		for (int i = 0; i < this->power; i++) {
			x.allNums[i] = this->allNums[i] + b.allNums[i];
		}
		return x;
	}
	Polinom operator*(Polinom& b) {	//РїРµСЂРµРІР°РЅС‚Р°Р¶РµРЅРЅСЏ РѕРїРµСЂР°С‚РѕСЂР° РјРЅРѕР¶РµРЅРЅСЏ
		Polinom x;
		x.allNums = new double[this->power*b.power];//РЅРµР·Р°Р±СѓРІР°С”РјРѕ РІРёРґС–Р»РёС‚Рё Р±С–Р»СЊС€Рµ РїР°Рј'СЏС‚С–
		int newPower=0;
		for (int i = 0; i < this->power; i++) {
			for (int j = 0; j < b.power; j++) {
				x.allNums[newPower++] = this->allNums[i] * b.allNums[j];
			}
		} 
		x.power = newPower;
		return x;
	}
	friend ostream& operator<<(ostream&o, Polinom&p) {
		//РїРµСЂРµРІР°РЅС‚Р°Р¶РµРЅРЅСЏ РѕРїРµСЂР°С‚РѕСЂР° Р·СЃСѓРІСѓ РІР»С–РІРѕ РґР»СЏ Р»РµРіРєРѕРіРѕ РІРёРІРѕРґСѓ РІ РєРѕРЅСЃРѕР»СЊ
		for (int i = p.power-1; i > 0; i--) {// РІРёРІРѕРґРёРјРѕ СѓСЃС– РєРѕРµС„. Р· "РҐ" С‚Р° СЃС‚РµРїРµРЅРµРј 
			o << " " <<p.allNums[i] << "x"<<i+1<<
				((fabs(p.allNums[i - 1])== p.allNums[i - 1])?" + ":" ");//РґРѕРґР°С”РјРѕ + С‚Р°Рј РґРµ РґРѕРґР°С‚РЅС–Р№ РєРѕРµС„
		} o << p.allNums[0]<<"x";// С– РѕСЃС‚Р°РЅРЅС–Р№..
		return o;
	}
};
int main() {
	SetConsoleOutputCP(1251);

	Polinom a,b;
	int power;
	cout << "Р’РІРµРґС–С‚СЊ СЃС‚РµРїС–РЅСЊ РїРѕР»С–РЅРѕРјР°: ";
	cin >> power;
	cout << "Р’РІРµРґС–С‚СЊ 1 РїРѕР»С–РЅРѕРј: \n";
	a.inputPolinom(power);
	cout << "Р’РІРµРґС–С‚СЊ 2 РїРѕР»С–РЅРѕРј: \n";
	b.inputPolinom(power);

	cout << "a + b =" << a + b<<endl;
	cout << "a * b =" << a * b << endl;
	int x;
	cout<< "Р’РІРµРґС–С‚СЊ РҐ: ";
	cin >> x;
	
	cout << "Р—РЅР°С‡РµРЅРЅСЏ РїРѕР»С–РЅРѕРјР° Рђ РІ С‚РѕС‡С†С– "<<x <<" = " << a.getValueInPoint(x);
	_getch();
	return 0;
}