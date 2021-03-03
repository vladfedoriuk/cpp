#ifndef SPHERE_H_
#define SPHERE_H_

#include"object.h"
#include<cmath>

class Sphere :public Object_3d {
protected:
	double r;
public:
	virtual double pole_pow() const override {
		return 4 * 3.14*pow(r, 2);
	};
	virtual double obj() const override {
		return (4.0 / 3.0)*3.14*pow(r, 3);
	};
	Sphere(double r = 0);


};


#endif