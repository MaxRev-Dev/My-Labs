#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
	SetConsoleOutputCP(1251);

	ifstream ifs("./test.cpp", ios::in);//³�������� ���� �� �������
	vector<string> data; //������������� ������. 
	//�� ��� ��� �� ����� string[] ����� ��������� � �� �� ����� �� ��� ������
	string pure = "";
	while (!ifs.eof()) { // ���� �� ����� �����
		string str;
		getline(ifs, str); // ������ �����
		if (str.find("/*") != string::npos) {//������ � ����� ������� ���������
			string comment = "";
			comment += str += "\n";

			while (!ifs.eof()) {	// ������ ��������
				getline(ifs, str);
				if (str.find("*/") != string::npos) { //���� �������� ����� �������
					comment += str += "\n";
					data.push_back(comment);	//ʳ���� ���������.
					// ������ ������� � �����(������) 
					break; //����������� �� ���������� ������� �����
				}
				comment += str += "\n";
				// ������ ���� � �����(������) 
			}

		}
		else {
			pure += str += "\n";
		}
	}
	ifs.close();//��������� ����

	ofstream ofs("./test.cpp", ios::trunc);
	ofs << pure;// �������� ������ ��� ��� ���������
	ofs.close();

	cout << "���� ��������� � ������������. �������� ��������..";
	if (data.capacity() == 0)cout << "\n��������� �� ��������\n";
	else {
		cout << ">> start" << endl;
		for (int i = 0; i < data.capacity(); i++) {
			cout << "��������: " << i + 1 << endl << data.at(i) << endl << endl;
		}
		cout << ">> end" << endl;
	}
	_getch();
	return 0;
}