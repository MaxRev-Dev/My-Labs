#include <iostream> 
#include <Windows.h>
#include <conio.h>

using namespace std;

int main() {
	SetConsoleOutputCP(1251);

	int A[100];//������ 
	int N;//���������� ��������� � �������
	int count = 0;//�������
	int number;//����� ������� �������������� ����� 
	cin >> N;//������ ���������� ��������� � �������
	for (int i = 0; i < N; i++) {//������ �������� �������
		cin >> A[i];
	}
	for (int i = 0; i < N; i++) {//���� ��� �������� ���������� ������������� ����� � ��������� ���������
		if (A[i] < 0 && i % 2 != 0) {
			count++;
		}
	}
	for (int i = 0; i < N; i++) {//���� ��� ���������� ������ ������� �������������� ��������
		if (A[i] < 0) {
			number = i;
			break;
		}
	}

	//������ ������� ������ � ��������� �������� �������
	int temp = A[0];
	A[0] = A[N - 1];
	A[N - 1] = temp;

	cout << "���������� ������������� ����� � ��������� ���������: " << count << endl;
	cout << "����� ������� �������������� ����� : " << number << endl;
	for (int i = 0; i < N; i++) 
		cout << A[i] << " ";
	
	_getch();
	return 0;
}