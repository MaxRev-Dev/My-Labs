#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

int main() {
	SetConsoleOutputCP(1251);

	cout << "Введите последовательность чисел через пробел и закончите 0"<<endl;
	int n, even = 0, odd = 0;
	while (true) { //пока мы не прервем цикл
		cin >> n;
		if (n == 0)break; //конец последовательности
		if (n % 2 == 1) odd++; // остача от деления = 1, число нечётное
		else even++; //
	}
	cout << "Чётных: " << even << "\n" << "Нечётных: " << odd;

	_getch();
	return 0;
}