#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<stack<int>> stacks(N); // ������� ������ �� N ������

    vector<int> result; // ��������� ���������� �������� TOP � POP

    for (int i = 0; i < K; ++i) {
        string line;
        getline(cin, line);

        int openIndex = line.find('(');
        string operation = line.substr(0, openIndex);

        if (operation == "PUSH") {
            int comaIndex = line.find(',');
            int stackIndex = stoi(line.substr(openIndex + 1, comaIndex));
            int value = stoi(line.substr(comaIndex + 1, line.size() - 1));
            
            stacks[stackIndex - 1].push(value);
        }

        if (operation == "TOP") {
            int stackIndex = stoi(line.substr(openIndex + 1, line.size() - 1));
            if (!stacks[stackIndex - 1].empty()) {
                result.push_back(stacks[stackIndex - 1].top());
            }
        }

        if (operation == "POP") {
            int stackIndex = stoi(line.substr(openIndex + 1, line.size() - 1));
            if (!stacks[stackIndex - 1].empty()) {
                result.push_back(stacks[stackIndex - 1].top());
                stacks[stackIndex - 1].pop();
            }
        }
    }

    // ������� ���������� �������� TOP � POP
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
