#include <iostream> 
#include <Windows.h>
#include <conio.h>

using namespace std;

int main() {
	SetConsoleOutputCP(1251);

	int A[100];//массив 
	int N;//количество элементов в массиве
	int count = 0;//счетчик
	int number;//номер первого отрицательного числа 
	cin >> N;//вводим количество элементов в массиве
	for (int i = 0; i < N; i++) {//вводим элементы массива
		cin >> A[i];
	}
	for (int i = 0; i < N; i++) {//цикл для подсчета количества отрицательных чисел с нечетными индексами
		if (A[i] < 0 && i % 2 != 0) {
			count++;
		}
	}
	for (int i = 0; i < N; i++) {//цикл для нахождения номера первого отрицательного элемента
		if (A[i] < 0) {
			number = i;
			break;
		}
	}

	//меняем местами первый и последний элементы массива
	int temp = A[0];
	A[0] = A[N - 1];
	A[N - 1] = temp;

	cout << "Количество отрицательных чисел с нечетными индексами: " << count << endl;
	cout << "Номер первого отрицательного числа : " << number << endl;
	for (int i = 0; i < N; i++) 
		cout << A[i] << " ";
	
	_getch();
	return 0;
}