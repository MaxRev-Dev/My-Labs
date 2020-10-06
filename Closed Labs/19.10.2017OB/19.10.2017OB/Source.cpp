#include <iostream>
#include <conio.h>
#include <Windows.h>

using namespace std;

class LinearSystem {
private:
	double **matrix,*B;
	int linesCount, XCount,i,j;
	//Вивід коренів
	void PrintSolved(double *x) {
		cout << "розв'язки системи:\n";
		for (i = 0; i<linesCount; i++)
			cout <<"X"<<i+1<< "= " <<x[i] << endl;
		cout << endl;
	}

	//Приватний конструктор для повернення результатів через вказівник 
	LinearSystem(double **mtx,int lines, int x) {
		this->matrix = mtx;
		this->linesCount = lines;
		this->XCount = x;
	}


	double * Gauss(double **a, double *y, int n)
	{
		double *x, max;
		int k, index;
		const double eps = 0.00001;  // точність
		x = new double[n];
		k = 0;
		while (k < n)
		{
			// Пошук рядка з максимальним a[i][k]
			max = abs(a[k][k]);
			index = k;
			for (int i = k + 1; i < n; i++)
			{
				if (abs(a[i][k]) > max)
				{
					max = abs(a[i][k]);
					index = i;
				}
			}
			// Перестановка рядків
			if (max < eps)
			{
				//немає нулювих діагональних елементів
				cout << "Розв'язок неможливий через не нульовий стовчик ";
				cout << index << " матриці A" << endl;
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
			// Нормалізація рівнянь
			for (int i = k; i < n; i++)
			{
				double temp = a[i][k];
				if (abs(temp) < eps) continue; // це нульвий тому пропускаємо
				for (int j = 0; j < n; j++)
					a[i][j] = a[i][j] / temp;
				y[i] = y[i] / temp;
				if (i == k)  continue; // це таке ж як і рахуємо зараз 
				for (int j = 0; j < n; j++)
					a[i][j] = a[i][j] - a[k][j];
				y[i] = y[i] - y[k];
			}
			k++;
		}
		// Зворотній хід
		for (k = n - 1; k >= 0; k--)
		{
			x[k] = y[k];
			for (int i = 0; i < k; i++)
				y[i] = y[i] - a[i][k] * x[k];
		}
		return x;
	}
public:
	//Конструктор 
	LinearSystem() {
		cout << "Потрібно ввести кількість рядків, невідомих \n\tта коефіціенти перед ними:\n";
		
		cout << "Кількість рядків: "; cin >> linesCount;
		cout << "Кількість невідомих:"; cin >> XCount;
			
		matrix = new double*[linesCount];
		for (int i = 0; i < linesCount; i++) {
			matrix[i] = new double[XCount];
		}
		cout << "Введіть коефіціенти СЛАР: "<<endl;
		for (int i = 0; i < linesCount; i++) {
			cout << "Рядок: " << i + 1 << endl;
			for (int j = 0; j < XCount; j++) {
				cout << "X" << j + 1 << "="; cin >> matrix[i][j];
			} cout << endl;
		}
		B = new double[linesCount];
		cout << "Введіть стовпчик з вільними коефіцієнтами: "<<endl;
		for (int i = 0; i < linesCount; i++) {
			cout<< "[" << i + 1 << "]  =";	cin >> B[i];
		}
		cout << "Матриця введена" << endl<<endl;

	}
	
	//Перевантаження оператора додавання
	LinearSystem* operator+(LinearSystem & R) {
		//Перевірка на сумісність
		if (R.linesCount != this->linesCount&& this->XCount != R.XCount) {
			cout << "Розміри СЛАР не однакові"<<endl;
			return nullptr;
		}
		//Матриця для результатів
		double**matrixTmp = new double*[linesCount];
		for (int i = 0; i < linesCount; i++) {
			matrixTmp[i] = new double[XCount];
		}
		//Віднімання кожного елемента окремо
		for (int i = 0; i < linesCount; i++) {
			for (int j = 0; j < XCount; j++) {
				matrixTmp[i][j] = this->matrix[i][j] + R.matrix[i][j];
			}
		}
		cout << "Матриці додані!\n";

		//Повертамо новий об'єкт через вказівник
		return new LinearSystem(matrixTmp,linesCount,XCount);
	}

	//Перевантаження оператора віднімання
	LinearSystem* operator-(LinearSystem &R) {
		//Перевірка на сумісність
		if (R.linesCount != this->linesCount&& this->XCount != R.XCount) {
			cout << "Розміри СЛАР не однакові" << endl;
			return nullptr;
		}
		//Матриця для результатів
		double**matrixTmp = new double*[linesCount];
		for (int i = 0; i < linesCount; i++) {
			matrixTmp[i] = new double[XCount];
		}
		//Додавання кожного елемента окремо
		for (int i = 0; i < linesCount; i++) {
			for (int j = 0; j < XCount; j++) {
				matrixTmp[i][j] = this->matrix[i][j] - R.matrix[i][j];
			}
		}
		cout << "Різницю виконано!\n";
		//Повертамо новий об'єкт через вказівник
		return new LinearSystem(matrixTmp, linesCount, XCount);
	}
	
	//Метод Гауса
	void SolveWithGaussMethodCompl() {
		PrintSolved(Gauss(this->matrix,this->B,linesCount));
	}
	
	//Метод класу для виводу матриці
	void ShowMatrix() {
		for (int i = 0; i < linesCount; i++) {
			for (int j = 0; j < XCount; j++) {
				cout << matrix[i][j] << "X"<<j+1<<" " <<
					(j+1<XCount?(matrix[i][j + 1] >= 0 ? "+ " : ""):"");
			}cout << endl;
		}
	}
	~LinearSystem() {
		for (int i = 0; i < linesCount; i++)
			delete[] matrix[i];
		delete[] matrix;
	}
};
int main() {
	SetConsoleOutputCP(1251);
	LinearSystem *heap = new LinearSystem[2];

	LinearSystem *solvedPlus = heap[0] + heap[1];
	if (solvedPlus != nullptr) {
		solvedPlus[0].ShowMatrix();
	}
	LinearSystem *solvedMinus = heap[0] - heap[1];
	if (solvedMinus != nullptr) {
		solvedMinus[0].ShowMatrix();
	}

	cout << "\n\nМатриця 1" << endl;
	heap[0].SolveWithGaussMethodCompl();
	cout << "Матриця 2"<<endl;
	heap[1].SolveWithGaussMethodCompl();

	_getch();
	return 0;
}