#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
double fx(double x);
double a, b;
int main() {
	double a, b, h;
	setlocale(LC_ALL, "Russian");
	cout << "¬ведите a: ";
	cin >> a;
	cout << "¬ведите b: ";
	cin >> b;
	cout << "¬ведите шаг h: ";
	cin >> h;
	for (double i = a; i <= b; i += h)
		if (4 - pow(i, 2) > 0) {
			cout << "f(" << i << ")" << setw(20) << fx(i) << endl;
		}
	return 0;
}
double fx(double x) {
	if (pow(x, 2) - 5 * x < 0) return a + b;
	else if (0 <= pow(x, 2) - 5 * x <= 10) return a - b;
	else if (pow(x, 2) - 5 * x >= 10) return a * b;
}