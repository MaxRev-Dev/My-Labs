#include <iostream>
#include <cmath>
#include <conio.h>
#include <Windows.h>
 
using namespace std;

int main() {
	SetConsoleOutputCP(1251);
	int N; //Ð Ñ”Ð Ñ•Ð Â»Ð Ñ‘Ð¡â€¡Ð ÂµÐ¡ÐƒÐ¡â€šÐ Ð†Ð Ñ• Ð¡â€¡Ð Ñ‘Ð¡ÐƒÐ ÂµÐ Â» 
	cout << "Ð â€™Ð Ð†Ð ÂµÐ Ò‘Ð Ñ‘Ð¡â€šÐ Âµ Ð Ñ”Ð Ñ•Ð Â»Ð Ñ‘Ð¡â€¡Ð ÂµÐ¡ÐƒÐ¡â€šÐ Ð†Ð Ñ• Ð¡â€¡Ð Ñ‘Ð¡ÐƒÐ ÂµÐ Â»: " << endl;
	cin >> N;//Ð Ð†Ð Ð†Ð Ñ•Ð Ò‘Ð Ñ‘Ð Ñ˜ Ð Ñ”Ð Ñ•Ð Â»Ð Ñ‘Ð¡â€¡Ð ÂµÐ¡ÐƒÐ¡â€šÐ Ð†Ð Ñ• Ð¡â€¡Ð Ñ‘Ð¡ÐƒÐ ÂµÐ Â»
	int i;
	int count = 0;//Ð¡ÐƒÐ¡â€¡Ð ÂµÐ¡â€šÐ¡â€¡Ð Ñ‘Ð Ñ” Ð¡â€¡Ð Ñ‘Ð¡ÐƒÐ ÂµÐ Â»
	double sum_sqrt = 0;//Ð¡ÐƒÐ¡Ñ“Ð Ñ˜Ð Ñ˜Ð Â° Ð Ñ”Ð Ñ•Ð¡Ð‚Ð Ð…Ð ÂµÐ â„– Ð Ñ—Ð Ñ•Ð Â»Ð Ñ•Ð Â¶Ð Ñ‘Ð¡â€šÐ ÂµÐ Â»Ð¡ÐŠÐ Ð…Ð¡â€¹Ð¡â€¦ Ð¡â€¡Ð Ñ‘Ð¡ÐƒÐ ÂµÐ Â»
	int multiply = 1;//Ð Ñ•Ð Â±Ð¡â€°Ð ÂµÐ Âµ Ð Ñ—Ð¡Ð‚Ð Ñ•Ð Ñ‘Ð Â·Ð Ð†Ð ÂµÐ Ò‘Ð ÂµÐ Ð…Ð Ñ‘Ð Âµ Ð¡â€¡Ð Ñ‘Ð¡ÐƒÐ ÂµÐ Â»
	while (N > 0) {
		cout << "Ð â€™Ð Ð†Ð ÂµÐ Ò‘Ð Ñ‘Ð¡â€šÐ Âµ Ð¡â€¡Ð Ñ‘Ð¡ÐƒÐ Â»Ð Ñ•: ";
		cin >> i;//Ð Ð†Ð Ð†Ð Ñ•Ð Ò‘Ð Ñ‘Ð Ñ˜ Ð¡â€¡Ð Ñ‘Ð¡ÐƒÐ Â»Ð Ñ•
		if (i > 0) {//Ð ÂµÐ¡ÐƒÐ Â»Ð Ñ‘ Ð¡â€¡Ð Ñ‘Ð¡ÐƒÐ Â»Ð Ñ• > 0
			sum_sqrt += sqrt((double)i);
			count++;
		}
		 multiply *= i;
		N--;
	}
	cout << "Ð Ñ™Ð Ñ•Ð Â»Ð Ñ‘Ð¡â€¡Ð ÂµÐ¡ÐƒÐ¡â€šÐ Ð†Ð Ñ• Ð Ñ—Ð Ñ•Ð Â»Ð Ñ•Ð Â¶Ð Ñ‘Ð¡â€šÐ ÂµÐ Â»Ð¡ÐŠÐ Ð…Ð¡â€¹Ð¡â€¦ Ð¡â€¡Ð Ñ‘Ð¡ÐƒÐ ÂµÐ Â»: " << count << endl;
	cout << "Ð ÐŽÐ¡Ñ“Ð Ñ˜Ð Ñ˜Ð Â° Ð Ñ”Ð Ñ•Ð¡Ð‚Ð Ð…Ð ÂµÐ â„– Ð Ñ—Ð Ñ•Ð Â»Ð Ñ•Ð Â¶Ð Ñ‘Ð¡â€šÐ ÂµÐ Â»Ð¡ÐŠÐ Ð…Ð¡â€¹Ð¡â€¦ Ð¡â€¡Ð Ñ‘Ð¡ÐƒÐ ÂµÐ Â»: " << sum_sqrt << endl;
	cout << "Ð Ñ›Ð Â±Ð¡â€°Ð ÂµÐ Âµ Ð Ñ—Ð¡Ð‚Ð Ñ•Ð Ñ‘Ð Â·Ð Ð†Ð ÂµÐ Ò‘Ð ÂµÐ Ð…Ð Ñ‘Ð Âµ Ð¡â€¡Ð Ñ‘Ð¡ÐƒÐ ÂµÐ Â»: " << multiply<<endl;
	_getch();
	return 0;
}