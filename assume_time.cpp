#include"queue.hpp"
#include<iostream>
#include<array>
#include<random>
#include<string>
#include"radix_sort.h"
#include"simple_algos.h"
#include"heap.h"
#include"quick_sortr.h"
//#include"heap.cpp"
#include<array>
#include<algorithm>
#include<fstream>
#include<chrono>

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<> dis(1, 1000);

void randomize(int* a, int n) {
	for (long i = 0; i < n; i++) {
		a[i] = dis(gen);
	}
}

void assume(std::ofstream& out, int* a, long n) {
	out << n << " ";
	randomize(a, n);
	auto start = std::chrono::high_resolution_clock::now();
	bubble_sort(a, n);
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = end - start;
	out << elapsed.count() << " ";

	randomize(a, n);
	start = std::chrono::high_resolution_clock::now();
	insertion_sort(a, n);
	end = std::chrono::high_resolution_clock::now();
	elapsed = end - start;
	out << elapsed.count() << " ";

	randomize(a, n);
	start = std::chrono::high_resolution_clock::now();
	selection_sort_minmax(a, n);
	end = std::chrono::high_resolution_clock::now();
	elapsed = end - start;
	out << elapsed.count() << " ";


	dis.param(std::uniform_int_distribution<int>::param_type(1, n));
	randomize(a, n);
	start = std::chrono::high_resolution_clock::now();
	counting_sort(a, n); //5
	end = std::chrono::high_resolution_clock::now();
	elapsed = end - start;
	out << elapsed.count() << " ";
	dis.param(std::uniform_int_distribution<int>::param_type(1, 1000));

	randomize(a, n);
	start = std::chrono::high_resolution_clock::now();
	merge_sort(a, 0, n-1);
	end = std::chrono::high_resolution_clock::now();
	elapsed = end - start;
	out << elapsed.count() << " ";

	randomize(a, n);
	start = std::chrono::high_resolution_clock::now();
	radix_sort(a, n, 4);
	end = std::chrono::high_resolution_clock::now();
	elapsed = end - start;
	out << elapsed.count() << " ";

	randomize(a, n);
	start = std::chrono::high_resolution_clock::now();
	Heap h;
	h.sortIter(a, n);
	end = std::chrono::high_resolution_clock::now();
	elapsed = end - start;
	out << elapsed.count() << " ";

	randomize(a, n);
	start = std::chrono::high_resolution_clock::now();
	qsort_iter(a, n); //9
	end = std::chrono::high_resolution_clock::now();
	elapsed = end - start;
	out << elapsed.count() << " ";
	out << std::endl;

}
void assume_time() {
	int* a = new int[160000];
	std::ofstream out("data.txt");
	assume(out, a, 10000);
	assume(out, a, 20000);
	assume(out, a, 40000);
	assume(out, a, 80000);
	assume(out, a, 160000);
	delete[] a;
	out.close();
}


