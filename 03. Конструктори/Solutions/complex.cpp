#include <iostream>
#include <stdexcept>
#include <cassert>
#include <cmath>


class Complex {

private:
	double real;
	double imag;

public:
	// Constructor: can be called with 0, 1, or 2 arguments
	Complex(const double real=0, const double imag=0): real{real}, imag{imag} {}

	Complex add(const Complex& c) const {
		return Complex{real + c.real, imag + c.imag};
	}

	Complex sub(const Complex& c) const {
		return Complex{real - c.real, imag - c.imag};
	}

	Complex mutiply(const Complex& c) const {
		return Complex{
			real * c.real - imag * c.imag,
			real * c.imag + c.real * imag
		};
	}

	Complex divide(const Complex& c) const {
		const double cnorm2 = c.real * c.real + c.imag * c.imag;
		return Complex{
			( real * c.real + imag * c.imag) / cnorm2,
			(-real * c.imag + c.real * imag) / cnorm2
		};
	}

	Complex negate() const {
		return Complex{-real, -imag};
	}

	Complex conjugate() const {
		return Complex{real, -imag};
	}
};
