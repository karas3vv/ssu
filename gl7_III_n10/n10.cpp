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

	cout << "������� �����: ";
	getline(cin, txt);

	while (txt[i]) {
		if (znaki(txt[i])) { //���� �-��� ������� true, ������ ���������� �� ���� ����������
			while (znaki(txt[i])) { //���� ��� ���� ����������
				i++; //��������� ����. ������� 
			}
			count++;
		}
		else
			i++; //���� znaki == false, �� ��������� ����. �������
	}

	string* words = new string[count]; //��� �������� ��� �����, ������� ���� � txt

	i = 0;
	int iwords = 0; //������ ��� �������, ��� �������� �����

	string wrd;
	while (txt[i]) {
		if (znaki(txt[i])) { //���� ���� ����������, �� 
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

	int k = 0; //������� ���� � ������

	//����� ��������������� ����
	for (int i = 0; i < count; i++) {
		wrd = words[i]; //� wrd ����������� ������� ������� words
		for (int j = 0; j < count; j++) {
			if (wrd == words[j]) //�������� � ������ ��������� �������
				k++; //���� ������� ��� ����������
		}
		if (k == 1) 
			cout << words[i] << endl;
		k = 0;
	}
	cout << endl;
	return 0;
}