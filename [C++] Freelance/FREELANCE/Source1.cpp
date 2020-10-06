#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

long long fact(long long n) {
	return (n == 1 || n == 0) ? 1 : fact(n - 1) * n; 
	// ���������� ���������� ��������
}

long long FindBinominal(int n, int k) {
	return fact(n) / (fact(k)*fact(n - k));
	//������� ��. ����.
}


int main() {
	SetConsoleOutputCP(1251); // ��� ��������� � ������.
	// ���� �� ������ ������ � ������������� ������ ����� �� Lucida Console 
	int n, k;
	long long bc;
	cout << "������ N: "; cin >> n;
	cout << "������ �: "; cin >> k;
	if (n < k) { // ���� n<k �� ��������� ��� � ���� � ������� �� ���������
		cout << "\nN �� ���� ������ �� �. ��������..\n";
		bc= FindBinominal(k, n);
	}
	else bc = FindBinominal(n, k); // �������� ���� ��� �� ���� ������������ �����
	cout << "����������  = "<<bc<<endl; 
	cout << "����� ��������: \n";
	while (bc % 2 == 0) { // ĳ���� ���� ������ == 0
		cout << bc << endl; bc /= 2;
	}
	_getch();
	return 0;
}