#include"test.h"
#include<iostream>

Test::Test(int) : i(a), d(0.) {
	std::cout << "c-tor" << std::endl;
}

Test::Test(int a, double d) : Test(a) {
	this->d = d;
}