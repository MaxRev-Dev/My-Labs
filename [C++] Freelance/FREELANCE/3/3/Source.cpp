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
	cout << "Р вЂ™Р Р†Р ВµР Т‘РЎвЂ“РЎвЂљРЎРЉ РЎвЂЎР С‘РЎРѓР В»Р С•: ";
	cin >> num;
	cout << "Р вЂ™Р Р†Р ВµР Т‘РЎвЂ“РЎвЂљРЎРЉ Р С”РЎР‚Р В°РЎвЂљР Р…РЎвЂ“РЎРѓРЎвЂљРЎРЉ Р С”Р С•РЎР‚Р ВµР Р…РЎРЏ: ";
	cin >> n;
	cout << square(num,num, n);
	_getch();
	return 0;
}