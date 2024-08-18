#include <iostream>
using namespace std;
void vstavka(int* mas, int& size, int newValue) {
	int newSize = size; //ноывй размер массива после вставки
	for (int i = 0; i < newSize - 1; i++) {
		if (mas[i] * mas[i + 1] < 0) {
			newSize += 1; //увел. массив после вставки
			for (int j = newSize - 1; j > i + 1; j--) {
				mas[j] = mas[j - 1]; //сдвиг элементов вправо, чтобы вставить новый элемент
			}
			mas[i + 1] = newValue;
		}
	}
	size = newSize; //уст. новый размер массива
}

int main() {
	int size, newValue;
	setlocale(LC_ALL, "Russian");
	cout << "Введите новый элемент для вставки: ";
	cin >> newValue;

	cout << "Введите размер массива: ";
	cin >> size;

	int* numbers = new int[2 * size];

	cout << "Введите элементы массива: " << endl;
	for (int i = 0; i < size; i++) {
		cout << "numbers[" << i << "] = ";
		cin >> numbers[i];
	}

	vstavka(numbers, size, newValue);

	cout << "Массив после вставки новых элементов: " << endl;
	for (int i = 0; i < size; i++) {
		cout << numbers[i] << "\t";
	}
	return 0;
}

