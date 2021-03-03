#ifndef Person_H_
#define Person_H_

#include<string>

class Person {
private:

	std::string name;
	std::string surname;
public:
	Person();
	~Person();
	Person(const std::string &name, const std::string surname);
	std::string getname() const;
	std::string getsurname() const;
	void introduce() const;
};

#endif
