#ifndef TEST_H_
#define TEST_H_

class Test {
private:
	int i;
	double d;
public:
	Test() = default; // uzywac defaultowych
	Test(int a);
	Test(int a, double d);
	Test(const Test& source)=delete;
	Test& operator=(const Test & source) = delete; //nie uzywac defaultowych
};

#endif
