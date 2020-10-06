#include <iostream>
#include<Windows.h>
#include <conio.h>

using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int N = 100;
	int *a = new int[N];
	int max = MININT;
	for (int i = 0; i < N; i++) {
		a[i] = rand() % 9 + 1;
		if (a[i] > max) max = a[i];
		cout << a[i] << " ";
	}
	cout << "\n\n\n";
	int maxcount = 0;

	for (int i = 0; i < N; i++) {
		if (a[i] == max)++maxcount;
	}
	cout <<"РњР°РєСЃРёРјР°Р»СЊРЅРµ Р·РЅР°С‡РµРµРЅСЏ Сѓ "<< maxcount<<" РµР»РµРј.";


	_getch();
	return 0;
}