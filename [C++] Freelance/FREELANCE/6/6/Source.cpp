#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

#pragma region For Harder Way
/*���������� ������� � ������� ���� ��� ������ � ��������*/
#include <vector>
#include <memory>	// for auto_ptr
#include <cmath>	// for the ceil and log10 and floor functions
#include <iostream>
#include <iomanip>	// for the setw function

typedef vector<int> IntRow;
typedef vector<IntRow> IntTable;
auto_ptr< IntTable > getSpiralArray(int dimension);
void printSpiralArray(const auto_ptr< IntTable >& spiralArrayPtr);
/*
	����� ��������� ������� ���� ������� �������
*/

#pragma endregion

void spiralOut(int **a,int m,int n) {
	int i, k = 0, l = 0;

	/*  k - ������ ������� �����
	m - ������ ���������� �����
	l - ������ ������� �������
	n - ������ ���������� ��������
	i - ��������
	*/

	while (k < m && l < n)
	{
		/* �������� ������ ����� �� ������� ����� */
		for (i = l; i < n; ++i)
		{
			cout<< a[k][i]<<" ";
		}
		k++;

		/* �������� ������ �������� �� ������� �����  */
		for (i = k; i < m; ++i)
		{
			cout << a[i][n - 1] << " ";
		}
		n--;

		/*  �������� ������� ����� �� ������� �����*/
		if (k < m)
		{
			for (i = n - 1; i >= l; --i)
			{
				cout << a[m - 1][i] << " ";
			}
			m--;
		}
		/*�������� ������ �������� �� ������� */
		if (l < n)
		{
			for (i = m - 1; i >= k; --i)
			{
				cout << a[i][l] << " ";
			}
			l++;
		}
	}
}

int main() {
	SetConsoleOutputCP(1251);
	cout << "������ ��������� �������: "; 
	int n;
	cin >> n;
	int **a = new int*[n],iter=0; //�������� �������� ���'��� �� ����� � ���������� ����
	for (int i = 0; i < n; i++) {
		a[i] = new int[n];
		for(int j=0;j<n;j++) a[i][j]=iter++;
	}
	spiralOut(a, n, n);// �������� ������� �� �����
	cout << endl << endl;

	//Harder Way
	printSpiralArray(getSpiralArray(n));// ��� ����� ������� ������� ���������

	_getch();
	return 0;
}

#pragma region Harder Way
auto_ptr< IntTable > getSpiralArray(int dimension)
{
	auto_ptr< IntTable > spiralArrayPtr(new IntTable(
		dimension, IntRow(dimension)));

	int numConcentricSquares = static_cast< int >(ceil(
		static_cast< double >(dimension) / 2.0));

	int j;
	int sideLen = dimension;
	int currNum = 0;

	for (int i = 0; i < numConcentricSquares; i++)
	{
		// do top side
		for (j = 0; j < sideLen; j++)
			(*spiralArrayPtr)[i][i + j] = currNum++;

		// do right side
		for (j = 1; j < sideLen; j++)
			(*spiralArrayPtr)[i + j][dimension - 1 - i] = currNum++;

		// do bottom side
		for (j = sideLen - 2; j > -1; j--)
			(*spiralArrayPtr)[dimension - 1 - i][i + j] = currNum++;

		// do left side
		for (j = sideLen - 2; j > 0; j--)
			(*spiralArrayPtr)[i + j][i] = currNum++;

		sideLen -= 2;
	}

	return spiralArrayPtr;
}

void printSpiralArray(const auto_ptr< IntTable >& spiralArrayPtr)
{
	size_t dimension = spiralArrayPtr->size();

	int fieldWidth = static_cast< int >(floor(log10(
		static_cast< double >(dimension * dimension - 1)))) + 2;

	size_t col;
	for (size_t row = 0; row < dimension; row++)
	{
		for (col = 0; col < dimension; col++)
			cout << setw(fieldWidth) << (*spiralArrayPtr)[row][col];
		cout << endl;
	}
}
#pragma endregion
