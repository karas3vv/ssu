#include <iostream>
#include <iomanip>
using namespace std;
void m1() {
	float c;
	setlocale(LC_ALL, "Russian");
	cout << "������� ����: ";
	cin >> c;
	cout << left << setw(20) << "����� � ��������" << setw(20) << "����� � ������" << endl;
	for (int i = 5; i <= 120; i += 5) 
	{
		cout << left << setw(20) << i << setw(20) << c * i << endl;
	}
}

void m2() {
	int i = 5;
	float c;
	setlocale(LC_ALL, "Russian");
	cout << "������� ����: ";
	cin >> c;
	cout << left << setw(20) << "����� � ��������" << setw(20) << "����� � ������" << endl;
	while (i <= 120) 
	{
		cout << left << setw(20) << i << setw(20) << c * i << endl;
		i += 5;
	}
}

void m3() {
	int i = 5;
	float c;
	setlocale(LC_ALL, "Russian");
	cout << "������� ����: ";
	cin >> c;
	cout << left << setw(20) << "����� � ��������" << setw(20) << "����� � ������" << endl;
	do {
		cout << left << setw(20) << i << setw(20) << c * i << endl;
		i += 5;
	}
	while (i <= 120);
}

int main() {
	m1();
	m2();
	m3();
}