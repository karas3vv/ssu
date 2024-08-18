#include <iostream>
using namespace std;

int main() {
    int mas[5][5];
    setlocale(LC_ALL, "Russian");
    int x;

    int r, c;
    cout << "¬ведите количество строк: ";
    cin >> r;
    cout << "¬ведите количество столбцов: ";
    cin >> c;

    cout << "¬ведите число x: ";
    cin >> x;

    cout << "¬ведите элементы массива: ";
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cout << "mas[" << i << "][" << j << "] = ";
            cin >> mas[i][j];
            if (mas[i][j] < x) {
                mas[i][j] *= 2;
            }
        }
    }
    cout << "»змененный массив: " << endl;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cout << mas[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}