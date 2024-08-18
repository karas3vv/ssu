#include <iostream>
#include <queue>

using namespace std;

void processIn(const string& input, queue<char>& memory, int N) {
    for (char c : input) {
        if (c == '*') {
            if (memory.empty()) {
                cout << "*"; // ���� ������ �����, ������� *
            }
            else {
                cout << memory.front(); // ������� ������� �� ������ ������
                memory.pop(); // ������� ������� �� ������ ������
            }
        }
        else {
            if (memory.size() >= N) {
                memory.pop(); // ����������� ������ ������, ���� ������ ���������
            }
            memory.push(c); // ��������� ����� ������� � ��������� ������
        }
    }
}

int main() {
    int N;
    cin >> N;

    queue<char> memory;

    string input;
    cin >> input;

    processIn(input, memory, N); // ������������ ������� ������

    cout << endl; // ������� ������ ����� ������

    return 0;
}
