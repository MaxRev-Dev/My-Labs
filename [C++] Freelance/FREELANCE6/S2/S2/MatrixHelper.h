#pragma once
#define MatrixHelper 
#include <iostream> 
using namespace std;

typedef struct { // Визначаємо свій тип матриці 
	int size; //розмір
	double **elems; //масив елементів
} SquareMatrix;

/*	Ініціалізація матриці з масиву */
SquareMatrix InitMatrix(int num, double ** xelems) {
	SquareMatrix A;
	A.size = num;
	A.elems = new double*[num];

	for (int i = 0; i < num; ++i) {
		A.elems[i] = new double[num];
		for (int j = 0; j < num; ++j)
			A.elems[i][j] = xelems[i][j];
	}
	return A;
}

/* Копіювання матриці */
SquareMatrix CopyMatrix(SquareMatrix src) {
	SquareMatrix dest;
	dest.size = src.size;
	dest.elems = new double*[dest.size];
	for (int i = 0; i < dest.size; ++i) {
		dest.elems[i] = new double[dest.size];
		for (int j = 0; j < dest.size; ++j)
			dest.elems[i][j] = src.elems[i][j];
	}
	return dest;
}
/* Визначник матриці */
double Determinant(SquareMatrix A) {
	double det = 1;

	for (int j = 0; j < A.size; ++j) {
		int i_max = j;
		for (int i = j; i < A.size; ++i) /*шукаємо індекс максимуму в рядку*/
			if (A.elems[i][j] > A.elems[i_max][j])
				i_max = i;

		if (i_max != j) { /*якщо не діагональний, то перестановка,
						  тоді  det *= -1*/
			for (int k = 0; k < A.size; ++k) {
				double tmp = A.elems[i_max][k];
				A.elems[i_max][k] = A.elems[j][k];
				A.elems[j][k] = tmp;
			}
			det *= -1;
		}

		if (fabs(A.elems[j][j]) < 1e-12) { // наближений до 0
			cout << "\nSingular matrix!\n"; /*Матриця вироджена = визначник 0*/
			return 0;
		}

		for (int i = j + 1; i < A.size; ++i) {
			double mult = -A.elems[i][j] / A.elems[j][j];
			for (int k = 0; k < A.size; ++k)
				A.elems[i][k] += mult * A.elems[j][k];
		}
	}

	for (int i = 0; i < A.size; ++i)
		det *= A.elems[i][i];

	return det;
}


/* Видалення матриці*/
void deleteMatrix(SquareMatrix A) {
	for (int i = 0; i < A.size; ++i)
		free(A.elems[i]);
	free(A.elems);
}



/*Додатково:

Це ще однин метод пошуку визначника тільки через мінори*/
/* Ця фукція бере матрицю на індексах і та j - висотою m
Ідеальна для мінорів*/
void GetMatrixAtAA(double **mas, double **p, int i, int j, int m) {
	int mI, mJ, nI, nJ;
	nI = 0;
	for (mI = 0; mI<m - 1; mI++) { //check row
		if (mI == i) nI = 1;
		nJ = 0;
		for (mJ = 0; mJ<m - 1; mJ++) {//check coll
			if (mJ == j) nJ = 1;
			p[mI][mJ] = mas[mI + nI][mJ + nJ];
		}
	}
}
/* Пошук визначника */
double Determinant(double **mas, int m) {
	int f, a; double l, o, r;

	double **p = new double*[m];
	for (f = 0; f < m; f++)
		p[f] = new double[m];
	l = 0; o = 0;
	r = 1;
	a = m - 1;
	if (m < 1) cout << "\nНеможливо знайти визначник матриці!\n";
	if (m == 1) {
		o = mas[0][0];
		return(o);
	}
	if (m == 2) {
		o = mas[0][0] * mas[1][1] - (mas[1][0] * mas[0][1]);
		return(o);
	}
	if (m > 2)
		for (f = 0; f < m; f++) {
			GetMatrixAtAA(mas, p, f, 0, m);
			o = o + r * mas[f][0] * Determinant(p, a);
			r = -r;
		}
	return o;
}