#include <iostream>
#include <string>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    string str1, str2, txt;

    cout << "������� �����: ";
    getline(cin, txt);

    cout << "������� �����, ������� ����� �����: ";
    getline(cin, str1);

    cout << "������� �����, �� ������� ����� ��������: ";
    getline(cin, str2);

   /* for (size_t i = 0; i < txt.length(); i++) {*/
        size_t first = txt.find(str1, 0);
        while (first != string::npos) {
            txt.replace(first, str1.length(), str2);
            first = txt.find(str1, first + str1.length());
    }
    cout << "���������� �����: " << endl;
    cout << txt;
    return 0;
}