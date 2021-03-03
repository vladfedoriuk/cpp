#pragma once
#include<iostream>

class Samplefunctor {
private:
	std::size_t i;
public:
	explicit Samplefunctor(std::size_t i);
	double operator()(std::size_t a);
	operator bool() const;
};