#include <iostream>
using namespace std;
void vstavka(int* mas, int& size, int newValue) {
	int newSize = size; //����� ������ ������� ����� �������
	for (int i = 0; i < newSize - 1; i++) {
		if (mas[i] * mas[i + 1] < 0) {
			newSize += 1; //����. ������ ����� �������
			for (int j = newSize - 1; j > i + 1; j--) {
				mas[j] = mas[j - 1]; //����� ��������� ������, ����� �������� ����� �������
			}
			mas[i + 1] = newValue;
		}
	}
	size = newSize; //���. ����� ������ �������
}

int main() {
	int size, newValue;
	setlocale(LC_ALL, "Russian");
	cout << "������� ����� ������� ��� �������: ";
	cin >> newValue;

	cout << "������� ������ �������: ";
	cin >> size;

	int* numbers = new int[2 * size];

	cout << "������� �������� �������: " << endl;
	for (int i = 0; i < size; i++) {
		cout << "numbers[" << i << "] = ";
		cin >> numbers[i];
	}

	vstavka(numbers, size, newValue);

	cout << "������ ����� ������� ����� ���������: " << endl;
	for (int i = 0; i < size; i++) {
		cout << numbers[i] << "\t";
	}
	return 0;
}

