#include <iostream>
#include <conio.h>
#include <iomanip>
#include <Windows.h>

using namespace std;

//Задача 5
void Min(int**m, int sizeN) {
	int index;
	for (int i = 0; i < sizeN; i++) {
		int min = MAXINT;
		for (int j = 0; j < sizeN; j++) {
			if (m[i][j] < min) {
				min = m[i][j];
				index = j;
			}
		}
		m[i][index] = m[i][i];
		m[i][i] = min;
	}
}
void TestMaxrix() {
	int n = 5;
	int **m = new int*[5];
	for (int i = 0; i < n; i++) {
		m[i] = new int[n];
		for (int j = 0; j < n; j++) {
			m[i][j] = rand() % 10 + 1;
			cout << m[i][j] << " ";
		}cout << endl;
	}cout << endl;
	Min(m, n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << m[i][j] << " ";
		}cout << endl;
	}
	_getch();
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//задача 5
	TestMaxrix();
	_getch();
	return 0;
}