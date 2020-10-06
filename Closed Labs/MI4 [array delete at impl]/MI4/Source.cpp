#include <iostream>
#include <conio.h>
#include <Windows.h>

using namespace std;
int size;
void Show(int *a) {
	for (int i = 0; i < ::size; i++) {
		cout << a[i]<<" ";
	}
}
int* DeleteAt(int *a, int n) {
	::size -= 1;
	int *a2 = new int[::size];
	for (int i =0; i < n - 1; i++) {
		a2[i] = a[i];
	}
	for (int i = n-1; i < ::size; i++) {
		a2[i] = a[i + 1];
	}
	return a2;
}
int main() {
	SetConsoleOutputCP(1251);
	
	cout << "Введіть N(розмір масиву): "; 
	cin >> ::size;
	int  *a = new int[::size],n;
	for (int i = 0; i < ::size; i++) a[i] = 1 + rand() % 9; 
	Show(a);

	cout << "\nІндекс елемента для видалення: ";
	cin >> n;
	a=DeleteAt(a, n);
	Show(a);

	_getch();
	return 0;
}