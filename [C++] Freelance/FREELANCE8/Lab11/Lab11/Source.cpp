#include <iostream>
#include <conio.h>
#include <Windows.h>

#define N 12 // ������ ������ - ���������

using namespace std;

int main() {
	SetConsoleOutputCP(1251);
	//�������������� �������� ��� ������� ���� INT
	int a[N],max =MININT,index;
	cout << "������� ����� �� 12 ���������"<<endl;
	for (int i = 0; i < N; i++) 
	{
		cout << "A[" << i + 1 << "] = ";
		cin >> a[i];
	}
	cout << "�������� �����:"<<endl;
	for (int i = 0; i < N; i++)
		cout << a[i] << " ";
	for (int i = 0; i < N; i++) {
		if (a[i] > max) { max = a[i]; index = i+1; }// ��������� ����� � ��� ������� � ������
		if (a[i+1] != fabs(a[i+1])) break; //���� ������ ����� != ����� => ��� �������������
	}
	cout << "\n���������� ������� ������ �� ������� ��������������\n";
	cout << "A[" << index << "] = " << a[index-1];

	_getch();
	return 0;
}