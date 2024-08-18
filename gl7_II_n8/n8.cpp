#include <iostream>
#include <string>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    string str1, str2, txt;

    cout << "¬ведите текст: ";
    getline(cin, txt);

    cout << "¬ведите слово, которое нужно найти: ";
    getline(cin, str1);

    cout << "¬ведите слово, на которое нужно заменить: ";
    getline(cin, str2);

   /* for (size_t i = 0; i < txt.length(); i++) {*/
        size_t first = txt.find(str1, 0);
        while (first != string::npos) {
            txt.replace(first, str1.length(), str2);
            first = txt.find(str1, first + str1.length());
    }
    cout << "»змененный текст: " << endl;
    cout << txt;
    return 0;
}