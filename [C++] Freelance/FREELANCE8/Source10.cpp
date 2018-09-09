#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <iomanip>
using namespace std;
//функция вычисления скидки
double Discount(double x, double perc) {
	return x * (100 - perc) / 100.0;
}
void Prog1() {

	cout << "Введите последовательность чисел через пробел и закончите 0" << endl;
	int n, even = 0, odd = 0;
	while (true) { //пока мы не прервем цикл
		cin >> n;
		if (n == 0)break; //конец последовательности
		if (n % 2 == 1) odd++; // остача от деления = 1, число нечётное
		else even++; //
	}
	cout << "Чётных: " << even << "\n" << "Нечётных: " << odd;

	_getch();
}
void Prog2() {

	int N; //количество чисел 
	cout << "Введите количество чисел: " << endl;
	cin >> N;//вводим количество чисел
	double i;
	double sum_pow_b = 0, sum_pow_a = 0, sum_sqrt_b = 0, sum_sqrt_a = 0;//объявление переменных 
	while (N > 0) {//начало цикла
		cout << "Введите число: ";
		cin >> i;//вводим число
		if (i < 0) {//если число < 0
			sum_pow_b += i;//сумма исходных чисел < 0
			sum_pow_a += pow(i, 2);//сумма чисел в квадрате
		}
		else {//иначе
			sum_sqrt_b += i;//сумма исходных чисел > 0
			sum_sqrt_a += sqrt(i);//сумма корней чисел
		}
		N--;//счетчик уменьшается до 0
	}
	cout << "Сумма исходных чисел ";
	if (sum_sqrt_b + sum_pow_b > sum_pow_a + sum_sqrt_a) //сравниваем сумму исходных чисел с полученных чисел
		cout << "больше";
	else
		cout << "меньше";
	cout << " чем сумма полученных чисел";
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
	cout << "Выберите програму:";
	cout << "[0] - Лаб10 - Скидка на товар"<<endl;
	cout << "[1] - Лаб7" << endl;
	cout << "[2] - Лаб8" << endl;
	cout << "[3] - Лаб9" << endl;
	cin >> choise;
	switch (choise) { //проверяем ввод
	case 0: {
		break; 
	}
	case 1: {
		Prog1(); 
		return 0; // дальше выход из програмы
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
	cout << "Введите стоимость товара: ";
	cin >> price;
	cout << "Введите первую скидку %: ";
	cin >> discount;
	price = Discount(price, discount);
	cout << "Цена на товар после 1 скидки: " << setprecision(2) << fixed << price << endl;
	cout << "Введите вторую скидку %: ";
	cin >> discount;
	price = Discount(price, discount);
	cout << "Цена на товар после 2 скидки: " << price;
	_getch();
	return 0;
}