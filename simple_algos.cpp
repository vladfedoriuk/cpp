#include"queue.hpp"
#include<iostream>
#include<array>
#include<random>
#include<string>


constexpr int MAX_LEN = 50000;

void bubble_sort(int* a, std::size_t n) {
	for (int i = 0; i < n-1; i++) {
		for (int j = n-1; j > i; j--) {
			if (a[j] < a[i]) {
				int temp = a[j];
				a[j] = a[i];
				a[i] = temp;
			}
		}
	}
}

void insertion_sort(int* a, std::size_t n) {
	for (int j = 1; j < n; j++) {
		int key = a[j];
		//insertion a[j] in an already sorted subsequence a[0...j-1]
		int i = j - 1;
		while (i >= 0 && a[i] > key) {
			a[i + 1] = a[i];
			i--;
		}
		a[i + 1] = key;
	}
}

void print(int* a, std::size_t n){
	for (int i = 0; i < n; i++) {
		std::cout << a[i] << " ";
	}
	std::cout << std::endl;
}

void selection_sort(int* a, std::size_t n) {
	for (int i = 0; i < n; i++) {
		int index = i;
		for (int j = i; j < n; j++) {
			if (a[j] < a[index]) {
				index = j;
			}
		}
		if (i != index) {
			int temp = a[i];
			a[i] = a[index];
			a[index] = temp;
		}
	}
}

void selection_sort_minmax(int* a, const std::size_t n) {
	int temp;
	for (int i = 0; i < n/2; i++) {
		int min = i;
		int max = n - i - 1;
		if (a[min] > a[max]) {
			temp = a[min];
			a[min] = a[max];
			a[max] = temp;
		}
		for (int j = i; j < n - i; j++) {
			if (a[j] < a[min]) {
				min = j;
			}
			if (a[j] > a[max]) {
				max = j;
			}
		}
			temp = a[i];
			a[i] = a[min];
			a[min] = temp;

			temp = a[n - i - 1];
			a[n - i - 1] = a[max];
			a[max] = temp;
	}
}

void counting_sort(int* a, const std::size_t n) {
	int max = a[0];

	for (int i = 1; i < n; i++) {
		if (max < a[i]) {
			max = a[i];
		}
	}

	int* c = new int[max+1];

	for (int i = 0; i <= max; i++) {
		c[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		c[a[i]]++;
	}

	int k = 0;
	for (int i = 0; i <= max; i++) {
		for (int j = 0; j < c[i]; j++) {
			a[k++] = i;
		}
	}
	delete[] c;
}

void merge(int *a, int left, int right, int middle) {
	int i, j, k;
	const int n1 = middle - left + 1;
	const int n2 = right - middle;
	int* L = new int[n1];
	int* R = new int[n2];

	for (i = 0; i < n1; i++) {
		L[i] = a[left + i];
	}

	for (j = 0; j < n2; j++) {
		R[j] = a[middle + j + 1];
	}

	i = 0, j = 0;
	for (k = left; i < n1 && j < n2; k++) {
		if (L[i] <= R[j]) {
			a[k] = L[i++];
		}
		else {
			a[k] = R[j++];
		}
	}

	while (i < n1) {
		a[k++] = L[i++];
	}

	while (j < n2) {
		a[k++] = R[j++];
	}
	delete[] L;
	delete[] R;
}

void merge_sort(int* a, int left, int right) {
	int middle;
	if (left < right) {
		middle = (left + right) / 2;
		merge_sort(a, left, middle);
		merge_sort(a, middle + 1, right);
		merge(a, left, right, middle);
	}
}



