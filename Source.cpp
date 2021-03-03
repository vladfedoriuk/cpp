#include"object.h"
#include"cube.h"
#include"sphere.h"
#include"rectangular_prism.h"
#include<iostream>

using namespace std;

int main() {

	Object_3d *fg;
	Rectangular_prism p1(2.5, 4, 3);
	Sphere k1(3);
	Sphere circle(3);

	cout << p1.pole_pow() << endl;
	fg = &p1;
	cout << fg->pole_pow() << endl;
	cout << fg->obj() << endl;

	cout << k1.pole_pow() << endl;
	cout << k1.obj() << endl;
	fg = &k1;
	cout << fg->pole_pow() << endl;
	cout << fg->obj() << endl;

	cout << circle.pole_pow() << endl;
	fg = &circle;
	cout << fg->pole_pow() << endl;
	cout << fg->obj() << endl;

	fg = new Sphere(4);

	delete fg;

	Cube t = Cube(3);
	fg = &t;
	cout << fg->pole_pow() << endl;
	system("pause");

	return 0;
}