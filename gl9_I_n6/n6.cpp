#include <iostream>
#include <fstream>
#include <string>


using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	ifstream in;
	char ch;
	long double count = 0, mins = numeric_limits<double>::max();
	int string_number = 1;
	int min_string_number = 1;

	in.open("input.txt");
	while (in.peek() != EOF) {
		in.get(ch);
		if (ch == '\n') {
			if (count < mins) {
				mins = count;
				min_string_number = string_number;
			}
			count = 0;
			string_number++;
		}
		else 
			count++;
	}

	cout << "Номер самой короткой строки: " << min_string_number << endl;
	in.close();
	return 0;
}