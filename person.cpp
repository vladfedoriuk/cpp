#include"person.h"
#include<iostream>
#include<string>

Person::Person() : name("Ktos") , surname("Anonim") {
	std::cout << "defaulr c-tor"<<std::endl;
	introduce();
}
Person::Person(const std::string &name, const std::string surname) : name(name), surname(surname) {
	std::cout << "c-tor"<<std::endl;
	introduce();
}
std::string Person::getname() const {
	return name;
}
std::string Person::getsurname() const {
	return surname;
}
void Person::introduce() const {
	std::cout << name <<" "<< surname<<std::endl;
}
Person::~Person() {
	std::cout << "d - tor"<<std::endl;
	introduce();
}