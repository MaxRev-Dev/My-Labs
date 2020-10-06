#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <vector>
#include <fstream>
#include <string>
#include <stdio.h>
using namespace std;

struct Item {
	char *entertp_code,
		*shop_code,
		*empl_num,
		*b_date,
		*nat_code,
		*empl_surn,
		*maried,
		*all_exp,
		*unnint_exp,
		*prof_code,
		*_class;
	float salary;
};

void WriteToFile(Item*all, int count) {
	ofstream out("data.dat", ios::trunc);
	for (int i = 0; i < count; i++) {
		out <<
			all[i].entertp_code << "|" <<
			all[i].shop_code << "|" <<
			all[i].empl_num << "|"<<
			all[i].empl_surn << "|" <<
			all[i].b_date << "|" <<
			all[i].nat_code << "|" <<
			all[i].maried << "|" <<
			all[i].all_exp << "|" <<
			all[i].unnint_exp << "|" <<
			all[i].prof_code << "|" <<
			all[i]._class << "|" <<
			all[i].salary<<endl;
	}
	out.close();
}

char* checkInp(int count, bool num) {
	
	string str;  // очищення буфера вводу у разі помилок
	if (num) { // для чисел
		getline(cin, str); // ввід у строку
		if (atoi(str.c_str()) == 0||str.length()>count) { // якщо це не число 
			cout << "\nПомилка: неправильний ввід. Повторіть спробу\n";
			
			return checkInp(count, num); 
			//рекурсивно дістаємо відповідь, поки не буде правильна)
		}
	}
	else {
		char* ch = new char[50];
		cin.getline(ch,30); 
		return ch;
	}
	char*buff =  new char[100];
	memcpy(buff,str.c_str(),sizeof(str.c_str()));
	return buff;
}

int count; // глобальна змінна розміру бази
Item* InputItems() {
	cout << "Кількість працівників для запису у файл: ";
	cin >> ::count; cin.get();
	Item *all = new Item[::count]; // нова база
	for (int i = 0; i < ::count; i++) {	
		cout << endl << "Працівник " << i + 1 << endl;
		cout << "Введіть код підпpиємства [5]: ";
		all[i].entertp_code = checkInp(5,true);
		cout << "Введіть код цеху [2]: ";
		all[i].shop_code = checkInp(2, true);
		cout << "Введіть табельний номеp пpацівника [4]: ";
		all[i].empl_num = checkInp(4, true);
		cout << "Введіть пpізвище пpацівника [30]: ";
		all[i].empl_surn = checkInp(30, false);// тут має бути слово
		cout << "Введіть рік наpодження [4]:";
		all[i].b_date = checkInp(4, true);
		cout << "Введіть код національності [2]: ";
		all[i].nat_code = checkInp(2, true);

		cout << "Введіть сімейний стан [1] 1/0: ";		
		int ism;
		cin >> ism; cin.get();
		all[i].maried =new char[2];			
		all[i].maried[0] = (ism == 0) ? '0' : '1';
		all[i].maried[1] = '\0';

		cout << "Введіть стаж pоботи загальний [2]: ";
		all[i].all_exp = checkInp(2, true);
		cout << "Введіть стаж pоботи непеpеpвний [2]: ";
		all[i].unnint_exp = checkInp(2, true);
		cout << "Введіть код пpофесії [4]: ";
		all[i].prof_code = checkInp(4, true);

		cout << "Введіть розpяд [1]: "; 
		cin >> ism; cin.get();
		char*buff = new char[5]; itoa(ism, buff, 10);
		all[i]._class = buff;

		cout << "Введіть оклад [float]: ";
		cin >> all[i].salary; cin.get(); cout << endl;
	}
	return all;
}

int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	Item*all_items = InputItems();
	WriteToFile(all_items, ::count);
	cout << "\nФайл записано та збережено, як data.dat\n";
	_getch();
	return 0;
}
