#include"tablica.h"
#include<iostream>

Tablica::Tablica(): t(NULL), top(0) {

}

Tablica::Tablica(std::size_t n) : size(n), top(0), t(new double[n]) {

}

Tablica::Tablica(Tablica &&source): size(source.get_size()), t(source.t){//move-constructor ( const - x bo nie mozemy zmienic ) ( przenosi zawartosc elementu bez kopiowania
	std::cout << "move-ctr" << std::endl;
	source.size = 0;
    source.t = NULL;
}
double Tablica::get_element(std::size_t i) const {
	return t[i];
}

void Tablica::set_element(std::size_t i, double a) {
	t[i] = a;
}
Tablica::~Tablica() {
	delete[] t;
}
std::size_t Tablica::get_size() const {
	return size;
}


void Tablica::push_back(std::size_t a) {
	(top < size) ? (t[top]=a, top++) :( top = 0, t[top]=a);
}

Tablica::Tablica(const Tablica &a) {
	t = new double[a.size];
	size = a.size;
	top = 0;
		for (std::size_t i=0; i < a.size; i++) {
		push_back(a.get_element(i));
	}
}
Tablica& Tablica::operator=(const Tablica& a) {
	if (this != &a) {
		delete[] t;
		size = a.size;
		t = new double[a.size];
		top = 0;
		for (std::size_t i = 0; i < a.size; i++) {
			push_back(a.get_element(i));
		}
	}
	return *this;
}

Tablica& Tablica::operator=(Tablica&& a) {
	if (this != &a) {
		size = a.get_size();
		delete[] t;

		t = a.t;
		a.size = 0;
		a.t = NULL;	
	}
	return *this;

}

double& Tablica::setGet(std::size_t i) {
	return t[i];
}

 double& Tablica::operator[](std::size_t i) {
	return t[i];
}

double& Tablica::operator[](std::size_t i) const {
	return t[i];
}