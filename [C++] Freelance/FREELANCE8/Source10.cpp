#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <iomanip>
using namespace std;
//С„СѓРЅРєС†РёСЏ РІС‹С‡РёСЃР»РµРЅРёСЏ СЃРєРёРґРєРё
double Discount(double x, double perc) {
	return x * (100 - perc) / 100.0;
}
void Prog1() {

	cout << "Р’РІРµРґРёС‚Рµ РїРѕСЃР»РµРґРѕРІР°С‚РµР»СЊРЅРѕСЃС‚СЊ С‡РёСЃРµР» С‡РµСЂРµР· РїСЂРѕР±РµР» Рё Р·Р°РєРѕРЅС‡РёС‚Рµ 0" << endl;
	int n, even = 0, odd = 0;
	while (true) { //РїРѕРєР° РјС‹ РЅРµ РїСЂРµСЂРІРµРј С†РёРєР»
		cin >> n;
		if (n == 0)break; //РєРѕРЅРµС† РїРѕСЃР»РµРґРѕРІР°С‚РµР»СЊРЅРѕСЃС‚Рё
		if (n % 2 == 1) odd++; // РѕСЃС‚Р°С‡Р° РѕС‚ РґРµР»РµРЅРёСЏ = 1, С‡РёСЃР»Рѕ РЅРµС‡С‘С‚РЅРѕРµ
		else even++; //
	}
	cout << "Р§С‘С‚РЅС‹С…: " << even << "\n" << "РќРµС‡С‘С‚РЅС‹С…: " << odd;

	_getch();
}
void Prog2() {

	int N; //РєРѕР»РёС‡РµСЃС‚РІРѕ С‡РёСЃРµР» 
	cout << "Р’РІРµРґРёС‚Рµ РєРѕР»РёС‡РµСЃС‚РІРѕ С‡РёСЃРµР»: " << endl;
	cin >> N;//РІРІРѕРґРёРј РєРѕР»РёС‡РµСЃС‚РІРѕ С‡РёСЃРµР»
	double i;
	double sum_pow_b = 0, sum_pow_a = 0, sum_sqrt_b = 0, sum_sqrt_a = 0;//РѕР±СЉСЏРІР»РµРЅРёРµ РїРµСЂРµРјРµРЅРЅС‹С… 
	while (N > 0) {//РЅР°С‡Р°Р»Рѕ С†РёРєР»Р°
		cout << "Р’РІРµРґРёС‚Рµ С‡РёСЃР»Рѕ: ";
		cin >> i;//РІРІРѕРґРёРј С‡РёСЃР»Рѕ
		if (i < 0) {//РµСЃР»Рё С‡РёСЃР»Рѕ < 0
			sum_pow_b += i;//СЃСѓРјРјР° РёСЃС…РѕРґРЅС‹С… С‡РёСЃРµР» < 0
			sum_pow_a += pow(i, 2);//СЃСѓРјРјР° С‡РёСЃРµР» РІ РєРІР°РґСЂР°С‚Рµ
		}
		else {//РёРЅР°С‡Рµ
			sum_sqrt_b += i;//СЃСѓРјРјР° РёСЃС…РѕРґРЅС‹С… С‡РёСЃРµР» > 0
			sum_sqrt_a += sqrt(i);//СЃСѓРјРјР° РєРѕСЂРЅРµР№ С‡РёСЃРµР»
		}
		N--;//СЃС‡РµС‚С‡РёРє СѓРјРµРЅСЊС€Р°РµС‚СЃСЏ РґРѕ 0
	}
	cout << "РЎСѓРјРјР° РёСЃС…РѕРґРЅС‹С… С‡РёСЃРµР» ";
	if (sum_sqrt_b + sum_pow_b > sum_pow_a + sum_sqrt_a) //СЃСЂР°РІРЅРёРІР°РµРј СЃСѓРјРјСѓ РёСЃС…РѕРґРЅС‹С… С‡РёСЃРµР» СЃ РїРѕР»СѓС‡РµРЅРЅС‹С… С‡РёСЃРµР»
		cout << "Р±РѕР»СЊС€Рµ";
	else
		cout << "РјРµРЅСЊС€Рµ";
	cout << " С‡РµРј СЃСѓРјРјР° РїРѕР»СѓС‡РµРЅРЅС‹С… С‡РёСЃРµР»";
	_getch();
}
void Prog3() {
	double xmin = 1,
		xmax = 2,
		ymin = 2,
		ymax = 5,
		q1 = 0.2,
		q2 = 0.5,
		b = -0.5;

	cout << setw(3) << setfill('-') << "X" << setw(8) << "Y" << setw(8) << "Z" << endl;
	for (double x = xmin; x <= xmax; x += q1) {
		for (double y = ymin; y <= ymax; y += q2) {
			double z = pow(x, -sqrt(y))*tan(x*b + 1.7);
			cout << setfill(' ') << setw(3) << x
				<< setw(3) << "|"
				<< setw(5) << y
				<< setw(3) << "|"
				<< setprecision(4) << z << endl;
		}
	}

	_getch();
}

int main() {
	SetConsoleOutputCP(1251);
	int choise = -1;
	cout << "Р’С‹Р±РµСЂРёС‚Рµ РїСЂРѕРіСЂР°РјСѓ:";
	cout << "[0] - Р›Р°Р±10 - РЎРєРёРґРєР° РЅР° С‚РѕРІР°СЂ"<<endl;
	cout << "[1] - Р›Р°Р±7" << endl;
	cout << "[2] - Р›Р°Р±8" << endl;
	cout << "[3] - Р›Р°Р±9" << endl;
	cin >> choise;
	switch (choise) { //РїСЂРѕРІРµСЂСЏРµРј РІРІРѕРґ
	case 0: {
		break; 
	}
	case 1: {
		Prog1(); 
		return 0; // РґР°Р»СЊС€Рµ РІС‹С…РѕРґ РёР· РїСЂРѕРіСЂР°РјС‹
	}
	case 2: {
		Prog2();
		return 0;
	}
	case 3: {
		Prog3();
		return 0;
	}
	default:break;
	}

	double discount, price;
	cout << "Р’РІРµРґРёС‚Рµ СЃС‚РѕРёРјРѕСЃС‚СЊ С‚РѕРІР°СЂР°: ";
	cin >> price;
	cout << "Р’РІРµРґРёС‚Рµ РїРµСЂРІСѓСЋ СЃРєРёРґРєСѓ %: ";
	cin >> discount;
	price = Discount(price, discount);
	cout << "Р¦РµРЅР° РЅР° С‚РѕРІР°СЂ РїРѕСЃР»Рµ 1 СЃРєРёРґРєРё: " << setprecision(2) << fixed << price << endl;
	cout << "Р’РІРµРґРёС‚Рµ РІС‚РѕСЂСѓСЋ СЃРєРёРґРєСѓ %: ";
	cin >> discount;
	price = Discount(price, discount);
	cout << "Р¦РµРЅР° РЅР° С‚РѕРІР°СЂ РїРѕСЃР»Рµ 2 СЃРєРёРґРєРё: " << price;
	_getch();
	return 0;
}