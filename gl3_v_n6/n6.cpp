#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double fx(double x) {
	return log(4 - pow(x, 2));
}
int main() {
	double a, b, h;
	setlocale(LC_ALL, "Russian");
	cout << "������� a: ";
	cin >> a;
	cout << "������� b: ";
	cin >> b;
	cout << "������� ��� h: ";
	cin >> h;
	for (double i = a; i <= b; i += h)
		if ((- 2 < i) and (i < 2)) {
			cout << "f(" << i << ")" << setw(20) << fx(i) << endl;
		}
		else {
			cout << "f(" << i << ")" << setw(20) << "�� ����������" << endl;
		}
	return 0;
}
