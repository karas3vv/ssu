#include <iostream>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    int x;
    cout << "¬ведите заданное число: ";
    cin >> x;

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

    int* sum = new int[20];
    int new_size = 0;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            sum[i] += mas[i][j];
        }
        if (sum[i] > x)
            new_size++; // если сумма строки больше х эту строку будем писать в новый массив
    }
}