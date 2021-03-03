#ifndef TABLICA_H_
#define TABLICA_H_
#include<iostream>
#include<cstdint>

class Tablica {
private:
	std::size_t size;
	double *t;
	std::size_t top;
public:
	Tablica();
	Tablica(std::size_t n);
	Tablica(const Tablica &a);//konstruktor kopiujacy;
	Tablica(Tablica &&source);
	double get_element(std::size_t i) const;
	void set_element(std::size_t i, double a);
	~Tablica();
	std::size_t get_size() const;
	void push_back(std::size_t a);
	Tablica& operator=(const Tablica& a);
	Tablica& operator=(Tablica&& a);
	double& setGet(std::size_t i);
    double& operator[](std::size_t i);
	double& operator[](std::size_t i) const;
};

#endif