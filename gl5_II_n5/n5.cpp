#include <iostream>
#include <cmath>

using namespace std;

int main() {
	unsigned n;
	double x, a, s = 0;
	setlocale(LC_ALL, "Russian");
	cout << "¬ведите x: ";
	cin >> x;
	a = x;
	cout << "¬ведите n: ";
	cin >> n;
	s += a;
	for (unsigned i = 2; i <= n; ++i) {
		a *= -pow(x, 2) / ((2 * i - 1) * (2 * i - 2));
		s += a;
	}
	cout << "S = " << s;
	return 0;
}