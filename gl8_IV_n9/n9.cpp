#include <iostream>
#include <cmath>

using namespace std;

float f(float x) {
	if (x < 1)
		return pow(x * x - 1, 2);
	else if (x > 1)
		return 1 / pow(1 + x, 2);
	else
		return 0;
}

void f(float x, float& y) {
	y = f(x);
}

int main() {
	setlocale(LC_ALL, "Russian");
	float x, y;

	cout << "¬ведите x: ";
	cin >> x;
	y = f(x);

	cout << "f(x) = " << y << endl;

	float y2;

	f(x, y2);
	cout << "f(x, &y) = " << y2 << endl;
	
	return 0;
}