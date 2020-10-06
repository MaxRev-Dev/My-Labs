#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;
 
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int x;
	cout << "������ ������� ������: ";
	cin >> x;
	int **a = new int*[x]; //�������� ���'��� �� ������
	for (int i = 0; i < x; i++) {
		a[i] = new int[2];
		cout << "³����� [1] => ����� " << i + 1 << ": ";
		cin >> a[i][0];
		cout << "³����� [2] => ����� " << i + 1 << ": ";
		cin >> a[i][1];
	}
	
	/* 
	       2|-----|4 MinT
		1|--------------|5
		 MaxB 3|----------|6
		       |--| result 
	*/


	int  minT = MAXINT, maxB = MININT; // ������ ���������� ��������� ��������
	for (int i = 0; i < x; i++) { 
		if (a[i][0] > maxB) maxB = a[i][0]; //max of bottom
		if (a[i][1] < minT) minT = a[i][1]; //min of top
	}
	if (maxB < minT) {
		cout << "³����� �������������: �(" << maxB << ") B(" << minT << ")";
	} else cout << "³����� �� �������������";

	_getch();
	return 0;
}