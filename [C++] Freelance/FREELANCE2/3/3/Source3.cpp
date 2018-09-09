#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <math.h>

using namespace std;

struct Polinom { //використовуємо код попереднього завдання
	double*allNums;// масив коефіцієнтів
	int power;
	int c;// степінь полінома + С

	void inputPolinom(int powerX) {
		this->power = powerX; //зберігаємо розмір
		allNums = new double[this->power];
		for (int i = this->power - 1; i > 0; i--) {	// вводимо поліном від максимально степеня до 1
			cout << "Введіть коефіцієнт " << i + 1 << " степеня: ";
			cin >> allNums[i];
		}
		cout << "Введіть коефіцієнт 1 степеня: ";
		cin >> allNums[0];
		cout << "Введіть С(вільний член): ";
		cin >> this->c;
	}
	double getValueInPoint(double x) {	//шукаємо значення полінома в точці
		double res = 0; //сума всіх частин
		for (int i = 0; i < this->power; i++) {
			res += allNums[i] * pow(x, i + 1);	// Сх^i
		}
		return res;
	}
	static Polinom powerTo(Polinom a,int powerSt) {		
		if (powerSt == 1)
			return a;
		return powerTo(a*a,powerSt-1);
	}

	Polinom operator*(Polinom& b) {	//перевантаження оператора множення
		Polinom x;
		x.allNums = new double[this->power*b.power+b.power];//незабуваємо виділити більше пам'яті
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
	//перевантаження оператора зсуву вліво для легкого виводу в консоль
	for (int i = p.power - 1; i > 0; i--) {// виводимо усі коеф. з "Х" та степенем 
		o << " " << p.allNums[i] << "x" << i + 1 <<
			((fabs(p.allNums[i - 1]) == p.allNums[i - 1]) ? " + " : " ");//додаємо + там де додатній коеф
	} o << p.allNums[0] << "x" << ((abs(p.c) == p.c) ? " + " : " ") << p.c << endl;// і останні..
	return o;
}
int main() {
	SetConsoleOutputCP(1251);

	Polinom a, b;
	int power;
	cout << "Введіть поліном: \n";
	a.inputPolinom(2);
	cout << "Введіть степінь: \n";
	cin>> power;
	Polinom p = Polinom::powerTo(a, power);
	cout << p; // використовуємо статичну функцію без створення нового об'єкту
	_getch();
	return 0;
}