#include <iostream>
using namespace std;

int main() {
	int n, maxn = 0, imax = 0;
	setlocale(LC_ALL, "Russian");
	cout << "������� n (���-�� ���������): ";
	cin >> n;
	int* mas = new int[n];
	cout << "������� �������� �������: " << endl;
	for (int i = 0; i < n; ++i) {
		cout << "mas[" << i << "] = ";
		cin >> mas[i];
		if (mas[i] > maxn) {
			maxn = mas[i];
			imax += 1;
		}
	}
	cout << "����� ������� ������������� ��������: " << imax;
	return 0;
}