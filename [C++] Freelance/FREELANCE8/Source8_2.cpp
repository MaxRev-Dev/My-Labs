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
	int i;
	int count = 0;//������� �����
	double sum_sqrt = 0;//����� ������ ������������� �����
	int multiply = 1;//����� ������������ �����
	while (N > 0) {
		cout << "������� �����: ";
		cin >> i;//������ �����
		if (i > 0) {//���� ����� > 0
			sum_sqrt += sqrt((double)i);
			count++;
		}
		 multiply *= i;
		N--;
	}
	cout << "���������� ������������� �����: " << count << endl;
	cout << "����� ������ ������������� �����: " << sum_sqrt << endl;
	cout << "����� ������������ �����: " << multiply<<endl;
	_getch();
	return 0;
}