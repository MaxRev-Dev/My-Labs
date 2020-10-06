#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

int main() {
	SetConsoleOutputCP(1251);
	int size_NxN;
	
	cout << "Введіть розмір масиву: ";
	cin >> size_NxN;

	//Виділяємо пам'ять під масив
	int *matrix = new int[size_NxN];

	cout << "\nВипадково згенеровані числа:" << endl;
	//заповнюємо масив випадковими числами 
	for (int i = 0; i < size_NxN; i++) {
		matrix[i] = rand() % 1000; //випадкове число в межах від 0 до 1000
		cout << "[" << matrix[i] << "] ";
	}
	cout << endl << endl;

	cout << "Непарні:\n";
	for (int i = 0; i < size_NxN; i++) {
		if (matrix[i] % 2 != 0) cout << "["<< matrix[i]<<"] "; // виводимо непарні числа
	}

	_getch();
	return 0;
}