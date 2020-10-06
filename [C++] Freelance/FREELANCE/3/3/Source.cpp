#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

double square(double num,double x, int step) {
	if (num <= 0)
		return 0;
	double x1 = ((step - 1)*x + (num / pow(x, step - 1)))/step;
	if (fabs(x - x1) < 0.01) return x;
	return square(num,x1, step);
}

int main() {
	SetConsoleOutputCP(1251);
	int num,n;
	cout << "¬вед≥ть число: ";
	cin >> num;
	cout << "¬вед≥ть кратн≥сть корен€: ";
	cin >> n;
	cout << square(num,num, n);
	_getch();
	return 0;
}