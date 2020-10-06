#include <iostream>
#include <conio.h>
#include <Windows.h>

#define N 12 // размер масива - константа

using namespace std;

int main() {
	SetConsoleOutputCP(1251);
	//инициализируем максимум как минимум типа INT
	int a[N],max =MININT,index;
	cout << "Введите масив из 12 елементов"<<endl;
	for (int i = 0; i < N; i++) 
	{
		cout << "A[" << i + 1 << "] = ";
		cin >> a[i];
	}
	cout << "Исходный масив:"<<endl;
	for (int i = 0; i < N; i++)
		cout << a[i] << " ";
	for (int i = 0; i < N; i++) {
		if (a[i] > max) { max = a[i]; index = i+1; }// сохраняем число и его ииндекс в масиве
		if (a[i+1] != fabs(a[i+1])) break; //если модуль числа != число => оно отрицательное
	}
	cout << "\nНаибольший елемент масива до первого отрицательного\n";
	cout << "A[" << index << "] = " << a[index-1];

	_getch();
	return 0;
}