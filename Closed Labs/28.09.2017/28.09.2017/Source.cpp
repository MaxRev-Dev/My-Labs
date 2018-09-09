#include <iostream>
#include <Windows.h>
#include <fstream>
#include <conio.h>
#include <vector>
#include <sstream>
using namespace std;

struct Contact {
	string Name;
	long long Tel;
	string Address;
	int PostArea;
	bool isMan;
	string Company;
};

template <typename Type>
class Contacts {
private:
	vector<Contact*> *obj;
public:
	Contacts();
	void Add(string name, long long tel, string addr, int postarrea, bool isman, string company);
	bool IsEmpty();
	void Print(int iter);
	void PrintAll();
	void Print(Type);
	void DeleteAt(int i);
	Type ShowExtra(Type);
	void WriteFile(string);
	void ReadFromFile(string);
};



template<typename Type>
Contacts<Type>::Contacts()
{
	obj = new vector<Contact*>[1];
}

template<typename Type>
void Contacts<Type>::Add(string name, long long tel, string addr, int postarrea, bool isman, string company)
{
	Contact *d = new Contact[1];
	d->Name = name;
	d->Tel = tel;
	d->Address = addr;
	d->PostArea = postarrea;
	d->isMan = isman;
	d->Company = company;
	this->obj[0].push_back(d);
}


template<typename Type>
bool Contacts<Type>::IsEmpty()
{	
	return (this->obj[0].size()>0 ? false : true);
}

template<typename Type>
void Contacts<Type>::DeleteAt(int i)
{
	this->obj[0].erase(this->obj[0].begin()+i);
}

template<typename Type>
void Contacts<Type>::Print(int i)
{
	auto f = this->obj->at(i);
	cout << "\n\nContact at [0]: ";
	cout <<  "\nІм'я: " << f->Name << " " << "\nТелефон: " ;
	cout <<"+"<< to_string(f->Tel) << " ";
	cout << "\nСтать: " << (f->isMan ? "Man" : "Woman") << " ";
	cout << "\nАдреса: " << f->Address << " ";
	cout << "\nПошт.індекс: " << f->PostArea << " ";
	cout << "\nКомпанія: " << f->Company << " "<<endl<<endl;
}
template<typename Type>
void Contacts<Type>::PrintAll()
{
	cout << "\n >>>>>> ALL >>>>>>";
	for (auto u = 0; u < this->obj->size();u++) {
		auto f = this->obj->at(u);
		cout << "\n\nContact at ["<<u<<"]: ";
		cout << "\nІм'я: " << f->Name << " " << "\nТелефон: ";
		cout << "+" << to_string(f->Tel) << " ";
		cout << "\nСтать: " << (f->isMan ? "Man" : "Woman") << " ";
		cout << "\nАдреса: " << f->Address << " ";
		cout << "\nПошт.індекс: " << f->PostArea << " ";
		cout << "\nКомпанія: " << f->Company << " " << endl << endl;
	}
	cout << " <<<<<< ALL <<<<<<\n";
}

template<typename Type>
Type Contacts<Type>::ShowExtra(Type x)
{
	auto g = this->obj;
	for (int i = 0; i < this->obj->size(); i++) {
			if (x.Name == g->at(i)->Name) return g->at(i)[0];
	}
	return Type();
}
template<typename Type>
 void Contacts<Type>::Print(Type f) {
	cout << "\n\nContact found ["<<f.Name<< "]: ";
	cout << "\nІм'я: " << f.Name << " " << "\nТелефон: ";
	cout << "+" << to_string(f.Tel) << " ";
	cout << "\nСтать: " << (f.isMan ? "Man" : "Woman") << " ";
	cout << "\nАдреса: " << f.Address << " ";
	cout << "\nПошт.індекс: " << f.PostArea << " ";
	cout << "\nКомпанія: " << f.Company << " " << endl << endl;
}
 template<typename Type>
 void Contacts<Type>::ReadFromFile(string path) {
	 ifstream i(path);
	 string sym;
	 
	 this->obj->clear();
	
	 while (!i.eof()) {
		 Contact *d = new Contact[1];
		 getline(i, sym); int y = 0;
		 if (sym == "")break;
		 while (sym.at(y) != ' ')
		 {
			 d->Name += sym.at(y++);
		 }y++;
		 string tmp;
		 while (sym.at(y) != ' ')
		 {
			 tmp += sym.at(y++);
		 }y++;
		 d->Tel=stoll(tmp ); tmp = "";
		 while (sym.at(y) != ' ')
		 {
			 tmp += sym.at(y++);
		 }y++;
		  d->PostArea=stoll(tmp); tmp = "";

		 while (sym.at(y) != ' ')
		 {
			 tmp += sym.at(y++);
		 }y++;
		 if (tmp == "1") d->isMan = true; else d->isMan = false;
		 while (sym.at(y) != ' ')
		 {
			 d->Address += sym.at(y++);
		 }y++;
		 while (y<sym.size())
		 {
			 d->Company += sym.at(y++);
		 }y++;
		 this->obj[0].push_back(d);
	 }
	 i.close();
	 cout << "\n\n\nSTRINGS FROM FILE\n";
	 this->PrintAll();
	 cout << "\n\n\END OF FILE!!!";
 }
 template<typename Type>
 void Contacts<Type>::WriteFile(string path) {
	 ofstream of(path, ios::trunc);
	 
	 for (int i = 0; i < this->obj->size(); ++i) {
		 auto f = this->obj->at(i);
		 of << f->Name << " " << to_string(f->Tel) << " ";
		 of << f->PostArea << " " << f->isMan << " "<<f->Address << " " << f->Company<<"\n";
	 }
	 of.close();
 }

 string path = "D:\\MaxRev\\Desktop\\28.09.2017.txt";
int main() {
	SetConsoleOutputCP(1251);
	Contacts<Contact>* c = new Contacts<Contact>[1]; 
	cout << (c->IsEmpty() ? "\nContact List is Empty\n" : "\nIS SET\n");
	c->Add("MaxRev", 380664707815, "local", 43636, true, "Comp1");
	c->Add("MaxRev2", 3845707815, "else", 4234, false, "Comp2");
	c->Add("MaxRev3", 38046634507815, "else", 252634, false, "Comp3");
	c->Add("MaxRev4", 38034456815, "local", 45774, true, "Comp4");
	cout << (c->IsEmpty() ? "Contact List is Empty" : "IS SET");
	c->Print(0);
	c->PrintAll();

	//Search impl
	Contact l;
	l.Name = "MaxRev3";
	c->Print(c->ShowExtra(l));

	//Remove
	c->DeleteAt(3);
	cout << "\nREMOVED 3\n";
	c->PrintAll();
	c->WriteFile(path);
	c->ReadFromFile(path);
	_getch();
	return 0;
}