#pragma once
#include <iostream>
#include <string>
#include <iomanip>

struct Item {
	std::string
		nick = "",
		course = "",
		group = "";
	int 	gradebook_id,
		fcode,
		dpcode,
		scode,
		mark;
	void SetMark(std::string s) {
		this->mark = atoi(s.c_str());
	}
	void SetBGID(std::string s) {
		this->gradebook_id = atoi(s.c_str());
	}
	void SetFcode(std::string s) {
		this->fcode = atoi(s.c_str());
	}
	void SetDpCode(std::string s) {
		this->dpcode = atoi(s.c_str());
	}
	void SetScode(std::string s) {
		this->scode = atoi(s.c_str());
	}
};
using namespace std;
void header() {
	cout << "|" << "Код факультету"
		<< "|" << "Код спеціальності"
		<< "|" << "Курс"
		<< "|" << "Група"
		<< "|" << "Код дисципліни"
		<< "|" << "Прізвище"
		<< "|" << "Ном. з/к"
		<< "|" << "Оцінка" << "|" << endl;
}
void PrintAll(const vector<Item> v) {
	cout << endl;
	header();
	for (size_t i = 0; i < v.size(); i++) {
		auto  p = v[i];
		cout << " [" << i + 1 << "] " <<
			"|" << setw(5) << p.fcode << setw(5) << "|" << setw(5) <<
			setw(5) << p.scode << setw(5) << "|" << setw(5) <<
			setw(5) << p.course << setw(5) << "|" << setw(5) <<
			setw(10) << p.group << setw(5) << "|" << setw(5) <<
			setw(5) << p.dpcode << setw(5) << "|" << setw(5) <<
			setw(10) << p.nick << setw(5) << "|" << setw(5) <<
			setw(5) << p.gradebook_id << setw(5) << "|" << setw(5) <<
			setw(5) << p.mark << "|" << endl;
	} cout << endl;
}
vector<Item>* ReadFile(string file) {
	vector<Item> *vec = new vector<Item>();
	ifstream ins(file.c_str(), ios::in);
	if (ins.is_open()) {
		char*buff = new char[256]; string trash = "";
		while (!ins.eof()) {
			ins.getline(buff, 256);
			if (buff[0] != '\0') {
				int j = 0;
				Item it;
				string tmp = "";
				while (buff[j] != '|') { // fcode
					tmp += buff[j++];
				}j++;
				it.SetFcode(tmp); tmp = "";

				while (buff[j] != '|') { //spcode
					tmp += buff[j++];
				}j++;
				it.SetScode(tmp); tmp = "";
				while (buff[j] != '|') { //course
					it.course += buff[j++];
				}j++;
				while (buff[j] != '|') {//group
					it.group += buff[j++];
				}j++;
				while (buff[j] != '|') {//dpcode
					tmp += buff[j++];
				}j++;
				it.SetDpCode(tmp); tmp = "";

				while (buff[j] != '|') {//nick
					it.nick += buff[j++];
				}j++;
				while (buff[j] != '|') {//gb_id
					tmp += buff[j++];
				}j++;
				it.SetBGID(tmp); tmp = "";
				while (true) { // mark
					if (buff[j] == '\0') break;
					tmp += buff[j++];
				}
				it.SetMark(tmp);
				vec->push_back(it);
			}
		} ins.close();
		return vec;
	}
	return nullptr;
}
void WriteItems(string file, const vector<Item> v) {
	ofstream of(file, ios::trunc);
	cout << endl << "Відкриваємо файл для запису...";
	for (size_t i = 0; i < v.size(); i++) {
		auto  p = v[i];
		of <<
			p.fcode << "|" <<
			p.scode << "|" <<
			p.course << "|" <<
			p.group << "|" <<
			p.dpcode << "|" <<
			p.nick << "|" <<
			p.gradebook_id << "|" <<
			p.mark << endl;
	}
	cout << endl << "Файл успішно збережено! " << endl;
	of.close();
}