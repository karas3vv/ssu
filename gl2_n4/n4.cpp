#include <iostream>
#include <cmath>
using namespace std;
double fx(double x) {
	return pow(x, 3) - sin(x);
}
int main() {
	double a, b;
	setlocale(LC_ALL, "Russian");
	cout << "������� a: ";
	cin >> a;
	cout << "������� b: ";
	cin >> b;
	if (fx(a) > fx(b)) {
		cout << "���������� �������� ������� � ����� a" << endl;
	}
	if (fx(a) < fx(b)) {
		cout << "���������� �������� ������� � ����� b" << endl;
	}
	if (fx(a) == fx(b)) {
		cout << "������� �����" << endl;
	}
	return 0;
}