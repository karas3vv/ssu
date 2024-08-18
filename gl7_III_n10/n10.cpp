#include <iostream>
#include <string>

using namespace std;

bool znaki(char zn) {
	if (zn == ' ' || zn == ',' || zn == '.')
		return true;
	else
		return false;
}

int main() {
	setlocale(LC_ALL, "Russian");
	string txt;
	int i = 0, count = 0;

	cout << "¬ведите текст: ";
	getline(cin, txt);

	while (txt[i]) {
		if (znaki(txt[i])) { //если ф-ци€ вернула true, значит наткнулись на знак препинани€
			while (znaki(txt[i])) { //пока еще знак препинани€
				i++; //провер€ем след. элемент 
			}
			count++;
		}
		else
			i++; //если znaki == false, то провер€ем след. элемент
	}

	string* words = new string[count]; //тут хран€тс€ все слова, которые есть в txt

	i = 0;
	int iwords = 0; //индекс дл€ массива, где хран€тс€ слова

	string wrd;
	while (txt[i]) {
		if (znaki(txt[i])) { //если знак препинани€, то 
			while (znaki(txt[i])) {
				i++;
			}
			words[iwords] = wrd;
			iwords++;
			wrd.clear();
			wrd += txt[i];
		}
		else {
			wrd += txt[i];
		}
		if (i < txt.length())
			i++;
		else
			break;
	}

	int k = 0; //счетчик слов в тексте

	//поиск неповтор€ющихс€ слов
	for (int i = 0; i < count; i++) {
		wrd = words[i]; //в wrd присваиваем элемент массива words
		for (int j = 0; j < count; j++) {
			if (wrd == words[j]) //повер€ем с каждым элементом массива
				k++; //увел счетчик при повторении
		}
		if (k == 1) 
			cout << words[i] << endl;
		k = 0;
	}
	cout << endl;
	return 0;
}