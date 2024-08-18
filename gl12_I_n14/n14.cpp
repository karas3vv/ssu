#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");

	int n;
	cout << "Введите количество элементов: ";
	cin >> n;

	vector<int> seq(n);

	cout << "Введите элементы последовательности: ";
	for (int i = 0; i < n; i++)
		cin >> seq[i];

	int x;
	cout << "Введите число x: ";
	cin >> x;

	int min_value = *std::min_element(seq.begin(), seq.end());

	// Заменить все минимальные элементы
	replace_if(seq.begin(), seq.end(), [min_value](int val) { 
		return val == min_value; 
	}, x);

    // Вывести результат
	cout << "Результат: " << endl;
    for (int i : seq) {
        cout << i << " ";
    }

    return 0;
}