#include <iostream>
#include <fstream>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");

	ofstream out("output.dat", ios::binary);

	int n;
	cout << "������� ���������� ������������ �����: ";
	cin >> n;
	int a, b;
	cout << "������� ������ ���������: ";
	cin >> a;
	cout << "������� ����� ���������: ";
	cin >> b;

	double x;
	cout << "������� ������������ �����: ";
	for (int i = 0; i < n; i++) {
		cin >> x;
		out.write((char*)&x, sizeof(double));
	}

	out.close();

	ifstream in("output.dat", ios::binary);

	cout << "����� ��� ���������: ";
	for (int i = 0; i < n; i++) {
		in.read((char*)&x, sizeof(double));
		if ((x < a) || (x > b)) {
			cout << x << " ";
		}
	}

	in.close();
	return 0;
}