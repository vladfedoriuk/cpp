#include"sf.h"

Samplefunctor::Samplefunctor(std::size_t i) : i(i) {

}

double Samplefunctor::operator()(std::size_t a) {
	return a*i;
}

Samplefunctor::operator bool() const {
	return i != 0;
}