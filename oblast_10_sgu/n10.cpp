#include <iostream>
using namespace std;
int main() {
	double x, y;
	cin >> x >> y;
	if (x >= 1 && x <= 4 && y >= 1 && y <= 5 && y <= - 4.0 / 3.0 * x + 19.0 / 3.0)
	{
		cout << "Yes";
	}
	else
	{
		cout << "No";
	}
	return 0;
}