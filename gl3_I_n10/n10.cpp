#include <iostream>
#include <cmath>
using namespace std;
int main() {
	double x, y;
	setlocale(LC_ALL, "Russian");
	cout << "x = ";
	cin >> x;
	cout << "y = ";
	cin >> y;
	if (y > -100 && y < -abs(x))
	{
		cout << "��";
	}
	else if (y < -100 || y > -abs(x))
	{
		cout << "���";
	}
	else
	{
		cout << "�� �������";
	}
	return 0;
}