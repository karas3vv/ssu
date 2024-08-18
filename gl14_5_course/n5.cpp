#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Course {
private:
    string courseName; // название круса
    string instructor; // имя преподавателя
    int hours; // кол-во часов
    static int count; // статическое поле для подсчета количества экземпляров класса

public:
    // конструкторы
    Course() : courseName(""), instructor(""), hours(0) { // конструктор без параметров
        count++; // увеличиваем счетчик экземпляров
    }

    Course(const string& name, const string& instructor, int hours)
        : courseName(name), instructor(instructor), hours(hours) { // конструктор с параметрами
        count++; // увеличиваем счетчик экземпляров
    }

    // статический метод для получения количества экземпляров
    static int getCount() {
        return count;
    }

    // метод для получения названия курса
    string getCourseName() const {
        return courseName;
    }

    // Method to get the number of hours
    int getHours() const {
        return hours;
    }

    // метод для изменения количества часов
    void changeHours(int newHours) {
        hours = newHours;
    }

    // операторы сравнения
    bool operator<(const Course& other) const {
        return courseName < other.courseName;
    }

    bool operator>(const Course& other) const {
        return courseName > other.courseName;
    }

    bool operator==(const Course& other) const {
        return courseName == other.courseName;
    }

    // способ вывода сведений о курсе в поток
    friend ostream& operator<<(ostream& os, const Course& course) {
        os << "Course: " << course.courseName << ", Instructor: " << course.instructor << ", Hours: " << course.hours;
        return os;
    }
};

int Course::count = 0;

// компаратор для сортировки курсов по алфавиту
struct AlphComparator {
    bool operator()(const Course& a, const Course& b) const {
        return a.getCourseName() < b.getCourseName();
    }
};

int main() {
    vector<Course> courses;

    ifstream in("input.txt");

    string courseName, instructor;
    int hours;

    while (in >> courseName >> instructor >> hours) {
        courses.emplace_back(courseName, instructor, hours);
    }

    in.close();

    sort(courses.begin(), courses.end(), AlphComparator());

    ofstream out("output.txt");

    for (const Course& course : courses) {
        out << course << endl;
    }

    out.close();

    return 0;
}