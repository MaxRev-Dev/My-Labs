#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

#pragma region For Harder Way
/*РћРіРѕР»РѕС€РµРЅРЅСЏ Р±С–Р±Р»С–РѕС‚РµРє С– РІР»Р°СЃРЅРёС… С‚РёРїС–РІ РґР»СЏ СЂРѕР±РѕС‚Рё Р· РјР°С‚СЂРёС†РµСЋ*/
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
	РєС–РЅРµС†СЊ РѕРіРѕР»РѕС€РµРЅСЊ РІР»Р°СЃРЅРёС… С‚РёРїС–РІ СЃРєР»Р°РґРЅРѕС— РјР°С‚СЂРёС†С–
*/

#pragma endregion

void spiralOut(int **a,int m,int n) {
	int i, k = 0, l = 0;

	/*  k - С–РЅРґРµРєСЃ РїРµСЂС€РѕРіРѕ СЂСЏРґРєР°
	m - С–РЅРґРµРєСЃ РѕСЃС‚Р°РЅРЅСЊРѕРіРѕ СЂСЏРґРєР°
	l - С–РЅРґРµРєСЃ РїРµСЂС€РѕРіРѕ СЃС‚РѕРІРїС†СЏ
	n - С–РЅРґРµРєСЃ РѕСЃС‚Р°РЅРЅСЊРѕРіРѕ СЃС‚РѕРІРїС†СЏСЏ
	i - С–С‚РµСЂР°С‚РѕСЂ
	*/

	while (k < m && l < n)
	{
		/* Р’РёРІРѕРґРёРјРѕ РїРµСЂС€РёР№ СЂСЏРґРѕРє С–Р· Р·Р°Р»РёС€РєСѓ СЂСЏРґРєС–РІ */
		for (i = l; i < n; ++i)
		{
			cout<< a[k][i]<<" ";
		}
		k++;

		/* Р’РёРІРѕРґРёРјРѕ РїРµСЂС€РёР№ СЃС‚РѕРІРїРµС†СЊ С–Р· Р·Р°Р»РёС€РєСѓ СЂСЏРґРєС–РІ  */
		for (i = k; i < m; ++i)
		{
			cout << a[i][n - 1] << " ";
		}
		n--;

		/*  Р’РёРІРѕРґРёРјРѕ РѕСЃС‚Р°РЅРЅС–Р№ СЂСЏРґРѕРє С–Р· Р·Р°Р»РёС€РєСѓ СЂСЏРґРєС–РІ*/
		if (k < m)
		{
			for (i = n - 1; i >= l; --i)
			{
				cout << a[m - 1][i] << " ";
			}
			m--;
		}
		/*Р’РёРІРѕРґРёРјРѕ РїРµСЂС€РёР№ СЃС‚РѕРІРїРµС†СЊ С–Р· Р·Р°Р»РёС€РєСѓ */
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
	cout << "Р’РІРµРґС–С‚СЊ СЂРѕР·РјС–СЂРЅС–СЃС‚СЊ РјР°С‚СЂРёС†С–: "; 
	int n;
	cin >> n;
	int **a = new int*[n],iter=0; //Р’РёРґС–Р»СЏС”РјРѕ РґРёРЅР°РјС–С‡РЅРѕ РїР°Рј'СЏС‚СЊ РїС–Рґ РјР°СЃРёРІ С– Р·Р°РїРѕРІРЅСЋС”РјРѕ Р№РѕРіРѕ
	for (int i = 0; i < n; i++) {
		a[i] = new int[n];
		for(int j=0;j<n;j++) a[i][j]=iter++;
	}
	spiralOut(a, n, n);// Р’РёРІРѕРґРёРјРѕ РјР°С‚СЂРёС†СЋ СЏРє СЂСЏРґРѕРє
	cout << endl << endl;

	//Harder Way
	printSpiralArray(getSpiralArray(n));// С‚Р°Рє РјРѕР¶РЅР° РІРёРІРµСЃС‚Рё РјР°С‚СЂРёС†СЋ РєРІР°РґСЂР°С‚РЅСѓ

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
