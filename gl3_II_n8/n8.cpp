#include <iostream>
using namespace std;
int main() {
	int m;
	setlocale(LC_ALL, "Russian");
	cout << "����������� ������: ";
	cin >> m;
	if (m >= 0 && m <= 49)
		m = 0;
	else if (m >= 50 && m <= 69)
		m = 1;
	else if (m >= 70 && m <= 89)
		m = 2;
	else if (m >= 90 && m <= 100)
		m = 3;

	switch (m)
	{
	case 0:
		cout << "�������������������"; 
		break;
	case 1:
		cout << "�����������������";
		break;
	case 2:
		cout << "������";
		break;
	case 3:
		cout << "�������";
		break;
	default:
		cout << "������������ �����";
		break;
	}
	return 0;
}