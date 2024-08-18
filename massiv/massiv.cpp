#include <iostream>

using namespace std;
void split_string(string s, string del, double* res_out) {
    // Use find function to find 1st position of delimiter.
    int end = s.find(del);
    for (int i = 0; end != -1; ++i) { // Loop until no delimiter is left in the string.
        double res;
        res = atof(s.substr(0, end).c_str());
        cout << res << endl;
        res_out[i] = res;
        s.erase(s.begin(), s.begin() + end + 1);
        end = s.find(del);
    }
}
int main() {
    int n = 4;
    double* a = new double[n];
	string s1 = "11.1 11.2 11.3 11.4";
    split_string(s1, " ", a);
    cout << *a;
    return 0;
}