#ifndef _POINT_H
#define _POINT_H

#include<functional>
#include<exception>
#include<iostream>

template<typename T>
class Point {
private:
	T x;
	T y;
public:
	Point();
	Point(const T& x, const T& y);
	T& operator[](char k);
	void print() {
		std::cout << "[" << x << ", " << y << "]";
	};
	double dist(Point<T>& p) {
		return sqrt((x - p['x'])*(x - p['x']) + (y - p['y'])*(y - p['y']));
	};

};

template<typename T>
inline Point<T>::Point(): x(0.0), y(0.0)
{
};

template<typename T>
Point<T>::Point(const T& x, const T& y): x(x), y(y) {

};

template<typename T>
T& Point<T>::operator[](char k) {
	if (k == 'x') {
		return x;
	}
	else if (k == 'y') {
		return y;
	}
	else throw std::runtime_error("wrong argument given to a Point::operator[]");
};


#endif