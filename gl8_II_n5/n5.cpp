#include <iostream>

using namespace std;

long double ackermann_function(size_t n, size_t m)
{
    if (n == 0)
        return m + 1;

    if (n != 0 && m == 0)
        return ackermann_function(n - 1, 1);

    if (n > 0 && m > 0)
        return ackermann_function(n - 1, ackermann_function(n, m - 1));
}

int main() {
    setlocale(LC_ALL, "Russian");
    long double n, m;
    cout << "¬ведите n: ";
    cin >> n;
    cout << "¬ведите m: ";
    cin >> m;

    cout << ackermann_function(n, m);
    return 0;
}