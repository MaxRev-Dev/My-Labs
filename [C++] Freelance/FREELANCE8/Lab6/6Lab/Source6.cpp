#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <iomanip>

using namespace std;

int main() {
	SetConsoleOutputCP(1251);//��� ������ ���������
	int N;
	cout << "������� ������� � ���������:";
	cin >> N;

	cout << setw(2) << "�����" << setw(2) << "|" << setw(12) << "���������" << endl;
	for (int i = 100; i <= 1000; i += N) {
		// ������������� "�����" �������		//������������ ����� 3 ������ ����� ��������� ����� .���
		cout << setw(5) << i << setw(2) << "|" << setw(10) << setprecision(3) << fixed << i / 1000.0 << endl;
	}
	_getch(); //����� � �������
	return 0;
}