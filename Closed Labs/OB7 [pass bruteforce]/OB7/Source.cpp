#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string>
#include <algorithm>

using namespace std;

class Bruteforce {
private:
	bool alfa, num, symb,reg; // ���� ��� ���������� ������
	string pass_old,
		charLow = "abcdefghijklmnopqrstuvwxyz", 
		charHigh="ABCDEFGHIJKLMNOPQRSTUVWXYZ", //���������� ��� ��������� �������
		nums="1234567890",
		symbols=" !\"#$%&\'()*+,-./:;<=>?@[\]^_`{|}~";
	int max; // ������� ������
	volatile bool found=false; // ����� ��� ������ �� �������� ������

	/*��� �������� ���� ������ �����������
	������ ���� ��������� ���� �Ѳ ������� ������ ���������
	*/
	void Routine(std::string const& chars, size_t max_len, std::string const& cur) {
		if (cur.length() == max_len) { 
			return; // ���� ������� ���������� ����� 
			// �� ������ ��� ��� ���� � �����
		}
		else {
			for (auto c : chars) {
				std::string next = cur + c;
				cout << "#"<<++counter<<" ��������: " << next << "  >>>  ��������...";
				if (next == pass_old) { //�������� �� ���
					cout << "\n������ ������ �������! - " << next;
					found = true;
					return;
				}
				else {
					cout << " �� ��������! " << endl;
					if (!found) Routine(chars, max_len, next);
					else return;
				}
				if(found) return;
			}// ����� � �������� ������
			if (found) return;
		}
	}
	static int counter; // �������� �� ����-����� ��� ������ 
public:
	Bruteforce(string pass, bool alfa,bool regist, bool num, bool symb,int maxlength) {
		pass_old = pass, this->alfa = alfa, this->num = num,
			this->symb = symb, reg = regist;
			max = maxlength;
	}
	void TryToCatchPass() {
			Routine( // �������� ������� ���������
				(alfa?(reg? charLow + charHigh :charHigh + charLow) :"")+(num?nums:"")+(symb?symbols:"") 
				,pass_old.length(),"");
			cout << "\n������!"<<endl;
	}

};
int Bruteforce::counter = 0;

int main() {
	SetConsoleOutputCP(1251);
	cout << "������ ������: ";
	string  pass; int x; bool x1,x2, x3, x4;
	getline(cin, pass);
	cout << "��� ��������� ������ �������: \n";
	cout << "��������� �����? [1/0] ";
	cin >> x; cin.get(); x1 = static_cast<bool>(x);
	cout << "�������� ����� ������ ����? [1/0] ";
	cin >> x; cin.get(); x2 = static_cast<bool>(x);
	cout << "��������� �����? [1/0] ";
	cin >> x; cin.get(); x3 = static_cast<bool>(x);
	cout << "��������� ��������� �������? [1/0] "; 
	cin >> x; cin.get(); x4 = static_cast<bool>(x);

	Bruteforce *brfs = new Bruteforce(pass, x1, x2, x3,x4,pass.length());
	cout << "\n!!! ������� ������ ������ ��� ������ � ����������� ������� !!!\n";
	cout << "��������� ������� ������ - �� 3 ������� \n(�� 70300 ������� ��� 52 ����)\n�������� Enter ��� ������� ������\n";
	_getch();
	brfs->TryToCatchPass();

	_getch();
	return 0;
}