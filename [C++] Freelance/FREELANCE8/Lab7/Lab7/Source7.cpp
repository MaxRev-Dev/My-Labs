#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

int main() {
	SetConsoleOutputCP(1251);

	cout << "������� ������������������ ����� ����� ������ � ��������� 0"<<endl;
	int n, even = 0, odd = 0;
	while (true) { //���� �� �� ������� ����
		cin >> n;
		if (n == 0)break; //����� ������������������
		if (n % 2 == 1) odd++; // ������ �� ������� = 1, ����� ��������
		else even++; //
	}
	cout << "׸����: " << even << "\n" << "��������: " << odd;

	_getch();
	return 0;
}