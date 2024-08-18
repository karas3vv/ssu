#include <iostream>
using namespace std;

int main() {
	int n, maxn = 0, imax = 0;
	setlocale(LC_ALL, "Russian");
	cout << "Введите n (кол-во элементов): ";
	cin >> n;
	int* mas = new int[n];
	cout << "Введите элементы массива: " << endl;
	for (int i = 0; i < n; ++i) {
		cout << "mas[" << i << "] = ";
		cin >> mas[i];
		if (mas[i] > maxn) {
			maxn = mas[i];
			imax += 1;
		}
	}
	cout << "Номер первого максимального элемента: " << imax;
	return 0;
}