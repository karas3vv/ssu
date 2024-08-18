#include <iostream>
#include <fstream>
#include <string>
#include <set>

using namespace std;

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    string line;

    while (getline(in, line)) {
        set<char> low;
        set<char> up;

        for (char symb : line) {
            if (!isalpha(symb)) {
                continue;
            }

            if (isupper(symb)) {
                up.insert(symb);
            }
            else {
                low.insert(symb);
            }
        }

        for (char symb : low) {
            up.erase(toupper(symb));
        }

        for (char symb : up) {
            out << symb << ' ';
        }
        out << endl;
    }

    in.close();
    out.close();

    cout << "The answer is written to output.txt" << endl;

    return 0;
}