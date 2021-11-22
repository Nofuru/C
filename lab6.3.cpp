#include <iostream>
const double pi = 3.141592653589793;
using namespace std;

class Figure {
public:
	virtual double area() = 0;

	virtual void show() = 0;
};

class Circle : public Figure {
protected:
	double r, s;
public:
	Circle(double v_r) {

		if (v_r <= 0) {
			throw "Указанный радиус меньше либо равен 0";
		}
		r = v_r;
		s = 0.0;
	}

	double area() override {
		s = pi * (r * r);
		return s;
	}

	void show() override {
		cout << "Circle, "<< r << ", " << area() << endl;
	}

	double* getadressr() {
		return &r;
	}

	double* getadress_s() {
		s = pi * (r * r);
		return &s;
	}
};

class Rectangle : public Figure {
protected:
	double a, b, s;
public:
	Rectangle(double v_a)
	{
		a = v_a;
		b = 0;
		s = 0;
	}

	Rectangle(double v_a, double v_b)
	{
		a = v_a;
		b = v_b;
		s = 0;
	}
	double *getadressa() {
		return &a;
	}
	double *getadressb() {
		if (b > 0) {
			return &b;
		}
		else {
			return &a;
		}
	}

	double area() override {
		if (b > 0) {
			s = a * b;
			return s;
		}
		else {
			s = a * a;
			return s;
		}
	}

	double *getadress_s() {
		if (b > 0) {
			s = a * b;
			return &s;
		}
		else {
			s = a * a;
			return &s;
		}
	}

	void show() override {
		if (b <= 0) {
			cout << "Rectangle, "<< a << ", " << area() << endl;
		}
		else {
			cout << "Rectangle, " << a << ", " << b << ", " << area() << endl;
		}
		
	}
};


int main()
{
	setlocale(LC_ALL, "rus");

	Circle circle(4);

	Rectangle rectangle(3);
	Rectangle rectangle1(3, 5);

	circle.show();
	rectangle.show();
	rectangle1.show();

	// зад. 3 нельзя создать объект абстрактного класса.	

	//зад. 4 не сделал
}