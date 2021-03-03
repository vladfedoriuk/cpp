#ifndef COMPLEX_H_
#define COMPLEX_H_
#include<cmath>

enum Mode {
	alg, geom
};

class Complex {

private:
	double Im;
	double Re;
	double ang;
	double r;
	double abs;
	Mode mode;
	double modul() { return sqrt(pow(Re, 2) + pow(Im, 2));};
public:
	Complex();
	Complex(double Re, double Im, Mode mode);
	Complex(double Re, double Im);
	~Complex();
	double getRe() {
		return Re;
	};
	double getIm() {
		return Im;
	};
	Complex operator+(const Complex &a);
	friend Complex operator+(const Complex &a, const Complex &b);
	Complex operator-(const Complex &a);
	friend Complex operator-(const Complex &a, const Complex &b);
	Complex operator*(double n);
	friend Complex operator*(const Complex &a, double n);
};
#endif