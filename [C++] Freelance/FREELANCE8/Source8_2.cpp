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
	int i;
	int count = 0;//счетчик чисел
	double sum_sqrt = 0;//сумма корней положительных чисел
	int multiply = 1;//общее произведение чисел
	while (N > 0) {
		cout << "Введите число: ";
		cin >> i;//вводим число
		if (i > 0) {//если число > 0
			sum_sqrt += sqrt((double)i);
			count++;
		}
		 multiply *= i;
		N--;
	}
	cout << "Количество положительных чисел: " << count << endl;
	cout << "Сумма корней положительных чисел: " << sum_sqrt << endl;
	cout << "Общее произведение чисел: " << multiply<<endl;
	_getch();
	return 0;
}