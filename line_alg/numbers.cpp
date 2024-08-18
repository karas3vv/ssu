#include <iostream>
#include <cmath>
using namespace std;
int main() {
	int k, d;
	cin >> k;
	cin >> d;
	cout << ((k - 1) % 7 + d) % 7;
	return 0;
}
