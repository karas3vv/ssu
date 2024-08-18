#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

double summa(const vector<double>& arr) {
    double sum = 0.0;
    int last_positive_index = -1;

    // Находим индекс последнего положительного элемента
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] > 0) {
            last_positive_index = i;
        }
    }

    // Если нет положительных элементов, возвращаем 0
    if (last_positive_index == -1) {
        return 0;
    }

    // Считаем сумму элементов до последнего положительного
    for (int i = 0; i < last_positive_index; ++i) {
        sum += arr[i];
    }

    return sum;
}

int main() {
    int n;
    cin >> n;

    vector<double> array(n);
    for (int i = 0; i < n; ++i) {
        cin >> array[i];
    }

    double result = summa(array);

    // Выводим результат с тремя знаками после десятичной точки
    cout << fixed << setprecision(3);
    cout << result << endl;

    return 0;
}
