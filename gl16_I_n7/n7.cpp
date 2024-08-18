//#include <iostream>
//#include <fstream>
//#include <string>
//#include <list>
//
//using namespace std;
//
//class Stack {
//	struct Element {
//		string inf;
//		Element* next;
//		Element(string x, Element* p) : inf(x), next(p) {}
//	};
//	Element* head;
//public:
//	Stack() : head(0) {}
//	bool Empty() {
//		return (head == 0);
//	}
//
//	string Pop() {
//		if (Empty()) {
//			return 0;
//		}
//		else {
//			Element* r = head;
//			string i = r->inf;
//			head = r->next;
//			delete r;
//			return i;
//		}
//	}
//
//	void Push(string data) {
//		head = new Element(data, head);
//	}
//
//	string Top() {
//		if (Empty()) {
//			return 0;
//		}
//		else {
//			return head->inf;
//		}
//	}
//};
//
//void replaceDuplicatesWithOne(Stack& stack, const string& value) {
//    if (!stack.Empty() && stack.Top() == value) {
//        // если верхний элемент стека совпадает с текущим значением, это означает, что текущее значение является дубликатом предыдущего значения.
//        // В этом случае пропускаем добавление текущего значения в стек
//        return;
//    }
//    // Иначе добавляем текущее значение в стек.
//    stack.Push(value);
//}
//
//void replaceDuplicates(list<int>& myList) {
//    Stack stack;
//    for (int value : myList) {
//        // преобразуем целое число в строку перед добавлением в стек
//        replaceDuplicatesWithOne(stack, to_string(value));
//    }
//    myList.clear();
//    // извлекаем все элементы из стека и преобразуем их обратно в целые числа, добавляя в начало списка
//    while (!stack.Empty()) {
//        myList.push_front(stoi(stack.Pop()));
//    }
//}
//
//int main() {
//    ifstream in("input.txt");
//
//    list<int> myList;
//    int num;
//    while (in >> num) {
//        myList.push_back(num);
//    }
//    in.close();
//
//    replaceDuplicates(myList);
//
//    ofstream out("output.txt");
//
//    for (int val : myList) {
//        out << val << " ";
//    }
//    out.close();
//
//    cout << "Duplicates replaced and written to output.txt" << endl;
//
//    return 0;
//}

#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <algorithm>

using namespace std;


class QueueException {
private:
	string s;
public:
	QueueException(string msg) : s(msg) {}
	string what() {
		return s;
	}
};

template <class Item>
class Queue {
	struct Elem {
		Item inf;
		Elem* next;
		Elem(Item x) : inf(x), next(0) {}
	};
	Elem* head, * tail;
public:
	Queue() : head(0), tail(0) {}
	bool Empty() {
		return (head == 0);
	}
	Item Get() {
		if (Empty()) {
			throw QueueException("Queue Exception! Get - queue empty!");
		}
		else {
			Elem* t = head;
			Item i = t->inf;
			head = t->next;
			if (head == NULL) {
				tail = NULL;
			}
			delete t;
			return i;
		}
	}
	void Put(Item data) {
		Elem* t = tail;
		tail = new Elem(data);
		if (!head) {
			head = tail;
		}
		else {
			t->next = tail;
		}
	}
};

 //Функция для замены последовательностей повторяющихся элементов на один элемент
void compressQueue(Queue<int>& queue) {
	if (queue.Empty())
		return;

	Queue<int> compressedQueue;
	int currentElement = queue.Get();
	compressedQueue.Put(currentElement);

	while (!queue.Empty()) {
		int element = queue.Get();
		if (element != currentElement) {
			compressedQueue.Put(element);
			currentElement = element;
		}
	}

	queue = compressedQueue;
}

int main() {
	Queue<int> queue;

	ifstream inputFile("input.txt");

	int number;
	while (inputFile >> number) {
		queue.Put(number);
	}
	inputFile.close();

	 //Применение замены повторяющихся элементов
	compressQueue(queue);

	ofstream outputFile("output.txt");

	while (!queue.Empty()) {
		outputFile << queue.Get() << " ";
	}
	outputFile.close();

	cout << "Duplicates replaced and written to output.txt" << endl;
	return 0;
}