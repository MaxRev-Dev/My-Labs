#include <iostream> 
#include <conio.h>
#include <Windows.h>
#include <iomanip>
#include "MatrixHelper.h"

using namespace std;

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

int xmain() {
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

	deleteMatrix(A);
	_getch();
	return 0;
}
