#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <iomanip>
#include <vector>
#include <fstream>
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
	double salary;
};
size_t count=0;
Item*ReadFile() {
	ifstream ifs("data.dat", ios::in);
	char*buff = new char[100];
	if (!ifs.is_open()){
	cout<<"Файл не знайдено. Це має бути data.dat";_getch();
	exit(1);
	}
	vector<Item> all;
	while (!ifs.eof())
	{
		Item a;
		ifs.getline(buff, 500);
		if (buff[0] != '\0') {
			int j = 0, i = 0;
			a.entertp_code = new char[5];
			while (buff[i] != '|') a.entertp_code[j++] = buff[i++]; a.entertp_code[j] = '\0';
			i++;

			j = 0;
			a.shop_code = new char[2];
			while (buff[i] != '|') a.shop_code[j++] = buff[i++]; a.shop_code[j] = '\0';
			i++;

			j = 0;
			a.empl_num = new char[4];
			while (buff[i] != '|') a.empl_num[j++] = buff[i++]; a.empl_num[j] = '\0';
			i++;

			j = 0;
			a.empl_surn = new char[30];
			while (buff[i] != '|') a.empl_surn[j++] = buff[i++]; a.empl_surn[j] = '\0';
			i++;

			j = 0;
			a.b_date = new char[4];
			while (buff[i] != '|') a.b_date[j++] = buff[i++]; a.b_date[j] = '\0';
			i++;

			j = 0;
			a.nat_code = new char[2];
			while (buff[i] != '|') a.nat_code[j++] = buff[i++]; a.nat_code[j] = '\0';
			i++;

			j = 0;
			a.maried = new char[1];
			while (buff[i] != '|') a.maried[j++] = buff[i++]; a.maried[j] = '\0';
			i++;

			j = 0;
			a.all_exp = new char[2];
			while (buff[i] != '|') a.all_exp[j++] = buff[i++]; a.all_exp[j] = '\0';
			i++;

			j = 0;
			a.unnint_exp = new char[2];
			while (buff[i] != '|') a.unnint_exp[j++] = buff[i++]; a.unnint_exp[j] = '\0';
			i++;

			j = 0;
			a.prof_code = new char[4];
			while (buff[i] != '|') a.prof_code[j++] = buff[i++]; a.prof_code[j] = '\0';
			i++;

			j = 0;
			a._class = new char[1];
			while (buff[i] != '|') a._class[j++] = buff[i++]; a._class[j] = '\0';
			i++;

			j = 0;
			char*tmp = new char[10];
			while (true) {
				tmp[j++] = buff[i++];
				if (buff[i] == '\0')break;
			}tmp[j] = '\0';
			a.salary = atof(tmp);

			all.push_back(a);
		}
	}
	ifs.close();
	::count = all.size();
	cout << "У файлі " << ::count << " записів\n";
	Item* allret = new Item[all.size()];
	for (int i = 0; i < all.size(); i++) {
		allret[i] = all.at(i);
	} return allret;
}
void printall(Item*all) {
	for (int i = 0; i < ::count; i++) {
		cout << endl <<
			"\nКод підпpиємства: " << all[i].entertp_code <<
			"\nКод цеху: " << all[i].shop_code <<
			"\nТабельний номеp пpацівника: " << all[i].empl_num <<
			"\nПpізвище пpацівника: " << all[i].empl_surn <<
			"\nРік наpодження: " << all[i].b_date <<
			"\nКод національності: " << all[i].nat_code <<
			"\nСімейний стан: " << all[i].maried <<
			"\nСтаж pоботи загальний: " << all[i].all_exp <<
			"\nСтаж pоботи непеpеpвний : " << all[i].unnint_exp <<
			"\nКод пpофесії: " << all[i].prof_code <<
			"\nРозpяд: " << all[i]._class <<
			"\nОклад : " << all[i].salary << endl;
	}
}
void tableHeader() {
	cout << endl << setw(18) << "|" << setw(28) << "| Загальний стаж |" << " Працівників за розрядами |" << endl;
	cout << "Код підприємства |"<<" Код цеху |  роботи, років |"<<"  1 | 2 | 3 | 4 | 5 | 6   |"<<endl;
}
void printClass(Item a,int*_class) {
	cout << setw(10) << a.entertp_code
		<< setw(9) << " | " << setw(5) << a.shop_code
		<< setw(6) << " | " << setw(7) << a.all_exp
		<< setw(11) << " |  "
		<< _class[0] << " | " << _class[1] << " | "
		<< _class[2] << " | " << _class[3] << " | "
		<< _class[4] << " | " << _class[5] << "   |" << endl;
	
}

bool contains(vector<Item> all, Item x) {
	for (int i = 0; i < all.size(); i++) {
		if (atoi(all[i].entertp_code) == atoi(x.entertp_code) &&
			atoi(all[i].shop_code) == atoi(x.shop_code) &&
			atoi(all[i].all_exp) == atoi(x.all_exp))
			return true;
	}
	return false;
}

void uniteEnterp(vector<Item> all) {
	vector< vector< Item > > CLASSES;
	for (int i = all.size(); i >0; i--) {
		bool found = false;
		if (CLASSES.size() > 0) {
			for (int g = 0; g < CLASSES.size(); g++) {
				if (contains(CLASSES[g], all[all.size() - 1])) {
					CLASSES[g].push_back(all[all.size() - 1]); all.pop_back(); 
					found = true;
				}
			}

		}
		if (!found) {
			vector<Item> enterp;
			enterp.push_back(all[all.size() - 1]);
			all.pop_back();
			CLASSES.push_back(enterp);
		}
	}


	if (CLASSES.size() == 0) {
		cout << endl << "Немає підприємств з такими працівниками" << endl << endl;
	}
	else {
		tableHeader();
	}
	for (int i = 0; i < CLASSES.size(); i++) {
		int *_class = new int[6];
		for (int f = 0; f < 6; f++) _class[f] = 0;
		for (int j = 0; j < CLASSES[i].size(); j++)
		{
			_class[atoi(CLASSES[i][j]._class) - 1] += 1;

		}
		printClass(CLASSES[i][0], _class);
	}
}

int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	Item*all_items = ReadFile();
	cout << "Файл успішно прочитано!" << endl;
	cout << "Вивести всі записи? 1/0 :";
	int x; cin >> x; cin.get();
	if (x ==1) printall(all_items);
	cout << endl;

	cout << "\n\n\nДо 20 років :";
	vector <Item> sorted;

	for (int i = 0; i < ::count; i++)
	{
		if ((2017 - atoi(all_items[i].b_date)) < 20) {
			sorted.push_back(all_items[i]);
		}
	}
	uniteEnterp(sorted);
	sorted.clear();
	cout << "\n\n\nВід 20 до 30 років :";
	
	for (int i = 0; i < ::count; i++)
	{
		int ys = 2017 - atoi(all_items[i].b_date);
		if (ys >= 20 && ys <= 30) {
			sorted.push_back(all_items[i]);
		}
	}
	uniteEnterp(sorted);
	sorted.clear();
	cout << "\n\n\nБільше 30 років :" ;

	for (int i = 0; i < ::count; i++)
	{
		if ((2017 - atoi(all_items[i].b_date)) > 30) {
			sorted.push_back(all_items[i]);
		}
	}
	uniteEnterp(sorted);
	sorted.clear();
	_getch();
	return 0;
}
