#include <iostream>
#include <string>

using namespace std;

class ZeroDenominator : public exception {
public:
	ZeroDenominator(const string& msg) : msg(msg) {}

	const char* what() const override {
		return msg.c_str();
	}
private:
	string msg;
};

class Rational {
private:
	int numerator;
	int denominator;
	static unsigned count;
public:
	Rational(int numerator, int denominator) :
		numerator(numerator), denominator(denominator) {
		if (denominator == 0) {
			throw ZeroDenominator("Denominator is 0");
		}
	}

	Rational() : numerator(1), 
};