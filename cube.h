#ifndef _CUBE_H_ 
#define _CUBE_H_
#include"rectangular_prism.h"

class Cube : public Rectangular_prism, public Object_3d {
public:
	Cube(double a = 0);
	virtual double pole_pow() const override { return pow(a,3); };
	virtual double obj() const override { return 6 * a; }
};


#endif
