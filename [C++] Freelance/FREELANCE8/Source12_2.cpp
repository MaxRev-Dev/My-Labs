#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

int main() {
	SetConsoleOutputCP(1251);

	int A[100];//������ ���� ���������
	int N;//���������� ��������� �������
	cout << "������� ���������� ��������� � �������: ";
	cin >> N;
	int sum = 0;//����� ������������� �����
	int count_zero = 0;//���������� ����� ����� ����
	int count = 0;//���������� ������������� �����
	int SUM = 0;//����� ������������� �����
	cout << "������� �������� �������: ";
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < N; i++) {
		if (A[i] < 0) {
			sum += A[i];//��������� ������������� �����
		}
		else if (A[i] == 0) {
			count_zero++;//������� ���������� ����� = 0
		}
		else {
			count++;//������� ����� > 0 
			SUM += A[i];//����� ����� > 0
		}
	}



	cout << "����� ���� ������������� ���������: " << sum << endl;
	cout << "���������� �����, ������ ����: " << count_zero << endl;
	cout << "��������� ������� �������������� ������ ������������� �����: " << SUM / count << endl;
	int B[100];//������ ��� ����� < �������� ���������������
	int count_a = 0;//���������� ����� < �������� ���������������
	for (int i = 0; i < N; i++) {
		if (A[i] < SUM / count) {
			count_a++;
		}
	}
	int j = 0;
	for (int i = 0; i < N; i++) {//������������ �������� < �������� ��������������� � ����� ������
		if (A[i] < SUM / count) {
			B[j] = A[i];
			j++;
		}
	}
	for (int j = 0; j < count_a; j++) {
		cout << B[j] << " ";
	}
	cout << endl;
	_getch();
	return 0;
}