#include<cmath>
#include"vector.h"
#include"functions.h"

using namespace std;


	void Vector::set_r() {
		r = sqrt(pow(x, 2) + pow(y, 2) + pow(z,2));

	}

	void Vector::set_x(double x) {
		this->x = x;
	}
	void Vector::set_y(double y) {
		this->y = y;
	}
	void Vector::set_z(double z) {
		this->y = y;
	}
	Vector::Vector() {
		x = 0.0;
		y = 0.0;
		z = 0.0;
		set_r();
	}

	Vector::Vector(double n1, double n2, double n3): x(n1), y(n2), z(n3) {	

	}

	Vector::~Vector() {

	}

	Vector Vector::operator+(const Vector &b) const {
		return Vector(this->x + b.x, this->y + b.y,this->z+b.z);
	}
	Vector Vector::operator-(const Vector &b) const {
		return Vector(this->x - b.x, this->y - b.y,this->z-b.z);
	}
	Vector Vector::operator-() const {
		return Vector(-this->x, -this->y, -this->z);
	}
	Vector Vector::operator*(double n) const {
		return Vector(n*x, n*y,n*z);
	}

	Vector& Vector::operator+=(const Vector& v) {
		this->x += v.x;
		this->y += v.y;
		this->z += v.z;
		return *this;
	}

	std::ostream & operator<<(std::ostream &os, const Vector &v) {
			os << "(x,y)" << " = " << "(" << v.xval() << ", " << v.yval() <<", "<<v.zval()<< ")\n";
		return os;
	}

	std::istream& operator>>(std::istream& os, Vector &v) {
		os >> v.x >> v.y >> v.z;
		return os;
	}

	double& Vector::operator[](char p) {
		switch (p) {
		case 'x':
			return x;
			break;
		case 'y':
			return y;
			break;
		case 'z':
			return z;
			break;
		default:
			break;

		}
	}

	double& Vector::operator[](int p) {
		switch (p) {
		case 0:
			return x;
			break;
		case 1:
			return y;
			break;
		case 2:
			return z;
			break;
		default:
			break;

		}
	}
	const double& Vector::operator[](int p) const {
		switch (p) {
		case 0:
			return x;
			break;
		case 1:
			return y;
			break;
		case 2:
			return z;
			break;
		default:
			break;

		}
	}

	
	const double& Vector::operator[](char p) const {
		switch (p) {
		case 'x':
			return x;
			break;
		case 'y':
			return y;
			break;
		case 'z':
			return z;
			break;
		default:
			break;

		}
	}