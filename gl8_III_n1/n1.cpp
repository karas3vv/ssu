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

    cout << "������� n: ";
    cin >> n;
    cout << "������� d: ";
    cin >> dif;
    cout << "������� ������ ������� �������������� ����������: ";
    cin >> first;

    cout << n <<"-� ������� ����������: " << member(first, dif, n - 1) << endl;
    cout << "����� " << n << " ��������� ����������: " << summa(first, dif, n - 1) << endl;

    return 0;
}