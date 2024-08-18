#include <iostream>

using namespace std;

class Phone {
private:
	float diag;
	string os;
	static string color;
public:
	Phone() : os("Android") {
		cout << "this is constructor phone" << endl;
		cout << "diag: ";
		cin >> diag;
	//	cout << endl << "color: ";
	//	cin >> color;
	}
	void showInfo() {
		cout << "diag: " << diag << ", " << "OS: " << os << ", " << "color: " << color << endl;
		color = "green";
	}
	static void showColor() {
		cout << "color is " << color << endl;
	}
};
string Phone::color = "blue";

int main() {
	Phone myPhone1, myPhone2;
	Phone::showColor();
	myPhone1.showInfo();
	myPhone2.showInfo();

	return 0;
}