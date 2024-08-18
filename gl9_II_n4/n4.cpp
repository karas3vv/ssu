#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	ifstream in1 ("input1.txt");
	ifstream in2 ("input2.txt");
	ofstream out ("output.txt");

	string num1, num2;
	int summ = 0;
	while (in1 >> num1 && in2 >> num2) {
		summ = stoi(num1) + stoi(num2);
		out << summ << " ";
	}
	cout << "Результат записан в файл output.txt" << endl;

	in1.close();
	in2.close();
	out.close();
	return 0;
}