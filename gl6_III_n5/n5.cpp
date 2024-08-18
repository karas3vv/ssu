#include <iostream>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	int r, c;
    cout << "¬ведите количество строк: ";
    cin >> r;
    cout << "¬ведите количество столбцов: ";
    cin >> c;

    int** mas = new int* [r];
    for (int i = 0; i < r; ++i) {
        mas[i] = new int[c];
    }

    cout << "¬ведите " << r * c << " элементов матрицы:" << endl;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cout << "mas[" << i << "][" << j << "] = ";
            cin >> mas[i][j];
        }
    }

    cout << "»сходна€ матрица:" << endl;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << mas[i][j] << " ";
        }
        cout << endl;
    }

    double summ = 0;
    int count = 0;
    for (int i = 0; i < r; i++) {
        for (int j = (r - i); j < c; j++) {
            summ += mas[i][j];
            ++count;
        }
    }

    cout << "—реднее арифметическое элементов под побочной диагональю:" << endl;
    cout << summ / count;

    return 0;
}