#pragma once
#define MatrixHelper 
#include <iostream> 
using namespace std;

typedef struct { // Р’РёР·РЅР°С‡Р°С”РјРѕ СЃРІС–Р№ С‚РёРї РјР°С‚СЂРёС†С– 
	int size; //СЂРѕР·РјС–СЂ
	double **elems; //РјР°СЃРёРІ РµР»РµРјРµРЅС‚С–РІ
} SquareMatrix;

/*	Р†РЅС–С†С–Р°Р»С–Р·Р°С†С–СЏ РјР°С‚СЂРёС†С– Р· РјР°СЃРёРІСѓ */
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

/* РљРѕРїС–СЋРІР°РЅРЅСЏ РјР°С‚СЂРёС†С– */
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
/* Р’РёР·РЅР°С‡РЅРёРє РјР°С‚СЂРёС†С– */
double Determinant(SquareMatrix A) {
	double det = 1;

	for (int j = 0; j < A.size; ++j) {
		int i_max = j;
		for (int i = j; i < A.size; ++i) /*С€СѓРєР°С”РјРѕ С–РЅРґРµРєСЃ РјР°РєСЃРёРјСѓРјСѓ РІ СЂСЏРґРєСѓ*/
			if (A.elems[i][j] > A.elems[i_max][j])
				i_max = i;

		if (i_max != j) { /*СЏРєС‰Рѕ РЅРµ РґС–Р°РіРѕРЅР°Р»СЊРЅРёР№, С‚Рѕ РїРµСЂРµСЃС‚Р°РЅРѕРІРєР°,
						  С‚РѕРґС–  det *= -1*/
			for (int k = 0; k < A.size; ++k) {
				double tmp = A.elems[i_max][k];
				A.elems[i_max][k] = A.elems[j][k];
				A.elems[j][k] = tmp;
			}
			det *= -1;
		}

		if (fabs(A.elems[j][j]) < 1e-12) { // РЅР°Р±Р»РёР¶РµРЅРёР№ РґРѕ 0
			cout << "\nSingular matrix!\n"; /*РњР°С‚СЂРёС†СЏ РІРёСЂРѕРґР¶РµРЅР° = РІРёР·РЅР°С‡РЅРёРє 0*/
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


/* Р’РёРґР°Р»РµРЅРЅСЏ РјР°С‚СЂРёС†С–*/
void deleteMatrix(SquareMatrix A) {
	for (int i = 0; i < A.size; ++i)
		free(A.elems[i]);
	free(A.elems);
}



/*Р”РѕРґР°С‚РєРѕРІРѕ:

Р¦Рµ С‰Рµ РѕРґРЅРёРЅ РјРµС‚РѕРґ РїРѕС€СѓРєСѓ РІРёР·РЅР°С‡РЅРёРєР° С‚С–Р»СЊРєРё С‡РµСЂРµР· РјС–РЅРѕСЂРё*/
/* Р¦СЏ С„СѓРєС†С–СЏ Р±РµСЂРµ РјР°С‚СЂРёС†СЋ РЅР° С–РЅРґРµРєСЃР°С… С– С‚Р° j - РІРёСЃРѕС‚РѕСЋ m
Р†РґРµР°Р»СЊРЅР° РґР»СЏ РјС–РЅРѕСЂС–РІ*/
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
/* РџРѕС€СѓРє РІРёР·РЅР°С‡РЅРёРєР° */
double Determinant(double **mas, int m) {
	int f, a; double l, o, r;

	double **p = new double*[m];
	for (f = 0; f < m; f++)
		p[f] = new double[m];
	l = 0; o = 0;
	r = 1;
	a = m - 1;
	if (m < 1) cout << "\nРќРµРјРѕР¶Р»РёРІРѕ Р·РЅР°Р№С‚Рё РІРёР·РЅР°С‡РЅРёРє РјР°С‚СЂРёС†С–!\n";
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