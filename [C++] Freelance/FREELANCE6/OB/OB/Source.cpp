#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string>

using namespace std;

int HexToInt(const char* str)
{
	int r;
	// ������� ���������� hex - int
	// x - hex ������
	sscanf_s(str, "%x", &r); 
	return r;
}
// �������� �� ������� hex �����
bool ishex(string str) {
	string hex = "123456789abcdef";
	for (int i= 0; i < str.length(); i++) {
		//����� � ������
		if (hex.find(str[i]) == string::npos) 
			return false;
	} 
	return true;
}
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	while (true) {
		string str; cout << "������ ����� � HEX ������: ";
		getline(cin, str); 
		int num = MININT; 
		
		if (ishex(str)) { 
			// ����� � �������. ����������..
			num = HexToInt(str.c_str());			// ������ ������ �� 5 �� ���� 0
			cout << "����� (OCT) " << num << " " << ((num % 5 == 0) ? "�" : "�� �") << " ������� 5";
		}
		else {
			cout << "����� �� � ��������������";
		} 
		cout << endl<<endl;
	}
}