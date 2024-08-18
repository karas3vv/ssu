#include <iostream>
#include <queue>

using namespace std;

void processIn(const string& input, queue<char>& memory, int N) {
    for (char c : input) {
        if (c == '*') {
            if (memory.empty()) {
                cout << "*"; // если пам€ть пуста, выводим *
            }
            else {
                cout << memory.front(); // выводим элемент из первой €чейки
                memory.pop(); // удал€ем элемент из первой €чейки
            }
        }
        else {
            if (memory.size() >= N) {
                memory.pop(); // освобождаем первую €чейку, если пам€ть заполнена
            }
            memory.push(c); // добавл€ем новый элемент в последнюю €чейку
        }
    }
}

int main() {
    int N;
    cin >> N;

    queue<char> memory;

    string input;
    cin >> input;

    processIn(input, memory, N); // обрабатываем входные данные

    cout << endl; // выводим символ новой строки

    return 0;
}
