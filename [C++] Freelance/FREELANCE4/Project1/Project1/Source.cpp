#include <iostream>
#include <conio.h>
#include <vector>
#include <Windows.h>

using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int cols,rows;
	cout << "Р’РІРµРґС–С‚СЊ РєС–Р»СЊРєС–СЃС‚СЊ СЃС‚РѕРІРїС†С–РІ: ";
	cin >> cols;
	cout << "Р’РІРµРґС–С‚СЊ РєС–Р»СЊРєС–СЃС‚СЊ СЃС‚РѕРІРїС†С–РІ: ";
	cin >> rows;
	int**m = new int*[cols+1];
	//РІРІС–Рґ РјР°С‚СЂРёС†С–
	for (int i = 0; i < cols; i++) {
		m[i] = new int[rows+1];
		for (int j = 0; j < rows; j++) {
			cout << "Р’РІРµРґС–С‚СЊ A["<<i+1<<"]["<<j+1<<"]: ";
			cin >> m[i][j];
		}
	}
	//РІРёРІС–Рґ
	cout << endl<<"Р’Р°С€Р° РјР°С‚СЂРёС†СЏ"<<endl;
	for (int i = 0; i < cols; i++) {
		for (int j = 0; j < rows; j++) {
			cout << m[i][j] << " ";
		}cout << endl;
	}
	//РїРѕС€СѓРє РјР°РєСЃРёРјР°Р»СЊРЅРёС… РµР»РµРјРµРЅС‚С–РІ
	vector<int> maxline;
	for (int i = 0; i < cols; i++) {
		int rowMax = MININT,colsMax=MININT;
		for (int j = 0; j < rows; j++) {
			if (m[i][j] > rowMax) rowMax = m[i][j];
		}
		maxline.push_back(rowMax);
	}
	for (int i = 0; i < rows; i++) {
		int colsMax = MININT;
		for (int j = 0; j < cols; j++) {
			if (m[j][i] > colsMax) colsMax = m[j][i];
		}
		maxline.push_back(colsMax);
	}

	//СЂР°С…СѓС”РјРѕ СЃСѓРјСѓ
	int sum = 0;
	for (size_t i = 0; i < maxline.size(); i++) {
		sum += maxline[i];
	}
	cout <<"РЎСѓРјР° РґРѕСЂС–РІРЅСЋС” " << sum<<endl;
	//Р·Р°РїРёСЃ СЃСѓРјРё Сѓ РґС–Р°РіРѕРЅР°Р»СЊ
	for (int i = 0; i < cols; i++) {
		m[i][i] = sum;
	}
	//РІРёРІС–Рґ
	cout <<endl<<"РџРµСЂРµС‚РІРѕСЂРµРЅР° РјР°С‚СЂРёС†СЏ"<<endl;
	for (int i = 0; i < cols; i++) {
		for (int j = 0; j < rows; j++) {
			cout << m[i][j] << " ";
		}cout << endl;
	}
	
	_getch();
	return 0;
}