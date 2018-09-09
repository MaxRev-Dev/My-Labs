#pragma once
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string>
#include <sstream>
//EXTERNAL MODULE
#include "mainModule.h"

using namespace std; 

template <typename T>
string Test<T>::ToString(T value) {
	return to_string(value);
}
template <typename T>
int Test<T>::ToInt() {
	return stoi(value);
}
template <typename T>
double Test<T>::ToDouble() {
	return stod(value);
}
template <typename T>
float Test<T>::ToFloat() {
	return stof(value);
}
template <typename T>
long Test<T>::ToLong() {
	return stol(value);
}
template <typename T>
long long Test<T>::ToLongLong() {
	return stoll(value);
}
template<typename T>
void Test<T>::TestAll() {
	cout << "!!> Test START <!!\n";
	if (CanConvertToNum) {
		cout << "Converted to INT: " << to_string(this->ToInt()) << endl;
		cout << "Converted to DOUBLE: " << to_string(this->ToDouble()) << endl;
		cout << "Converted to FLOAT: " << to_string(this->ToFloat()) << endl;
		cout << "Converted to LONG: " << to_string(this->ToLong()) << endl;
		cout << "Converted to LONG LONG: " << to_string(this->ToLongLong()) << endl;
	}
	else cout << "Value Cannot be converted\n";
	cout << "!!> Test END <!!";
	
}