#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

int main() {
	SetConsoleOutputCP(1251);

	int A[100];//массив всех элементов
	int N;//количество элементов массива
	cout << "Введите количество элементов в массиве: ";
	cin >> N;
	int sum = 0;//сумма отрицательных чисел
	int count_zero = 0;//количество чисел равно нулю
	int count = 0;//количество положительных чисел
	int SUM = 0;//сумма положительных чисел
	cout << "Введите элементы массива: ";
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < N; i++) {
		if (A[i] < 0) {
			sum += A[i];//суммирует отрицательных чисел
		}
		else if (A[i] == 0) {
			count_zero++;//подсчет количества чисел = 0
		}
		else {
			count++;//подсчет чисел > 0 
			SUM += A[i];//сумма чисел > 0
		}
	}



	cout << "Сумма всех отрицательных элементов: " << sum << endl;
	cout << "Количество чисел, равных нулю: " << count_zero << endl;
	cout << "Вычислить среднее арифметическое только положительных чисел: " << SUM / count << endl;
	int B[100];//массив для чисел < среднего арифметического
	int count_a = 0;//количество чисел < среднего арифметического
	for (int i = 0; i < N; i++) {
		if (A[i] < SUM / count) {
			count_a++;
		}
	}
	int j = 0;
	for (int i = 0; i < N; i++) {//переписываем элементы < среднего арифметического в новый массив
		if (A[i] < SUM / count) {
			B[j] = A[i];
			j++;
		}
	}
	for (int j = 0; j < count_a; j++) {
		cout << B[j] << " ";
	}
	cout << endl;
	_getch();
	return 0;
}