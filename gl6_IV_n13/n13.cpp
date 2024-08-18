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

    int* res = new int[r];
    cout << "¬ведите " << r * c << " элементов матрицы:" << endl;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cout << "mas[" << i << "][" << j << "] = ";
            cin >> mas[i][j];
        }
    }

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (mas[i][j] < 0) {
                res[i] = j;
                break;
            }
            else
                res[i] = -1;
        }
    }
    for (int i = 0; i < r; ++i) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}