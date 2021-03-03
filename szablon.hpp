#pragma once
template<typename T1, typename T2, typename T3>
T1 add(const T2 &p1, const T3 &p2) {
	return p1 + p2;
}

template <typename T, std::size_t N>
void f(std::size_t n) {
	T t[N];
}

template<typename T, int N>
class SamleClass {
public:
	T t[N];
	SampleClass();
	~SampleClass();

};