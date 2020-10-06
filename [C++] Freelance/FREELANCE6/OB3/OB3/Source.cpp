#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <time.h>

using namespace std;

int GetModule(int**a,int cols,int rows) {
	int sum = 0;
	for (int i = 0; i < rows; i++) {
		int max = MININT; //протилежне значення для максимуму
		for (int j = 0; j < cols; j++) {
			if (a[i][j] > max) max = a[i][j];
		}
		sum += max;
	}
	return sum;
}
int **SumMatrix(int **a, int**b, int cols, int rows) {
	int **cur = new int*[rows];
	for (int i = 0; i < rows; i++) {
		cur[i] = new int[cols];
		for (int j = 0; j < cols; j++) {
			cur[i][j] = a[i][j] + b[i][j];
		}
	}
	return cur;
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));// random seed для рандому
	int rows, cols, N;
	double result;

	int ***xMatrix; 
	 N = 3;
	xMatrix = new int**[N]; // просто масив матриць

	cout << "Введіть кількість стовпців матриці: ";
	cin >> cols;
	cout << "Введіть кількість рядків матриці: ";
	cin >> rows;

	for (int x = 0; x < N; x++) {
		int**cur = xMatrix[x]; //беремо матрицю з масиву

		cur = new int*[rows];
		for (int i = 0; i < rows; i++) {
			cur[i] = new int[cols];
			for (int j = 0; j < cols; j++) {
				cur[i][j] = rand() % 90 + 10; //заповнюємо випадковими числами
			}
		}
		xMatrix[x] = cur; //записуємо нову матрицю в масив
	}
	cout << endl;
	for (int x = 0; x < N; x++) {
		cout << "Матриця [" << x + 1 << "]"<<endl;
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				cout << xMatrix[x][i][j] << " ";
			}cout << endl;
		}
		cout << endl << endl;
	}

	int *mod = new int[N];
	for (int x = 0; x < N; x++) {
		mod[x] = GetModule(xMatrix[x],cols,rows);
	}
	
	int mA = abs(mod[0]), mB = abs(mod[1]), mC = abs(mod[2]); // тут по модулю
	int **a_b_c =
		SumMatrix( // X+C
			SumMatrix(xMatrix[0], xMatrix[1], cols, rows), // A+B
		xMatrix[2], cols, rows);

	result = (mA + mB + mC) / GetModule(a_b_c,cols,rows); //та формула
	cout << "\nResult " << result<<endl;
	_getch();
	return 0;
}