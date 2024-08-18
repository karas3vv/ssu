#include <fstream>
#include <map>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

int main() {
	string x;
	int i = 1;
	map <string, pair <int, int>> all;

	while (in.peek() != EOF) {
		in >> x;
		if (!(x.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"))) {
			if (all.find(x) == all.end()) {
				all[x] = make_pair(i, i);
			}
			else {
				all[x].second = i;
			}
		}
		++i;
	}
	in.close();

	for (auto it = all.begin(); it != all.end(); it++) {
		out << "Number: " << it->first << endl << "First occurrence: " << it->second.first << ", Last occurrence : "
			<< it->second.second << endl << endl;
	}

	out.close();

	return 0;
}