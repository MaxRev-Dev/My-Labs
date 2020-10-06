#include <iostream> 
#include <conio.h>
#include <Windows.h>
#include <iomanip>
#include "MatrixHelper.h"

using namespace std;

/* РњРµС‚РѕРґ Р“Р°СѓСЃР°*/
double * SolveGauss(SquareMatrix A, double *y, double epsilon)
{
	double *x, max, **a = A.elems;
	int k, index, n = A.size;
	const double eps = epsilon;  // С‚РѕС‡РЅС–СЃС‚СЊ
	x = new double[n];
	k = 0;
	while (k < n)
	{
		// РџРѕС€СѓРє СЂСЏРґРєР° Р· РјР°РєСЃРёРјР°Р»СЊРЅРёРј a[i][k]
		max = abs(a[k][k]);
		index = k;
		for (int i = k + 1; i < n; i++)
			if (abs(a[i][k]) > max)
			{
				max = abs(a[i][k]);
				index = i;
			}
		// РџРµСЂРµСЃС‚Р°РЅРѕРІРєР° СЂСЏРґРєС–РІ
		if (max < eps)
		{
			//РЅРµРјР°С” РЅСѓР»СЋРІРёС… РґС–Р°РіРѕРЅР°Р»СЊРЅРёС… РµР»РµРјРµРЅС‚С–РІ
			cout << "Р РѕР·РІ'СЏР·РѕРє РЅРµРјРѕР¶Р»РёРІРёР№ С‡РµСЂРµР· РЅРµ РЅСѓР»СЊРѕРІРёР№ СЃС‚РѕРІС‡РёРє ";
			cout << index << " РјР°С‚СЂРёС†С– A" << endl;
			return 0;
		}
		for (int j = 0; j < n; j++)
		{
			double temp = a[k][j];
			a[k][j] = a[index][j];
			a[index][j] = temp;
		}
		double temp = y[k];
		y[k] = y[index];
		y[index] = temp;
		// РќРѕСЂРјР°Р»С–Р·Р°С†С–СЏ СЂС–РІРЅСЏРЅСЊ
		for (int i = k; i < n; i++)
		{
			double temp = a[i][k];
			if (abs(temp) < eps) continue; // С†Рµ РЅСѓР»СЊРІРёР№ С‚РѕРјСѓ РїСЂРѕРїСѓСЃРєР°С”РјРѕ
			for (int j = 0; j < n; j++)
				a[i][j] = a[i][j] / temp;
			y[i] = y[i] / temp;
			if (i == k)  continue; // С†Рµ С‚Р°РєРµ Р¶ СЏРє С– СЂР°С…СѓС”РјРѕ Р·Р°СЂР°Р· 
			for (int j = 0; j < n; j++)
				a[i][j] = a[i][j] - a[k][j];
			y[i] = y[i] - y[k];
		}
		k++;
	}
	// Р—РІРѕСЂРѕС‚РЅС–Р№ С…С–Рґ
	for (k = n - 1; k >= 0; k--)
	{
		x[k] = y[k];
		for (int i = 0; i < k; i++)
			y[i] = y[i] - a[i][k] * x[k];
	}
	return x;
}

int xmain() {
	int N = 3;
	double eps = 0.00001,*x;
	double xelems[3][3] = {
		{ 9.3, -4.6, -3.4 },
	{ 5.4,    7,  0.4 },
	{ 3.2, -4.1,  8.8 }
	};

	double b[] = { -6.8, 4.5, 8.1 };

	double **elems = new double*[3];
	for (int i = 0; i < 4; i++) {
		elems[i] = new double[4];
		for (int j = 0; j < 4; j++) {
			elems[i][j] = xelems[i][j];
		}
	}

	SquareMatrix A = InitMatrix(N, elems);

	x = SolveGauss(A, b, eps);
	cout << "Answer solved with Gauss method: ";
	for (int i = 0; i < A.size; ++i) {
		cout << setprecision(3) << x[i] << " ";
	}cout << endl;


	deleteMatrix(A);
	_getch();
	return 0;
}
