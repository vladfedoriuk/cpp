#ifndef VECTOR_H_
#define VECTOR_H_

#include<iostream>
	class Vector {
	private:
		double x;
		double y;
		double z;
		double r;
		void set_r();
		void set_x( double x);
		void set_y(double y);
		void set_z(double z);
	public:
		Vector();
		Vector(double n1, double n2, double n3);
		~Vector();
		double xval()const { return x; };
		double yval()const { return y; };
		double zval()const { return z; };
		double rval()const { return r; };

		double dot(const Vector& v2) const {
			return x*v2.x + y*v2.y + z*v2.z;
		};

		Vector cross(const Vector& v2) const {
			return Vector(y*v2.z - z*v2.y, z*v2.x - x*v2.z, x*v2.y - y*v2.x);
		}

		//methods overloading operators
		Vector operator+(const Vector & b) const;
		Vector operator-(const Vector& b) const;
		Vector operator-() const;
		Vector operator*(double n) const;
		Vector& operator+=(const Vector& v);
		friend Vector operator*(double n, const Vector& a);
		friend std::ostream & operator<<(std::ostream &os, const Vector &v);
		friend std::istream& operator>>(std::istream& os, Vector &v);
		double& operator[](char p);
		const double& operator[](char p) const;
		double& operator[](int p);
		const double& operator[](int p) const;
	};
#endif VECTOR_H_
