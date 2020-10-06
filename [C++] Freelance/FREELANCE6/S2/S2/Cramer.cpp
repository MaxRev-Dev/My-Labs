#include <iostream> 
#include <conio.h>
#include <Windows.h>
#include <iomanip>
#include "MatrixHelper.h"


using namespace std;

/* Ð ÑšÐ ÂµÐ¡â€šÐ Ñ•Ð Ò‘ Ð Ñ™Ð¡Ð‚Ð Â°Ð Ñ˜Ð ÂµÐ¡Ð‚Ð Â°*/
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


	SquareMatrix tmp = CopyMatrix(A);
	x = SolveCramer(A, Determinant(tmp), b);

	cout << "Answer solved with Cramer method: ";
	for (int i = 0; i < A.size; ++i) {
		cout << setprecision(3) << x[i] << " ";
	}cout << endl;


	deleteMatrix(A);
	deleteMatrix(tmp);
	_getch();
	return 0;
}
