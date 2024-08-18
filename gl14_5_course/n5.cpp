#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Course {
private:
    string courseName; // �������� �����
    string instructor; // ��� �������������
    int hours; // ���-�� �����
    static int count; // ����������� ���� ��� �������� ���������� ����������� ������

public:
    // ������������
    Course() : courseName(""), instructor(""), hours(0) { // ����������� ��� ����������
        count++; // ����������� ������� �����������
    }

    Course(const string& name, const string& instructor, int hours)
        : courseName(name), instructor(instructor), hours(hours) { // ����������� � �����������
        count++; // ����������� ������� �����������
    }

    // ����������� ����� ��� ��������� ���������� �����������
    static int getCount() {
        return count;
    }

    // ����� ��� ��������� �������� �����
    string getCourseName() const {
        return courseName;
    }

    // Method to get the number of hours
    int getHours() const {
        return hours;
    }

    // ����� ��� ��������� ���������� �����
    void changeHours(int newHours) {
        hours = newHours;
    }

    // ��������� ���������
    bool operator<(const Course& other) const {
        return courseName < other.courseName;
    }

    bool operator>(const Course& other) const {
        return courseName > other.courseName;
    }

    bool operator==(const Course& other) const {
        return courseName == other.courseName;
    }

    // ������ ������ �������� � ����� � �����
    friend ostream& operator<<(ostream& os, const Course& course) {
        os << "Course: " << course.courseName << ", Instructor: " << course.instructor << ", Hours: " << course.hours;
        return os;
    }
};

int Course::count = 0;

// ���������� ��� ���������� ������ �� ��������
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