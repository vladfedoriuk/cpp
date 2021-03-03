#include"queue.hpp"
#include<iostream>
#include<array>
#include<random>
#include<string>
#include"radix_sort.h"
#include"simple_algos.h"
#include"heap.h"
#include"quick_sortr.h"
#include"heap.cpp"
#include<array>
#include<algorithm>
#include"random_data.h"
#include"assume_time.h"
//#include"assume_time.cpp"


int main() {
	int a[6] = { 2, 1, 5, 7, 9, 8 };
	bubble_sort(a, 6);
	print(a, 6);

	int b[8] = { 9, 8, 7, 6, 5, 1, 2, 3 };
	insertion_sort(b, 8);
	print(b, 8);

	int c[6] = { 11, 34, 54, 23, 65, 12 };
	selection_sort(c, 6);
	print(c, 6);

	int d[7] = { 101, 3, 2, 45, 67, 87, 321 };
	selection_sort_minmax(d, 7);
	print(d, 7);

	int e[7] = { 89, 1, 56, 34, 89, 43, 43 };
	counting_sort(e, 7);
	print(e, 7);

	int f[9] = { 123, 543 ,2345 ,52, 9999, 455, 1111, 1110, 0 };
	int len = 9;
	int num_of_digigts = 7;
	radix_sort(f, 9, 7);
	print(f, 9);

	int g[9] = { 123, 543 ,2345 ,52, 9999, 455, 1111, 1110, 0 };
	merge_sort(g, 0, 8);
	print(g, 9);

	int v[9] = { 123, 543 ,2345 ,52, 9999, 455, 1111, 1110, 0 };
	Heap h;
	h.sortIter(v, 9);
	print(v, 9);

	h.push(-2);
	h.push(1);
	h.push(3);
	h.push(10);
	h.print();
	h.pop();
	h.print();
	std::cout << h.check() << '\n';
	int k[9] = { 123, 543 ,2345 ,52, 9999, 455, 1111, 1110, 0 };
	qsort_iter(k, 9);
	print(k, 9);


	//std::sort use
	int arr[5000];
	int x;
	int size = 0;
	while (std::cin >> x) {
		arr[size] = x;
		size++;
	}
	std::sort(arr, arr + size);
	for (int i = 0; i < size; i++) {
		std::cout << arr[i] << " ";
	}
	//std::sort use

	std::cout << std::endl;
	//genRandom(100, 100);
	//genSorted();
	//genReverse();
	//genSortedFirst();
	//genSortedLast();
	assume_time();
	system("pause");
	return 0;
}
