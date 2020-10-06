#include <iostream>
#include <conio.h>
#include <vector>
#include <Windows.h>

using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int cols,rows;
	cout << "Введіть кількість стовпців: ";
	cin >> cols;
	cout << "Введіть кількість стовпців: ";
	cin >> rows;
	int**m = new int*[cols+1];
	//ввід матриці
	for (int i = 0; i < cols; i++) {
		m[i] = new int[rows+1];
		for (int j = 0; j < rows; j++) {
			cout << "Введіть A["<<i+1<<"]["<<j+1<<"]: ";
			cin >> m[i][j];
		}
	}
	//вивід
	cout << endl<<"Ваша матриця"<<endl;
	for (int i = 0; i < cols; i++) {
		for (int j = 0; j < rows; j++) {
			cout << m[i][j] << " ";
		}cout << endl;
	}
	//пошук максимальних елементів
	vector<int> maxline;
	for (int i = 0; i < cols; i++) {
		int rowMax = MININT,colsMax=MININT;
		for (int j = 0; j < rows; j++) {
			if (m[i][j] > rowMax) rowMax = m[i][j];
		}
		maxline.push_back(rowMax);
	}
	for (int i = 0; i < rows; i++) {
		int colsMax = MININT;
		for (int j = 0; j < cols; j++) {
			if (m[j][i] > colsMax) colsMax = m[j][i];
		}
		maxline.push_back(colsMax);
	}

	//рахуємо суму
	int sum = 0;
	for (size_t i = 0; i < maxline.size(); i++) {
		sum += maxline[i];
	}
	cout <<"Сума дорівнює " << sum<<endl;
	//запис суми у діагональ
	for (int i = 0; i < cols; i++) {
		m[i][i] = sum;
	}
	//вивід
	cout <<endl<<"Перетворена матриця"<<endl;
	for (int i = 0; i < cols; i++) {
		for (int j = 0; j < rows; j++) {
			cout << m[i][j] << " ";
		}cout << endl;
	}
	
	_getch();
	return 0;
}