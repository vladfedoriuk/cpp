#include<iostream>
#include"queue.hpp"

constexpr int num_of_queues = 10;

int current_digit(int number, int place)
{
	return number / place % 10;
}

void radix_sort(int *a, int len, int num_of_digits) {
	int max_num_of_digits = num_of_digits;
	int radix = 10;
	Queue<int> queues[num_of_queues];

	for (int d = 1, place = 1; d <= max_num_of_digits; place *= radix, ++d) {
		for (int i = 0; i < len; ++i) {
			queues[current_digit(a[i], place)].push(a[i]);
		}

		int a_pos = 0;
		for (int i = 0; i < num_of_queues; ++i) {
			while (!queues[i].empty()) {
				try {
					a[a_pos++] = queues[i].front();
				}
				catch (std::exception& e) {
					std::cout << e.what() << std::endl;
				}
				queues[i].pop();
			}
		}
	}
}
