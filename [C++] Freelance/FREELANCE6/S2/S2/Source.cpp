#include <iostream> 
#include <conio.h>
#include <Windows.h>
#include <iomanip>
#include "MatrixHelper.h"

using namespace std;


/* РњРµС‚РѕРґ РљСЂР°РјРµСЂР°*/
double* SolveCramer(SquareMatrix A, double det_A, double *b) {
	double *ret = new double[A.size];
	for (int i = 0; i < A.size; ++i) {
		SquareMatrix tmp = CopyMatrix(A);
		for (int j = 0; j < tmp.size; ++j)
			tmp.elems[j][i] = b[j];

		double det_tmp = Determinant(tmp);
		deleteMatrix(tmp);
		ret[i] = det_tmp / det_A;
	}
	return ret;
}
/* РњРµС‚РѕРґ Р—РµР№РґРµР»СЏ */
double* SolveSeidel(SquareMatrix A, double *b, double epsilon) {
	cout << "Solving with Seidel method:\n\nNormalizing matrix..\n";
	SquareMatrix tmp = CopyMatrix(A);
	double *b1 = new double[A.size];
	for (int i = 0; i < A.size; i++) {/*Р—РІРѕРґРёРјРѕ РґРѕ РЅРѕСЂРјР°Р»С–Р·РѕРІР°РЅРѕРіРѕ РІРёРіР»СЏРґСѓ*/
		for (int j = 0; j < A.size; j++) {
			if (i == j)
				tmp.elems[i][j] = (10 - A.elems[i][j]) / 10;
			else /* РґС–Р°РіРѕРЅР°Р»СЊ - РіРѕР»РѕРІРЅР° */
				tmp.elems[i][j] = -(A.elems[i][j] / 10);
			cout << tmp.elems[i][j] << " ";
		}
		b1[i] = b[i] / 10;
		cout << " = " << b1[i] << "   " << endl;
	}
	cout << "\nMatrix normalized\n\n";
	int k = 1;
	double eps = 1;
	double *X0 = new double[A.size], *X = new double[A.size];
	for (int i = 0; i < A.size; i++) { X[i] = X0[i] = b1[i]; }
	while (true)
	{
		if (eps < epsilon || k > 1000) break;
		//РЅСѓ С‚СѓС‚ С‚РёРїСѓ С„РѕСЂРјСѓР»Р°
		//xk(n+1)=A(k1)*x1(n)+A(k2)*x2(n)+A(k3)*x3(n)+B(k)
		for (int i = 0; i < A.size; i++) {
			double S = 0;
			for (int j = 0; j < A.size; j++) {
				if (j < i) S += tmp.elems[i][j] * X0[j];
				else /*СЏРєС‰Рѕ РµР»РµРјРµРЅС‚ РїС–Рґ РґС–Р°РіРѕРЅР°Р»Р»СЋ С‚Рѕ Р±РµСЂРµРјРѕ С…0*/
					S += tmp.elems[i][j] * X[j];
			} S += b1[i];
			X[i] = S;
		}

		cout << "Iteration: " << k << "   ";
		for (int i = 0; i < A.size; i++) {
			if (fabs(X[i] - X0[i]) < eps) {
				eps = fabs(X[i] - X0[i]); /*РїРµСЂРµРІС–СЂРєР° РЅР° Р·Р±С–Р¶РЅС–СЃС‚СЊ
										  abs( x РїРѕРїРµСЂРµРґРЅС–Р№ - x С‚РµРїРµСЂС–С€РЅС–Р№)*/
			}
			cout << X[i] << " ";
			X0[i] = X[i];
		}cout << endl;
		++k;
	}cout << endl;
	return X;
}
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

int main() {
	int N = 3;
	double eps = 0.00001;
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

	double *x = SolveSeidel(A, b, eps);

	cout << "Answer solved with Seidel method: ";
	for (int i = 0; i < A.size; ++i) {
		cout << setprecision(3) << x[i] << " ";
	}cout << endl;



	SquareMatrix tmp = CopyMatrix(A);
	x = SolveCramer(A, Determinant(tmp), b);

	cout << "Answer solved with Cramer method: ";
	for (int i = 0; i < A.size; ++i) {
		cout << setprecision(3) << x[i] << " ";
	}cout << endl;


	x = SolveGauss(A, b, eps);
	cout << "Answer solved with Gauss method: ";
	for (int i = 0; i < A.size; ++i) {
		cout << setprecision(3) << x[i] << " ";
	}cout << endl;


	deleteMatrix(A);
	deleteMatrix(tmp);
	_getch();
	return 0;
}

