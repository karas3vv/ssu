#include <iostream>

using namespace std;

//����
template <typename X>
X** in(int r, int c) {
	cout << "������� " << r * c << " ��������� �������:" << endl;
	X** arr = new X* [r];
	for (int i = 0; i < r; ++i) {
		arr[i] = new X[c];
		for (int j = 0; j < c; ++j) {
			cout << "arr[" << i << "][" << j << "] = ";
			cin >> arr[i][j];
		}
	}
	return arr;
}

//�����
template <typename X>
void out(X** arr, int r, int c) {
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

//���������
template <typename X> 
X average(X** arr, int r, int c) {
	double s = 0;
	int k = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (arr[i][j] < 0) {
				s += arr[i][j];
				k++;
			}
		}
	}
	return s / k;
}

int main() {
	setlocale(LC_ALL, "Russian");
	
	//������������� ������
	int Ir, Ic;
	cout << "������� ���������� ����� (��): ";
	cin >> Ir;
	cout << "������� ���������� �������� (��): ";
	cin >> Ic;

	int** Imas = in<int>(Ir, Ic);

	cout << "�������� ������������� ������:" << endl;
	out(Imas, Ir, Ic);
	cout << "������� �������� ������������� ���������: ";
	cout << average(Imas, Ir, Ic) << endl;

	//������������ ������
	int Dr, Dc;
	cout << "������� ���������� ����� (��): ";
	cin >> Dr;
	cout << "������� ���������� �������� (��): ";
	cin >> Dc;

	double** Dmas = in<double>(Dr, Dc);

	cout << "�������� ������������ ������:" << endl;
	out(Dmas, Dr, Dc);
	cout << "������� �������� ������������� ���������: ";
	cout << average(Dmas, Dr, Dc) << endl;

	return 0;
}