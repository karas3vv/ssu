#include <iostream>
using namespace std;
int main() {
	int M, N, c;
	cout << "M = ";
	cin >> M;
	cout << "N = ";
	cin >> N;
	if (M % N == 0) {
		c = M / N;
		cout << c;
	}
	else
		cout << setlocale(LC_ALL, "Russian") << "� �� N ������ �� �������";
	return 0;
}