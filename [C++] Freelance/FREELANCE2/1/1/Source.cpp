#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
	SetConsoleOutputCP(1251);

	ifstream ifs("./test.cpp", ios::in);//Відкриваємо файл на читання
	vector<string> data; //Використовуємо вектор. 
	//Це ніби той же масив string[] проте контейнер і він має розмір та свої методи
	string pure = "";
	while (!ifs.eof()) { // поки не кінець файлу
		string str;
		getline(ifs, str); // читаємо рядок
		if (str.find("/*") != string::npos) {//шукаємо у ньому початок коментаря
			string comment = "";
			comment += str += "\n";

			while (!ifs.eof()) {	// Читаємо коментар
				getline(ifs, str);
				if (str.find("*/") != string::npos) { //якщо знайдено кінець коменту
					comment += str += "\n";
					data.push_back(comment);	//Кінець коментаря.
					// Додаємо залишок у масив(вектор) 
					break; //повертаємось до звичайного читання файлу
				}
				comment += str += "\n";
				// Додаємо його у масив(вектор) 
			}

		}
		else {
			pure += str += "\n";
		}
	}
	ifs.close();//закриваємо файл

	ofstream ofs("./test.cpp", ios::trunc);
	ofs << pure;// записуємо чистий код без коментарів
	ofs.close();

	cout << "Файл прочитано і перезаписано. Виводимо коментарі..";
	if (data.capacity() == 0)cout << "\nКоментарів не знайдено\n";
	else {
		cout << ">> start" << endl;
		for (int i = 0; i < data.capacity(); i++) {
			cout << "Коментар: " << i + 1 << endl << data.at(i) << endl << endl;
		}
		cout << ">> end" << endl;
	}
	_getch();
	return 0;
}