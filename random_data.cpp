#include"random_data.h"
#include<random>
#include<iostream>
#include<algorithm>
#include<vector>

void genRandom(int n, int max) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(1, max);
	for (int i = 0; i < n; i++) {
		std::cout << dis(gen) << " ";
	}
	std::cout << std::endl;
};
  
void genSorted() {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dis;
	dis.param(std::uniform_int_distribution<int>::param_type(1, abs(dis(gen))%1000));
	std::size_t size = dis(gen);
	std::cout << "size: " << size << std::endl;
	std::vector<int> v;
	for (int i = 0; i < size; i++) {
		v.push_back(dis(gen));
	}
	std::sort(v.begin(), v.end());
	for (auto&e : v) {
		std::cout << e << " ";
	}
	std::cout << std::endl;
};

void genReverse() {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dis;
	dis.param(std::uniform_int_distribution<int>::param_type(1, 1000));
	std::size_t size = dis(gen);
	dis.param(std::uniform_int_distribution<int>::param_type(1, 5000));
	std::vector<int> v;
	for (int i = 0; i < size; i++) {
		v.push_back(dis(gen));
	}
	std::sort(v.begin(), v.end());
	std::reverse(v.begin(), v.end());
	for (auto&e : v) {
		std::cout << e << " ";
	}
	std::cout << std::endl;
};

void genSortedFirst() {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dis;
	dis.param(std::uniform_int_distribution<int>::param_type(1, 1000));
	std::size_t size = dis(gen);
	std::vector<int> v;
	dis.param(std::uniform_int_distribution<int>::param_type(1, 5000));
	for (int i = 0; i < size; i++) {
		v.push_back(dis(gen));
	}
	std::sort(v.begin(), v.end());
	v[0] = dis(gen);
	for (auto&e : v) {
		std::cout << e << " ";
	}
	std::cout << std::endl;
}

void genSortedLast() {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dis;
	dis.param(std::uniform_int_distribution<int>::param_type(1, 1000));
	std::size_t size = dis(gen);
	std::vector<int> v;
	dis.param(std::uniform_int_distribution<int>::param_type(1, 5000));
	for (int i = 0; i < size; i++) {
		v.push_back(dis(gen));
	}
	std::sort(v.begin(), v.end());
	v[size-1] = dis(gen);
	for (auto&e : v) {
		std::cout << e << " ";
	}
	std::cout << std::endl;

}