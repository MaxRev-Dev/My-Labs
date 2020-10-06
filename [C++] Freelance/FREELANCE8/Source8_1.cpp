#include <iostream>
#include <cmath>
#include <conio.h>
#include <Windows.h>

using namespace std;

int main() {
	SetConsoleOutputCP(1251);
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
	return 0;
}