#ifndef _CIRCLE_
#define _CIRCLE_
#include"figure.h"


using namespace std;

class Circle : public Figure {
private:
	double r;
public:
	Circle(double r = 0);
	virtual double pole() const override { return 3.14*r*r; };
	virtual double obwod() const override { return 2 * 3.14*r; }
};

#endif

