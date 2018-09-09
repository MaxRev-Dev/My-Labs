#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <tuple>
#include <algorithm>

void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}
void bubbleSort(int arr[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
}

using namespace std;

tuple<int, int>MinMax(int*a, int size) {
	int max = MININT;
	int min = MAXINT, in1 = 0, in2 = 0;
	for (int i = 0; i < size; i++) { //find max
		if (a[i] > max) {
			max = a[i];
			in1 = i;
		}
	}
	for (int i = 0; i < size; i++) { //find min
		if (a[i] < min) {
			min = a[i];
			in2 = i;
		}
	}
	return std::make_tuple(in1, in2);
}

void ReplaceLocalMinMax(int **m, int size) {
	for (int i = 0; i < size; i++) {
		int *curCol = new int[size], iter = 0;
		for (int j = 0; j < size; j++) {
			curCol[iter++] = m[j][i];
		}
		int f, l;	std::tie(f, l) = MinMax(curCol, iter); // indexes of max && min elements
		int *local = new int[(f > l) ? f - l : l - f], loc = 0;	// memory for array of local min <> max
		for (int g = f; (f > l) ? g >= l : g <= l; (f > l) ? g-- : g++) {
			local[loc++] = curCol[g];	// copying to array of local min <> max
		}
		bubbleSort(local, loc); // sorting array of min<>max
		for (int g = f, loc = 0; (f > l) ? g >= l : g <= l; (f > l) ? g-- : g++) {
			m[g][i] = local[loc++]; //puting local it in matrix
		}

		delete curCol, local; //memory cleaning
	}
}

int main() {
	SetConsoleOutputCP(1251);
	int size;
	cout << "¬вед≥ть розм≥р матриц≥ дл€ генеруван€: ";
	cin >> size;
	int **m = new int*[size];
	for (int i = 0; i < size; i++) {
		m[i] = new int[size];

	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			m[i][j] = 1 + rand() % 9;
			cout << m[i][j] << " ";
		}cout << endl;
	}
	cout << endl;

	ReplaceLocalMinMax(m, size);
	
	cout << endl;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << m[i][j] << " ";
		}cout << endl;
	}

	_getch();
	return 0;
}