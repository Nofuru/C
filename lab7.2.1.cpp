#include <iostream>
#include <math.h>
using namespace std;
class complex {
private:
	int re, im;
public:
	complex() {
		re = 0;
		im = 0;
	}
	complex(int re) {
		this->re = re;
		im = 0;
	}
	complex(int re, int im) {
		this->re = re;
		this->im = im;
	}

	complex operator+(const complex& other) {
		complex z1;
		z1.re = this->re + other.re;
		z1.im = this->im + other.im;
		return z1;
	}

	complex operator-(const complex& other) {
		complex z1;
		z1.re = this->re - other.re;
		z1.im = this->im - other.im;
		return z1;
	}
	friend ostream& operator<<(ostream&, complex&);
	friend istream& operator>>(istream&, complex&);
};

ostream& operator<<(ostream& os, complex& complex)
{
	if (complex.im < 0) {
		os << complex.re << " - " << abs(complex.im) << "i";
		return os;
	}
	else if (complex.im == 0) {
		os << complex.re << " + i";
		return os;
	}
	else {
		os << complex.re << " + " << complex.im << "i";
		return os;
	}
}

istream& operator>>(istream& os, complex& complex)
{
	os >> complex.re >> complex.im;
	return os;
}

int main()
{
	setlocale(LC_ALL, "rus");

	complex a(12, 34);
	complex b(24, 68);
	complex z1 = a + b;
	complex z2 = b - a;
	complex z3 = a - b;
	cout << z1 << endl << z2 << endl << z3 << endl;

}
