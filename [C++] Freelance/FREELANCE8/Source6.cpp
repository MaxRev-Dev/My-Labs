#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <iomanip>

using namespace std;

int main() {
	SetConsoleOutputCP(1251);//для вывода кириллицы
	int N;
	cout << "Введите разницу в значениях:";
	cin >> N;

	cout << setw(2) << "Метры" << setw(2) << "|" << setw(12) << "Километры" << endl;
	for (int i = 100; i <= 1000; i += N) {
		// устанавливаем "сетку" таблицы		//фиксированый вывод 3 знаков после плавающей точки .ххх
		cout << setw(5) << i << setw(2) << "|" << setw(10) << setprecision(3) << fixed << i / 1000.0 << endl;
	}
	_getch(); //пауза в консоли
	return 0;
}