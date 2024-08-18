#include <iostream>
#include <cmath>
using namespace std;
double fx(double x) {
	return pow(x, 3) - sin(x);
}
int main() {
	double a, b;
	setlocale(LC_ALL, "Russian");
	cout << "Введите a: ";
	cin >> a;
	cout << "Введите b: ";
	cin >> b;
	if (fx(a) > fx(b)) {
		cout << "Наибольшее значение функции в точке a" << endl;
	}
	if (fx(a) < fx(b)) {
		cout << "Наибольшее значение функции в точке b" << endl;
	}
	if (fx(a) == fx(b)) {
		cout << "Функции равны" << endl;
	}
	return 0;
}