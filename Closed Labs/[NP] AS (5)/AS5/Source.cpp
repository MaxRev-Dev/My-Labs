#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <vector>
#include <string>
#include <fstream>

using namespace std;
struct Item { 
	string name, adr,tel;
};
char* gen_random(bool withAlfa, const int len) {
	char* alphanum = ((!withAlfa) ?
		"0123456789" : "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");
	char* s = new char[len];
	for (int i = 0; i < len; ++i) {
		s[i] = alphanum[rand() % (strlen(alphanum) - 1)];
	}
	s[len] = 0;
	return s;
}
class RefBook {
private:
	const string DBName = "RefBook_DB.txt";
	vector<Item> *obj;
public:
	RefBook() {
		obj = new vector<Item>();
		if (!this->OpenDB()) FiresFirstTime();
	}
	void FiresFirstTime() {
		for (int i = 0; i < 10; i++) {
			Item *it = new Item;
			it->adr = gen_random(true, 10);
			it->name = gen_random(true, 15);
			it->tel = gen_random(false, 10);
			obj->push_back(*it);
			delete it;
		}
	}
	void Seach(string query) {
		for (size_t i = 0; i < obj->size(); i++) {
			if (obj->at(i).tel.find(query)!=string::npos) {
				auto a = obj->at(i);
				cout << "\nЗнайдено: #" << i + 1 <<"\nІм'я: "<< a.name.c_str() << 
					"\nТел.: " << a.tel<<"\nАдреса: "<<a.adr.c_str()<<endl;
			}
		}
	}
	void ShowAll() {
		for (size_t i = 0; i < obj->size(); i++) {
			auto a = obj->at(i);
			cout <<"#"<< i + 1 << "\tІм'я: " << a.name.c_str() <<
				"\tТел.: " << a.tel.c_str() << "\tАдреса: " << a.adr.c_str() << endl;
		}
		cout << endl;
	}
	void Add(Item &item) {
		obj->push_back(item);
	}
	void SaveToFile() {
		ofstream of(DBName, ios::trunc);
		for (size_t i = 0; i < obj->size(); i++) {
			auto a = obj->at(i);
			of << a.name.c_str() <<" "<< a.tel.c_str() << " " << a.adr.c_str() << endl;
		}
	}
	void DeleteAll() {
		obj->clear();
	}
	bool OpenDB() {
		ifstream of(DBName);
		if (!of.is_open()) return false; 
		string str;
		while (!of.eof()) {
			getline(of, str);
			if (str.length() > 5) {
				Item *it = new Item;

				size_t p1 = str.find_first_of(' '), p2 = str.find_last_of(' ');
				it->name = str.substr(0, p1);
				it->tel = str.substr(p1 + 1, p2 - p1);
				it->adr = str.substr(p2);
				obj->push_back(*it);
			}
		}
		return true;

	}
};
int main() {
	SetConsoleOutputCP(1251);

	RefBook *b = new RefBook();
	b->ShowAll();
	string str;
	cout << "Введіть пошуковий запит по номеру: ";
	getline(cin, str);
	b->Seach(str);

	Item*it = new Item;
	cout << "Введіть ім'я нового запису: ";	getline(cin, it->name);
	cout << "Введіть телефон: "; getline(cin, it->tel); 
	cout << "Введіть адресу: "; getline(cin, it->adr);
	b->Add(*it); delete it;

	b->SaveToFile();
	cout << "\nКнигу збережено\n";
	b->DeleteAll();
	b->OpenDB();
	cout << "\nЗаписи завантажено\n";
	b->ShowAll();

	delete b;

	_getch();
	return 0;
}