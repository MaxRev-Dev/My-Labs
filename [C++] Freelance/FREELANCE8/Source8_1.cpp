#include <iostream>
#include <cmath>
#include <conio.h>
#include <Windows.h>

using namespace std;

int main() {
	SetConsoleOutputCP(1251);
	int N; //���������� ����� 
	cout << "������� ���������� �����: " << endl;
	cin >> N;//������ ���������� �����
	double i;
	double sum_pow_b = 0, sum_pow_a = 0, sum_sqrt_b = 0, sum_sqrt_a = 0;//���������� ���������� 
	while (N > 0) {//������ �����
		cout << "������� �����: ";
		cin >> i;//������ �����
		if (i < 0) {//���� ����� < 0
			sum_pow_b += i;//����� �������� ����� < 0
			sum_pow_a += pow(i, 2);//����� ����� � ��������
		}
		else {//�����
			sum_sqrt_b += i;//����� �������� ����� > 0
			sum_sqrt_a += sqrt(i);//����� ������ �����
		}
		N--;//������� ����������� �� 0
	}
	cout << "����� �������� ����� ";
	if (sum_sqrt_b + sum_pow_b > sum_pow_a + sum_sqrt_a) //���������� ����� �������� ����� � ���������� �����
		cout << "������";
	else
		cout << "������";
	cout << " ��� ����� ���������� �����";
	_getch();
	return 0;
}