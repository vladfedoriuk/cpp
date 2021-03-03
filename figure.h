#ifndef _FIGURE_
#define _FIGURE_

#include<iostream>

class Figure {
public:
	virtual double pole() const = 0;
	virtual double obwod() const = 0;
};

#endif
