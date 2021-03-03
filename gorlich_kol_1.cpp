#include<iostream>
#include<stack>
#include<string>
#include<vector>
#include<algorithm>

int main() {
	std::stack<std::string> operators, nums;
	std::string s, current_bracket;
	while (std::cin >> s) {
		if (s == "(" || s == ")") {
			current_bracket = s;
		}
		else if (s == "+" || s == "-" || s == "*" || s == "/") {
			operators.push(s);
		}
		else {
			nums.push(s);
		}
		if (current_bracket == ")") {
			nums.push(operators.top());
			operators.pop();
			current_bracket = "(";
		}
	}
	std::vector<std::string> v;
	while (!nums.empty()) {
		v.emplace_back(nums.top());
		nums.pop();
	}
	std::reverse(v.begin(), v.end());
	for (auto& i : v) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
	system("pause");
	return 0;
}