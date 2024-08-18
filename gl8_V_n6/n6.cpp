#include <iostream>

using namespace std;

//Ввод
template <typename X>
X** in(int r, int c) {
	cout << "Введите " << r * c << " элементов матрицы:" << endl;
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

//Вывод
template <typename X>
void out(X** arr, int r, int c) {
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

//Обработка
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
	
	//Целочисленный массив
	int Ir, Ic;
	cout << "Введите количество строк (ЦМ): ";
	cin >> Ir;
	cout << "Введите количество столбцов (ЦМ): ";
	cin >> Ic;

	int** Imas = in<int>(Ir, Ic);

	cout << "Исходный целочисленный массив:" << endl;
	out(Imas, Ir, Ic);
	cout << "Среднее значение отрицательных элементов: ";
	cout << average(Imas, Ir, Ic) << endl;

	//Вещественный массив
	int Dr, Dc;
	cout << "Введите количество строк (ВМ): ";
	cin >> Dr;
	cout << "Введите количество столбцов (ВМ): ";
	cin >> Dc;

	double** Dmas = in<double>(Dr, Dc);

	cout << "Исходный вещественный массив:" << endl;
	out(Dmas, Dr, Dc);
	cout << "Среднее значение отрицательных элементов: ";
	cout << average(Dmas, Dr, Dc) << endl;

	return 0;
}