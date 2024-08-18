#include <iostream>
#include <cmath>

using namespace std;

int main() {
	double x, y;
	cin >> x >> y;
	if (y <= 3 && y >= abs(x)) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}
	return 0;
}