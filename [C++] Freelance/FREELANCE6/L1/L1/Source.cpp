#include <iostream>
#include <Windows.h>
#include <algorithm>
#include <string>
#include <conio.h> 

using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int N = 100;
	int *a = new int[N];
	for (int i = 0; i < N; i++) {
		a[i] = rand() % 1000000 + 1; // заповнюємо рандомними числами
		cout << a[i] << " ";
	}cout << endl;

	string *sA = new string[N];

	a[50] = 1000000; // буде найбільшим з усіх

	for (int i = 0; i < N; i++) {
		char buff[20];
		_itoa_s(a[i], buff, 10); // конвертуємо в стрічку
		sA[i] = buff;
	}
	int max = MININT, index = -1;
	for (int i = 0; i < N; i++) {
		int v = count(sA[i].begin(), sA[i].end(), '0'); //пошук 
		if (v > max) { max = v; index = i; }
	}

	cout << "\nЧисло " << sA[index] << " містить найбільше нулів - " << max << endl;
	_getch();
	return 0;
}