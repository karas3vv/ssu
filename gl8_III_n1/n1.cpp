#include <iostream>

using namespace std;

int member(int memb, int dif, int n) {
    if (n > 0)
        memb = dif + member(memb, dif, n - 1);
    return memb;
}

int summa(int sum, int dif, int n) {
    if (n > 0)
        sum += (n * dif) + summa(sum, dif, n - 1);
    return sum;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int n, dif, first;

    cout << "¬ведите n: ";
    cin >> n;
    cout << "¬ведите d: ";
    cin >> dif;
    cout << "¬ведите первый элемент арифметической прогрессии: ";
    cin >> first;

    cout << n <<"-й элемент прогрессии: " << member(first, dif, n - 1) << endl;
    cout << "—умма " << n << " элементов прогрессии: " << summa(first, dif, n - 1) << endl;

    return 0;
}