#include <iostream>

using namespace std;

int NOD(int a, int b)
{
    while (a != 0 && b != 0) {
        if (a > b) {
            a = a % b;
        }
        else {
            b = b % a;
        }
    }
    return a + b;
}

int main() {
    setlocale(LC_ALL, "Russian");
    double n, m, c, d;
    cout << "Введите n: ";
    cin >> n;
    cout << "Введите m: ";
    cin >> m;

    cout << "Исходная дробь: " << n << "/" << m << endl;
    cout << "НОД чисел n и m: " << NOD(n, m) << endl;

    cout << "1) Сокращенная дробь (числитель и знаменатель сокращены на НОД): " << n / NOD(n, m) << "/" << m / NOD(n, m) << endl;

    cout << "2) НОК (для n и m через НОД): " << (n * m) / NOD(n, m) << endl;

    cout << "Введите c: ";
    cin >> c;
    cout << "Введите d: ";
    cin >> d;

    cout << "3) Значение выражения a/b + c/d (где a = n, b = m): " << ((n / NOD(n, m)) / (m / NOD(n, m))) + ((c / NOD(n, m)) / (d / NOD(n, m))) << endl;


    cout << "4 пункт" << endl;
    int k, nod_;
    cout << "Введите количество чисел: ";
    cin >> k;

    int* arr = new int[k];

    for (int i = 0; i < k; i++) {
        cout << "Введите " << i + 1 << " число: ";
        cin >> arr[i];
    }

    if (k >= 2)
        nod_ = NOD(arr[0], arr[1]);
    else
        nod_ = arr[0];

    for (int i = 2; i < k; i++)
        nod_ = NOD(nod_, arr[i]);
    cout << "4) НОД " << k << " чисел: " << nod_ << endl;

    return 0;
}

