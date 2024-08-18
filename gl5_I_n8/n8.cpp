#include <iostream>
#include <cmath>
using namespace std;
int main() {
	double n, s = cos(1);
	cout << "n = ";
	cin >> n;
	for (int i = 2; i <= n; ++i) {
		s += pow(-1, i + 1) * cos(i);
	}
	cout << "S = " << s;
	return 0;
}