#ifndef _SQUARE_ 
#define _SQUARE_
#include"rectangle.h"

class Square : public Rectangle {
public:
	Square(double a = 0);
	virtual double pole() const override { return a*a; };
	virtual double obwod() const override { return 4 * a; }
};


#endif