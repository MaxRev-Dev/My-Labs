#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

int main() {
	SetConsoleOutputCP(1251);
	int size_NxN;
	
	cout << "������ ����� ������: ";
	cin >> size_NxN;

	//�������� ���'��� �� �����
	int *matrix = new int[size_NxN];

	cout << "\n��������� ���������� �����:" << endl;
	//���������� ����� ����������� ������� 
	for (int i = 0; i < size_NxN; i++) {
		matrix[i] = rand() % 1000; //��������� ����� � ����� �� 0 �� 1000
		cout << "[" << matrix[i] << "] ";
	}
	cout << endl << endl;

	cout << "������:\n";
	for (int i = 0; i < size_NxN; i++) {
		if (matrix[i] % 2 != 0) cout << "["<< matrix[i]<<"] "; // �������� ������ �����
	}

	_getch();
	return 0;
}