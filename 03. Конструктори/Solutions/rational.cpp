#include <iostream>
#include <stdexcept>
#include <cassert>


class Rational {

private:
	int numerator;
	int denominator;

public:
	// Constructor: it can be called with 0, 1, or 2 arguments!.
	Rational(const int num=0, const int denom=1) {
		numerator = num;
		denominator = denom;

		if (denominator == 0) {
			throw std::invalid_argument("Denominator cannot be 0!");
		} else if (denominator < 0) {
			// Sign information is carried by the numerator,
			// so switch the signs of both `numerator` and `denominator`.
			numerator *= -1;
			denominator *= -1;
		}
	}

	Rational add(const Rational& r) const {
		return Rational{
			numerator * r.denominator + r.numerator * denominator,
			denominator * r.denominator
		};
	}

	Rational sub(const Rational& r) const {
		return Rational{
			numerator * r.denominator - r.numerator * denominator,
			denominator * r.denominator
		};
	}

	Rational mutiply(const Rational& r) const {
		return Rational{
			numerator * r.numerator,
			denominator * r.denominator
		};
	}

	Rational divide(const Rational& r) const {
		return Rational{
			numerator * r.denominator,
			r.numerator * denominator
		};
	}

	void print() const {
		std::cout << numerator << '/' << denominator;
	}
};
