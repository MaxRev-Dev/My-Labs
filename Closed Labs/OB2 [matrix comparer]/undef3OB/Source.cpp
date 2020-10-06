#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

class MatrixComparer {
private:
	int **M1, **M2,_size;

public:
	MatrixComparer(int** m1, int**m2,int size) {
		M1 = m1, M2 = m2, _size = size;
	}
	void ShowResult() {
		for (int i = 0; i < _size; i++) {
			for (int j = 0; j < _size; j++) {
				if (M1[i][j] != M2[i][j]) {
					cout << "Матриці не однакові" << endl; return;
				}
			}
		}
		cout << "Матриці ідентичні" << endl;
	}
}; 
int size;
int** CreateMatrix() {
	int**m;
	if (::size > 5) { cout << "Матриця завелика для введення\n"; return 0; }
	m = new int*[::size];
	for (int i = 0; i < ::size; i++) {
		m[i] = new int[::size];
		for (int j = 0; j < ::size; j++) {
			cout << "A[" << i + 1 << "][" << j + 1 << "] : ";
			cin >>m[i][j];
		}
	}return m;

}
int main() {
	SetConsoleOutputCP(1251);
	int **m1, **m2;
	cout << "Введіть розмір квадратної матриці: ";
	cin >> ::size;
	cout << "Введіть першу матрицю:\n";
	m1 = CreateMatrix();
	cout << "Введіть другу матрицю:\n";
	m2 = CreateMatrix();
	MatrixComparer *cmp = new MatrixComparer(m1, m2,::size);
	cmp->ShowResult();
	_getch();
	return 0;
}