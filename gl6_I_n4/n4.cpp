#include <iostream>
#include <cmath>
using namespace std;
int main() {
	int n;
	cout << "n = ";
	cin >> n;
	//int mas[10] = { -1, -3, -4, 6, -9, 1, -8, -15, 0, -7 };
	int mas[6] = { -2, -5, -31, 4, 9, 13 };
	for (int i = 0; i < n; ++i) {
		if ((mas[i] % 3 != 0) && (mas[i] < 0)) {
			mas[i] = abs(mas[i]);
		}
		cout << mas[i] << " ";
	}
	return 0;
}

