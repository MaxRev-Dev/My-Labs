#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <iomanip>
using namespace std;

int main() {
	SetConsoleOutputCP(1251);
	const int N = 3, M = 2;
	int a[100][100];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << "A[" << i + 1 << "][" << j + 1 << "] = ";
			cin >> a[i][j];
		}
	}
	cout << "Матрица:"<<endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << setw(4)<<a[i][j]<<" ";
		}cout << endl;
	}
	int max = MININT,min=MAXINT,ximax,yimax,ximin,yimin;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (max < a[i][j]) {
				max = a[i][j];
				ximax = i;
				yimax = j;
			}
			if (min > a[i][j]) {
				min = a[i][j];
				ximin = i;
				yimin = j;
			}
		}
	}
	cout << "Максимальный елемент матрицы:"<<endl;
	cout << "A[" << ximax + 1 << "][" << yimax+1 << "] = " << a[ximax][yimax] << endl;
	cout << "Минимальный елемент матрицы:" << endl;
	cout << "A[" << ximin + 1 << "][" << yimin+1 << "] = " << a[ximin][yimin] << endl;

	_getch();
	return 0;
}