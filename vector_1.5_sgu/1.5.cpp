#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

double summa(const vector<double>& arr) {
    double sum = 0.0;
    int last_positive_index = -1;

    // ������� ������ ���������� �������������� ��������
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] > 0) {
            last_positive_index = i;
        }
    }

    // ���� ��� ������������� ���������, ���������� 0
    if (last_positive_index == -1) {
        return 0;
    }

    // ������� ����� ��������� �� ���������� ��������������
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

    // ������� ��������� � ����� ������� ����� ���������� �����
    cout << fixed << setprecision(3);
    cout << result << endl;

    return 0;
}
