#include <iostream>
#include <vector>

using namespace std;

void insert(vector<int>& vec, int newEl) {
	int lastPlus = -1;
	for (int i = 0; i < vec.size(); i++) {
		if (vec[i] > 0) {
			lastPlus = i;
		}
	}
	if (lastPlus != -1) {
		vec.insert(vec.begin() + lastPlus + 1, newEl);
	}
	else {
		vec.push_back(newEl);
	}
}

int main() {
	setlocale(LC_ALL, "Russian");

	int n;
	cout << "������� ���������� ���������: ";
	cin >> n;

	vector<int> seq(n);

	cout << "������� �������� ������������������: ";
	for (int i = 0; i < n; i++) {
		cin >> seq[i];
	}

	int newEl;
	cout << "������� ����� ������� ��� �������: ";
	cin >> newEl;

	insert(seq, newEl);

	cout << "���������� ������������������: ";
	for (int num : seq) {
		cout << num << " ";
	}
	cout << endl;

	return 0;
}