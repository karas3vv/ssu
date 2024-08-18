#include <iostream>
#include <string>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	string s, zn = "+-";

	cout << "Введите выражение: ";
	getline(cin, s);
	s += '+';

	int summ = 0;

	string::size_type k, pos = 0;
	k = s.find_first_of(zn, pos);

	summ += stoi(s.substr(pos, k - pos));
	pos = k + 1;
	k = s.find_first_of(zn, pos);

	while (k != string::npos) {
		if (s[k - 2] == '+')
			summ += stoi(s.substr(pos, k - pos));
		else
			summ -= stoi(s.substr(pos, k - pos));
		pos = k + 1;
		k = s.find_first_of(zn, pos);
	}

	cout << "Результат выражения: ";
	cout << summ << endl;

	return 0;
}
