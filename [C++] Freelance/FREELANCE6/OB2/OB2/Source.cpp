#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;
 
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int x;
	cout << "Введіть кількість відрізків: ";
	cin >> x;
	int **a = new int*[x]; //виділяємо пам'ять під відрізки
	for (int i = 0; i < x; i++) {
		a[i] = new int[2];
		cout << "Відрізок [1] => точка " << i + 1 << ": ";
		cin >> a[i][0];
		cout << "Відрізок [2] => точка " << i + 1 << ": ";
		cin >> a[i][1];
	}
	
	/* 
	       2|-----|4 MinT
		1|--------------|5
		 MaxB 3|----------|6
		       |--| result 
	*/


	int  minT = MAXINT, maxB = MININT; // беремо протилежне початкове значення
	for (int i = 0; i < x; i++) { 
		if (a[i][0] > maxB) maxB = a[i][0]; //max of bottom
		if (a[i][1] < minT) minT = a[i][1]; //min of top
	}
	if (maxB < minT) {
		cout << "Відрізки перетинаються: А(" << maxB << ") B(" << minT << ")";
	} else cout << "Відрізки НЕ перетинаються";

	_getch();
	return 0;
}