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
    cout << "������� n: ";
    cin >> n;
    cout << "������� m: ";
    cin >> m;

    cout << "�������� �����: " << n << "/" << m << endl;
    cout << "��� ����� n � m: " << NOD(n, m) << endl;

    cout << "1) ����������� ����� (��������� � ����������� ��������� �� ���): " << n / NOD(n, m) << "/" << m / NOD(n, m) << endl;

    cout << "2) ��� (��� n � m ����� ���): " << (n * m) / NOD(n, m) << endl;

    cout << "������� c: ";
    cin >> c;
    cout << "������� d: ";
    cin >> d;

    cout << "3) �������� ��������� a/b + c/d (��� a = n, b = m): " << ((n / NOD(n, m)) / (m / NOD(n, m))) + ((c / NOD(n, m)) / (d / NOD(n, m))) << endl;


    cout << "4 �����" << endl;
    int k, nod_;
    cout << "������� ���������� �����: ";
    cin >> k;

    int* arr = new int[k];

    for (int i = 0; i < k; i++) {
        cout << "������� " << i + 1 << " �����: ";
        cin >> arr[i];
    }

    if (k >= 2)
        nod_ = NOD(arr[0], arr[1]);
    else
        nod_ = arr[0];

    for (int i = 2; i < k; i++)
        nod_ = NOD(nod_, arr[i]);
    cout << "4) ��� " << k << " �����: " << nod_ << endl;

    return 0;
}

