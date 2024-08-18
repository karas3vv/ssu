#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    string symb;
    getline(in, symb);

    string text;
    int count = 0;

    while (in.peek() != EOF) {
        getline(in, text);
        string c;
        c = text[0];
        if (symb == c) {
            count++;
        }
    }
    out << count << '\n';

    in.close();
    out.close();
    return 0;
}
