#ifndef RECT_PRSM_H
#define RECT_PRSM_H

#include<iostream>
#include"object.h"

class Rectangular_prism: public Object_3d{
protected:
	double a, b, c;
public:
	virtual double pole_pow() const override {
		return 2 * a*b + 2 * a*c + 2 * b*c;
	};
	virtual double obj() const override{
		return a*b*c;
    };
	Rectangular_prism(double a = 0, double b = 0, double c = 0);
};


#endif