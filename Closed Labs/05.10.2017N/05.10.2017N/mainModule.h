#pragma once
//GLOBAL MODULE
using namespace std;
template <typename T>
class Test {
private:
	bool CanConvertToNum;
	T value;
public:
	void SetValue(T _value) {
		value = _value;
		try {
			int num;
			if (!(istringstream(value) >> num)) 
				CanConvertToNum = false;
			else CanConvertToNum = true;
		}
		catch (exception) {
			CanConvertToNum = false;
		}
	};
	string Test<T>::ToString(T);
	int Test<T>::ToInt();
	double Test<T>::ToDouble();
	float Test<T>::ToFloat();
	long Test<T>::ToLong();
	long long Test<T>::ToLongLong();
	void Test<T>::TestAll();
};