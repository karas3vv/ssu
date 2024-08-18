#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");
	
	string txt;

	while (in.peek() != EOF) {
		getline(in, txt);
		for (int i = 0; i < size(txt); ++i) {
			if (i % 2 == 0) {
				out << txt[i];
			}
		}
		out << '\n';
	}
	in.close();
	out.close();
	return 0;
}