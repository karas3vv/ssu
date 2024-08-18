#include <iostream>
#include <cmath>

using namespace std;

int main() {
	double e;
	setlocale(LC_ALL, "Russian");
	cout << "¬ведите e: ";
	cin >> e;
	double c = 4;
	double a = 4.0 / 3, s = 0;
	s += a;
	for(int i = 2; (a >= e) && (i < 1000); ++i) {
		c *= -2;
		a = c / (i * (2 * i + 1));
		s += a;
	}
	cout << "S = " << s;
	return 0;
}