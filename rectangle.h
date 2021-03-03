#ifndef _RECTANGLE_ 
#define _RECTANGLE_
#include"figure.h"

class Rectangle : public Figure {
protected:
	double a;
	double b;
public:
	Rectangle(double a = 0, double b = 0);
	virtual double pole() const override { return a*b; };
	virtual double obwod() const override { return 2 * (a + b); }
};


#endif