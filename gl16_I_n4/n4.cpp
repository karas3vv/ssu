//#include <iostream>
//#include <fstream>
//#include <vector>
//#include <stack>
//#include <algorithm>
//
//using namespace std;
//
//// Функция для подсчёта слов, начинающихся с определённой буквы
//int countWords(const vector<string>& words, char letter) {
//    int count = 0;
//    for (const string& word : words) {
//        if (word.front() == letter)
//            count++;
//    }
//    return count;
//}
//
//int main() {
//    ifstream in("input.txt"); 
//
//    vector<string> words;
//    string word;
//    while (in >> word) {
//        words.push_back(word);
//    }
//    in.close();
//
//    char targetLetter;
//    cout << "Enter the letter to count words starting with: ";
//    cin >> targetLetter;
//
//    int count = countWords(words, targetLetter);
//    cout << "Number of words starting with '" << targetLetter << "': " << count << endl;
//
//    // Стек для хранения слов, начинающихся с данной буквы
//    stack<string> wordStack;
//    for (auto it = words.begin(); it != words.end();) {
//        if ((*it)[0] == targetLetter) {
//            wordStack.push(*it);
//            it = words.erase(it); // Удаляем слово из исходного списка
//        }
//        else {
//            ++it;
//        }
//    }
//
//    // Выводим слова, начинающиеся с данной буквы
//    cout << "Words starting with '" << targetLetter << "':" << endl;
//    while (!wordStack.empty()) {
//        cout << wordStack.top() << endl;
//        wordStack.pop();
//    }
//
//    // Сохраняем обновленный список слов в файл
//    ofstream outputFile("updated_words.txt");
//
//    for (const string& w : words) {
//        outputFile << w << endl;
//    }
//    outputFile.close();
//
//    cout << "Updated word list saved to 'updated_words.txt'." << endl;
//
//    return 0;
//}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//#include <iostream>
//#include <fstream>
//#include <vector>
//#include <queue>
//#include <algorithm>
//
//using namespace std;
//
//// Функция для подсчёта слов, начинающихся с определённой буквы
//int countWords(const vector<string>& words, char letter) {
//    int count = 0;
//    for (const string& word : words) {
//        if (word.front() == letter)
//            count++;
//    }
//    return count;
//}
//
//int main() {
//    ifstream in("input.txt"); 
//
//    vector<string> words;
//    string word;
//    while (in >> word) {
//        words.push_back(word);
//    }
//    in.close();
//
//    char targetLetter;
//    cout << "Enter the letter to count words starting with: ";
//    cin >> targetLetter;
//
//    int count = countWords(words, targetLetter);
//    cout << "Number of words starting with '" << targetLetter << "': " << count << endl;
//
//    // Очередь для хранения слов, начинающихся с данной буквы
//    queue<string> wordQueue;
//    for (auto it = words.begin(); it != words.end();) {
//        if ((*it)[0] == targetLetter) {
//            wordQueue.push(*it);
//            it = words.erase(it); // Удаляем слово из исходного списка
//        }
//        else {
//            ++it;
//        }
//    }
//
//    // Выводим слова, начинающиеся с данной буквы
//    cout << "Words starting with '" << targetLetter << "':" << endl;
//    while (!wordQueue.empty()) {
//        cout << wordQueue.front() << endl;
//        wordQueue.pop();
//    }
//
//    // Сохраняем обновленный список слов в файл
//    ofstream outputFile("updated_words.txt");
//
//    for (const string& w : words) {
//        outputFile << w << endl;
//    }
//    outputFile.close();
//
//    cout << "Updated word list saved to 'updated_words.txt'." << endl;
//
//    return 0;
//}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <list>
#include <algorithm>

using namespace std;

// Функция для подсчёта слов, начинающихся с определённой буквы
int countWords(const list<string>& words, char letter) {
    int count = 0;
    for (const string& word : words) {
        if (word.front() == letter)
            count++;
    }
    return count;
}

int main() {
    ifstream in("input.txt");

    list<string> words;
    string word;
    while (in >> word) {
        words.push_back(word);
    }
    in.close();

    char targetLetter;
    cout << "Enter the letter to count words starting with: ";
    cin >> targetLetter;

    int count = countWords(words, targetLetter);
    cout << "Number of words starting with '" << targetLetter << "': " << count << endl;

    // Список для хранения слов, начинающихся с данной буквы
    list<string> startingWithLetter;
    auto it = words.begin();
    while (it != words.end()) {
        if ((*it)[0] == targetLetter) {
            startingWithLetter.push_back(*it);
            it = words.erase(it); // Удаляем слово из исходного списка
        } else {
            ++it;
        }
    }

    // Выводим слова, начинающиеся с данной буквы
    cout << "Words starting with '" << targetLetter << "':" << endl;
    for (const auto& word : startingWithLetter) {
        cout << word << endl;
    }

    // Сохраняем обновленный список слов в файл
    ofstream out("updated_words.txt");

    for (const auto& w : words) {
        out << w << endl;
    }
    out.close();

    cout << "Updated word list saved to 'updated_words.txt'." << endl;

    return 0;
}