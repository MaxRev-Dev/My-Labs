#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

#pragma region For Harder Way
/*ќголошенн€ б≥бл≥отек ≥ власних тип≥в дл€ роботи з матрицею*/
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
	к≥нець оголошень власних тип≥в складноњ матриц≥
*/

#pragma endregion

void spiralOut(int **a,int m,int n) {
	int i, k = 0, l = 0;

	/*  k - ≥ндекс першого р€дка
	m - ≥ндекс останнього р€дка
	l - ≥ндекс першого стовпц€
	n - ≥ндекс останнього стовпц€€
	i - ≥тератор
	*/

	while (k < m && l < n)
	{
		/* ¬иводимо перший р€док ≥з залишку р€дк≥в */
		for (i = l; i < n; ++i)
		{
			cout<< a[k][i]<<" ";
		}
		k++;

		/* ¬иводимо перший стовпець ≥з залишку р€дк≥в  */
		for (i = k; i < m; ++i)
		{
			cout << a[i][n - 1] << " ";
		}
		n--;

		/*  ¬иводимо останн≥й р€док ≥з залишку р€дк≥в*/
		if (k < m)
		{
			for (i = n - 1; i >= l; --i)
			{
				cout << a[m - 1][i] << " ";
			}
			m--;
		}
		/*¬иводимо перший стовпець ≥з залишку */
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
	cout << "¬вед≥ть розм≥рн≥сть матриц≥: "; 
	int n;
	cin >> n;
	int **a = new int*[n],iter=0; //¬ид≥л€Їмо динам≥чно пам'€ть п≥д масив ≥ заповнюЇмо його
	for (int i = 0; i < n; i++) {
		a[i] = new int[n];
		for(int j=0;j<n;j++) a[i][j]=iter++;
	}
	spiralOut(a, n, n);// ¬иводимо матрицю €к р€док
	cout << endl << endl;

	//Harder Way
	printSpiralArray(getSpiralArray(n));// так можна вивести матрицю квадратну

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
