#include <iostream>
using namespace std;

int main() {
	double b1 = 1, n, b;
	cout.precision(5);
	cout << "n = ";
	cin >> n;
	cout << "b1 = " << b1 << '\n';
	for (int i = 2; i <= n; ++i) {
		b = 0.2 * pow(b1, 4) + 1;
		cout << fixed << "b" << i << " = " << b << '\n';
		b1 = b;
	}
	return 0;
}