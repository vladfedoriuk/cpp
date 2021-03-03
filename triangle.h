#ifndef _TRIANGLE_
#define _TRIANGLE_
#include"figure.h"
#include<cmath>
#include<iostream>
#include<cstdlib>

class Triangle : public Figure {
private:
	double a, b, c;
public:
	Triangle(double a = 0, double b = 0, double c = 0);
	virtual double pole() const override { double p = (a + b + c) / 2; return pow(p*(p - a)*(p - b)*(p - c), 0.5); };
	virtual double obwod() const override { return a+b+c; }
};

#endif;

