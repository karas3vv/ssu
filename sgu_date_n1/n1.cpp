#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int daysInMonth(int month, int year) {
    switch (month) {
    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
    case 2:
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
            return 29;
        else
            return 28;
    default:
        return 31;
    }
}

struct Date {
    unsigned short day, month, year;
    void input() {
        char temp;
        in >> day >> temp >> month >> temp >> year;
    }
    void output() {
        out << setw(2) << setfill('0') << day << "/" << setw(2) << month << "/" << year << endl;
    }
    void previousDay() {
        if (day == 1) {
            if (month == 1) {
                day = 31;
                month = 12;
                year--;
            }
            else {
                month--;
                day = daysInMonth(month, year);
            }
        }
        else {
            day--;
        }
    }
};

int main() {
    Date dat;
    dat.input();
    dat.previousDay();
    dat.output();

    in.close();
    out.close();
    return 0;
}