#ifndef TABLICA_H_
#define TABLICA_H_

#include<iostream>
#include<cstdint>

template<typename T>
class Tablica {
public:
	const std::size_t size;
	T *t;
	std::size_t top;
	Tablica();
	Tablica(std::size_t n);
	Tablica(const Tablica<T> &a);//konstruktor kopiujacy;
	Tablica(Tablica<T> &&source);
	T get_element(std::size_t i) const;
	void set_element(std::size_t i, T a);
	~Tablica();
	std::size_t get_size() const;
	void push_back(T a);
	Tablica<T>& operator=(const Tablica<T>& a);
	Tablica<T>& operator=(Tablica<T>&& a);
	T& setGet(std::size_t i);
	T& operator[](std::size_t i);
	T& operator[](std::size_t i) const;
};

template<typename T>
Tablica<T>::Tablica():t(NULL), top(0) {
	std::cout << "Tablica c-tor" << std::endl;
}

template<typename T>
Tablica<T>::~Tablica() {
	delete[] t;
}

template<typename T>
Tablica<T>::Tablica(std::size_t n) : size(n), top(0), t(new double[n]) {

}

template<typename T>
Tablica<T>::Tablica(Tablica &&source) : size(source.get_size()), t(source.t) {//move-constructor ( const - x bo nie mozemy zmienic ) ( przenosi zawartosc elementu bez kopiowania
	std::cout << "move-ctr" << std::endl;
	source.size = 0;
	source.t = NULL;
}

template<typename T>
T Tablica<T>::get_element(std::size_t i) const {
	return t[i];
}

template<typename T>
void Tablica<T>::set_element(std::size_t i, T a) {
	t[i] = a;
}

template<typename T>
std::size_t Tablica<T>::get_size() const {
	return size;
}

template<typename T>
void Tablica<T>::push_back(T a) {
	(top < size) ? (t[top] = a, top++) : (top = 0, t[top] = a);
}

template<typename T>
Tablica<T>::Tablica(const Tablica &a) {
	t = new double[a.size];
	size = a.size;
	top = 0;
	for (std::size_t i = 0; i < a.size; i++) {
		push_back(a.get_element(i));
	}
}

template<typename T>
Tablica<T>& Tablica<T>::operator=(const Tablica<T>& a) {
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

template<typename T>
Tablica<T>& Tablica<T>::operator=(Tablica<T>&& a) {
	if (this != &a) {
		size = a.get_size();
		delete[] t;

		t = a.t;
		a.size = 0;
		a.t = NULL;
	}
	return *this;
}

template<typename T>
T& Tablica<T>::setGet(std::size_t i) {
	return t[i];
}

template<typename T>
T& Tablica<T>::operator[](std::size_t i) {
	return t[i];
}

template<typename T>
T& Tablica<T>::operator[](std::size_t i) const {
	return t[i];
}


template < typename T1, typename T2>
auto add( T1&&, T2&&) {
	return p1 + p2;
}


#endif
