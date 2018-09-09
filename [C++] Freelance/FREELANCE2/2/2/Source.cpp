#include <iostream>
#include <Windows.h>
#include <conio.h>


using namespace std;

struct Polinom {
	double*allNums;// масив коефіцієнтів
	int power;// степінь полінома
	void inputPolinom(int power) {	
		this->power = power; //зберігаємо розмір
		allNums = new double[power];
		for (int i = power-1; i > 0; i--) {	// вводимо поліном від максимально степеня до 1
			cout << "Введіть коефіцієнт " << i+1 << " степеня: ";
			cin >> allNums[i];
		}
		cout << "Введіть коефіцієнт 1 степеня: ";
		cin >> allNums[0];
	}
	double getValueInPoint(double x) {	//шукаємо значення полінома в точці
		double res=0; //сума всіх частин
		for (int i = 0; i < power; i++) {
			res += allNums[i] * pow(x,i+1);	// Сх^i
		}
		return res;
	}
	Polinom operator+(Polinom& b) {		//перевантаження оператора додавання 
		Polinom x; x.power = this->power;
		x.allNums = new double[this->power];
		for (int i = 0; i < this->power; i++) {
			x.allNums[i] = this->allNums[i] + b.allNums[i];
		}
		return x;
	}
	Polinom operator*(Polinom& b) {	//перевантаження оператора множення
		Polinom x;
		x.allNums = new double[this->power*b.power];//незабуваємо виділити більше пам'яті
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
		//перевантаження оператора зсуву вліво для легкого виводу в консоль
		for (int i = p.power-1; i > 0; i--) {// виводимо усі коеф. з "Х" та степенем 
			o << " " <<p.allNums[i] << "x"<<i+1<<
				((fabs(p.allNums[i - 1])== p.allNums[i - 1])?" + ":" ");//додаємо + там де додатній коеф
		} o << p.allNums[0]<<"x";// і останній..
		return o;
	}
};
int main() {
	SetConsoleOutputCP(1251);

	Polinom a,b;
	int power;
	cout << "Введіть степінь полінома: ";
	cin >> power;
	cout << "Введіть 1 поліном: \n";
	a.inputPolinom(power);
	cout << "Введіть 2 поліном: \n";
	b.inputPolinom(power);

	cout << "a + b =" << a + b<<endl;
	cout << "a * b =" << a * b << endl;
	int x;
	cout<< "Введіть Х: ";
	cin >> x;
	
	cout << "Значення полінома А в точці "<<x <<" = " << a.getValueInPoint(x);
	_getch();
	return 0;
}