#include <iostream>
#include <cmath>

using namespace std;

double f(double x, double e, int& n) {
	double s = 1;
	double a;
	double q = ((2 * n + 1) * x * x) / 2 * (2 * n + 3);

	do {
		n++;
		a = pow(x, 2 * n + 1) / ((2 * n + 1) * pow(2, n));
		s += a;
	} 
	while (fabs(a) >= e);
	return s;
}

int main() {
	setlocale(LC_ALL, "Russian");

	double a = 0, b = 0.99, e, h = 0.1;

	cout << "Введите e: ";
	cin >> e;
	int n = 0, i = 1;

	cout << "Num" << '\t' << "Значение х" << '\t' << "Значение функции F(x)" << '\t' << "Количество просуммированных слагаемых n" << endl;
	for (double x = a; x <= b; x += h) {
		cout << i << '\t' << x << '\t' << '\t' << '\t' << f(x, e, n) << '\t' << '\t' << '\t' << n << endl;
		i++;
		n = 0;
	}

	return 0;
}