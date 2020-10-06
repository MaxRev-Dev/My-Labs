#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

long long fact(long long n) {
	return (n == 1 || n == 0) ? 1 : fact(n - 1) * n; 
	// обчислюємо рекурсивно факторіал
}

long long FindBinominal(int n, int k) {
	return fact(n) / (fact(k)*fact(n - k));
	//формула бін. коеф.
}


int main() {
	SetConsoleOutputCP(1251); // для української в консолі.
	// якщо не працює змінити в налаштуваннях консолі шрифт на Lucida Console 
	int n, k;
	long long bc;
	cout << "Введіть N: "; cin >> n;
	cout << "Введіть К: "; cin >> k;
	if (n < k) { // якщо n<k то знаменник піде в мінус і рекурсія не скінчиться
		cout << "\nN має бути більшим ніж К. Замінюємо..\n";
		bc= FindBinominal(k, n);
	}
	else bc = FindBinominal(n, k); // замінюємо змінні щоб не було переповнення стеку
	cout << "Коефіцієнт  = "<<bc<<endl; 
	cout << "Прості множники: \n";
	while (bc % 2 == 0) { // Ділимо поки остача == 0
		cout << bc << endl; bc /= 2;
	}
	_getch();
	return 0;
}