#include"complex.h"

Complex::Complex() {
	Im = Re = 0;
	abs=modul();
	mode = alg;
}
Complex::Complex(double Re, double Im) {
	this->Re = Re;
	this->Im = Im;
	abs = modul();
	mode = alg;
}
Complex::Complex(double Re, double Im, Mode mode) {
	this->Re = Re;
	this->Im = Im;
	abs = modul();
	this->mode = mode;
}
Complex::~Complex() {

}

Complex Complex::operator+(const Complex &a) {
	return Complex(Re + a.Re, Im + a.Im);
}
Complex operator+(const Complex &a, const Complex &b) {
	return Complex(a.Re + b.Re, a.Im + b.Im);
}
Complex Complex::operator-(const Complex &a) {
	return Complex(Re - a.Re, Im - a.Im);
}
Complex operator-(const Complex &a, const Complex &b) {
	return Complex(a.Re - b.Re, a.Im - b.Im);
}
Complex Complex::operator*(double n) {
	return Complex(Re*n, Im*n);
}
Complex operator*(const Complex &a, double n) {
	return a*n;
}