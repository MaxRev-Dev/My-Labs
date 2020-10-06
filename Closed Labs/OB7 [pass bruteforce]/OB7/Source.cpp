#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string>
#include <algorithm>

using namespace std;

class Bruteforce {
private:
	bool alfa, num, symb,reg; // змінні для фільтрації пошуку
	string pass_old,
		charLow = "abcdefghijklmnopqrstuvwxyz", 
		charHigh="ABCDEFGHIJKLMNOPQRSTUVWXYZ", //Оголошення всіх пошукових символів
		nums="1234567890",
		symbols=" !\"#$%&\'()*+,-./:;<=>?@[\]^_`{|}~";
	int max; // довжина пароля
	volatile bool found=false; // змінна для виходу із глибинної рекурсії

	/*Тут робиться підбір пароля посимвольно
	Пароль буде знайдений якщо ВСІ фільтри вказані правильно
	*/
	void Routine(std::string const& chars, size_t max_len, std::string const& cur) {
		if (cur.length() == max_len) { 
			return; // якщо довжина знайденого більша 
			// то шукаємо далі але вище в стеку
		}
		else {
			for (auto c : chars) {
				std::string next = cur + c;
				cout << "#"<<++counter<<" Знайдено: " << next << "  >>>  Перевірка...";
				if (next == pass_old) { //перевірка на збіг
					cout << "\nПароль успішно знадено! - " << next;
					found = true;
					return;
				}
				else {
					cout << " Не підходить! " << endl;
					if (!found) Routine(chars, max_len, next);
					else return;
				}
				if(found) return;
			}// вихід з глибинної рекурсії
			if (found) return;
		}
	}
	static int counter; // лічильник на будь-якому рівні рекурсії 
public:
	Bruteforce(string pass, bool alfa,bool regist, bool num, bool symb,int maxlength) {
		pass_old = pass, this->alfa = alfa, this->num = num,
			this->symb = symb, reg = regist;
			max = maxlength;
	}
	void TryToCatchPass() {
			Routine( // передача значень фільтрами
				(alfa?(reg? charLow + charHigh :charHigh + charLow) :"")+(num?nums:"")+(symb?symbols:"") 
				,pass_old.length(),"");
			cout << "\nГотово!"<<endl;
	}

};
int Bruteforce::counter = 0;

int main() {
	SetConsoleOutputCP(1251);
	cout << "Введіть пароль: ";
	string  pass; int x; bool x1,x2, x3, x4;
	getline(cin, pass);
	cout << "Далі необхідно змінити фільтри: \n";
	cout << "Перевіряти букви? [1/0] ";
	cin >> x; cin.get(); x1 = static_cast<bool>(x);
	cout << "Спочатку нижній регістр букв? [1/0] ";
	cin >> x; cin.get(); x2 = static_cast<bool>(x);
	cout << "Перевіряти числа? [1/0] ";
	cin >> x; cin.get(); x3 = static_cast<bool>(x);
	cout << "Перевіряти спеціальні символи? [1/0] "; 
	cin >> x; cin.get(); x4 = static_cast<bool>(x);

	Bruteforce *brfs = new Bruteforce(pass, x1, x2, x3,x4,pass.length());
	cout << "\n!!! Довжина пароля збільшує час підбору у геометричній прогресії !!!\n";
	cout << "Оптимальні довжини паролів - до 3 символів \n(це 70300 значень для 52 букв)\nНатисніть Enter для початку підбору\n";
	_getch();
	brfs->TryToCatchPass();

	_getch();
	return 0;
}