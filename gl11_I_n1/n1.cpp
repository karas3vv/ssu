#include "fstream"
#include "string"
#include "iostream"
#include "iomanip" 

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

struct student {
	string fam;
	string name;
	string secondname;
	int year;
	int mark[5]; // оценки по пяти предметам
	double averagemark = 0; // средняя оценка
	void print();
};

// вывод данных в выходной поток
void student::print() {
	out << setw(12) << left << fam << setw(10) << name << setw(15) << secondname << setw(10) << year;
	for (int i = 0; i < 5; i++)
		out << setw(3) << mark[i];
	out << setw(5) << averagemark << endl;
}

void sort(student* a, int n) {
	student temp;
	int i, j;
	for (i = 2; i < n; i++) {
		j = i;
		while (a[j].averagemark < a[j - 1].averagemark) {
			temp = a[j];
			a[j] = a[j - 1];
			a[j - 1] = temp;
			j--;
		}
	}
}

int main() {
	setlocale(LC_ALL, "Russian");

	int n = 1, m, i;
	student stud[20];
	student temp;

	student fake;
	fake.averagemark = -1;
	stud[0] = fake;

	in >> m;

	while (in.peek() != EOF) {
		in >> stud[n].fam;
		in >> stud[n].name;
		in >> stud[n].secondname;
		in >> stud[n].year;
		for (i = 0; i < 5; i++)
			in >> stud[n].mark[i];
		for (i = 0; i < 5; i++)
			stud[n].averagemark += stud[n].mark[i];
		stud[n].averagemark /= 5.0;
		n++;
	}

	sort(stud, 19);

	for (i = 18; i > 0; i--)
		stud[i].print();

	cout << "Данные отсортированны в файле output.txt" << endl;

	in.close();
	out.close();
	return 0;
}