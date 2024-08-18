#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double f(double x) {
    try {
        if (x == 2)
            throw "не имеет смысла";
    }
    catch (const char* s) {
        throw s;
    }
    return log(fabs(x - 2));
}

int main() {
    setlocale(LC_ALL, "Russian");
    double a, b, h, x, y;

    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    cout << "h = ";
    cin >> h;
    cout << left << setprecision(5);
    cout << setw(10) << "x" << setw(10) << "y" << endl;

    for (x = a; x <= b; x += h) {
        try {// пытаемся выполнить вспомогательную функцию
            y = f(x);
            cout << setw(10) << x << setw(10) << y << endl;
        }
        // обработка исключения, переданного из вспомогательной функции 
        catch (const char* s)
        {
            cout << setw(10) << x << s << endl;
        }
    }

    return 0;
}
