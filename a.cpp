#include<iostream>

#include<tuple>

#include<vector>
#include<utility>

using namespace std;

std::tuple<int, std::vector<double>, std::pair<double, int>> fun() {
	vector<double> res_v;
	int res_i = 3;
	auto res_p = std::make_pair(2., 4);
	res_v.resize(4);
	return{ res_i, std::move(res_v),res_p };
}

int main() {
	//auto[i, v, p] = fun();
}