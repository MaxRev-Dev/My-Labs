#include <iostream>
#include <Windows.h>
#include <conio.h>
using namespace std;

long long Cut(int k,long long n) {
	auto r = n; int rx=1;
	while ((r = r / 10) != 0)
		rx++;
	if (rx!=k) return	Cut(k, n / 10);
	return n;
}

int main() {
	SetConsoleOutputCP(1251);
	int x,k; cout << "Введіть число: ";
	cin >> x;
	cout << "Введіть К: ";
	cin >> k;
	cout << Cut(k,x);
	_getch();
	return 0;
}
