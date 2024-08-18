#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");

	int n;
	cout << "������� ���������� ���������: ";
	cin >> n;

	vector<int> seq(n);

	cout << "������� �������� ������������������: ";
	for (int i = 0; i < n; i++)
		cin >> seq[i];

	int x;
	cout << "������� ����� x: ";
	cin >> x;

	int min_value = *std::min_element(seq.begin(), seq.end());

	// �������� ��� ����������� ��������
	replace_if(seq.begin(), seq.end(), [min_value](int val) { 
		return val == min_value; 
	}, x);

    // ������� ���������
	cout << "���������: " << endl;
    for (int i : seq) {
        cout << i << " ";
    }

    return 0;
}