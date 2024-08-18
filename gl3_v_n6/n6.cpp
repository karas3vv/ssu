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
	cout << "¬ведите a: ";
	cin >> a;
	cout << "¬ведите b: ";
	cin >> b;
	cout << "¬ведите шаг h: ";
	cin >> h;
	for (double i = a; i <= b; i += h)
		if ((- 2 < i) and (i < 2)) {
			cout << "f(" << i << ")" << setw(20) << fx(i) << endl;
		}
		else {
			cout << "f(" << i << ")" << setw(20) << "не определена" << endl;
		}
	return 0;
}
