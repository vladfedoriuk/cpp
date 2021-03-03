#ifndef _HEAP_H
#define _HEAP_H

#include<iostream>
#include<functional>

constexpr std::size_t max_len = 50000;

template<typename T>
class Heap {
private:
	std::size_t siz;
	T* arr;
	void increase_key(std::size_t i, const T& x);
	void heapify(T* a, std::size_t i, std::size_t n);
	std::function<int(T, T)> compare;
public:
	void print() {
		for (std::size_t i = 0; i < siz; i++) {
			std::cout << arr[i] << " ";
		}
		std::cout << std::endl;
	};
	Heap();
	~Heap();
	Heap(const std::function<int(T, T)>& cmp);
	void push(const T& x);
	T pop();
	T& top() {
		return arr[0];
	};
	std::size_t size() {
		return siz;
	};
	bool empty() {
		return siz == 0;
	};
	bool check() {
		for (std::size_t i = 0; i < siz; i++) {
			if (i * 2 + 1 < siz && arr[i * 2 + 1] > arr[i]) return false;
			if (i * 2 + 2 < siz && arr[i * 2 + 2] > arr[i]) return false;
		}
		return true;
	};
	void build(T* a, std::size_t n);
	void sortIter(T* a, std::size_t n);
};

template<typename T>
Heap<T>::Heap() : arr(new T[max_len]), siz(0) {
	compare = [](T a, T b) {return a - b; };
};

template<typename T>
Heap<T>::Heap(const std::function<int(T, T)>& cmp) : arr(new T[max_len]), siz(0), compare(cmp) {

};

template<typename T>
void Heap<T>::heapify(T* a, std::size_t i, std::size_t n) {
	std::size_t largest = i;
	do {
		std::size_t root = largest;
		std::size_t left = 2 * root + 1;
		std::size_t right = 2 * root + 2;
		if (left < n && compare(a[left], a[largest]) > 0) {
			largest = left;
		}
		if (right < n && compare(a[right], a[largest]) > 0) {
			largest = right;
		}
		if (largest == root) break;
		T temp = a[root];
		a[root] = a[largest];
		a[largest] = temp;
	} while (true);
};

template<typename T>
Heap<T>::~Heap() {
	if (arr) delete[] arr;
};

template<typename T>
void Heap<T>::build(T* a, std::size_t n) {
	for (int i = (n - 1) / 2; i >= 0; i--) {
		heapify(a, i, n);
	}

};

template<typename T>
void Heap<T>::sortIter(T* a, std::size_t n) {
	build(a, n);
	for (std::size_t i = n - 1; i > 0; i--) {
		T temp = a[0];
		a[0] = a[i];
		a[i] = temp;
		heapify(a, 0, i);
	}
};

template<typename T>
void Heap<T>::push(const T& x) {
	siz++;
	increase_key(siz - 1, x);
};

template<typename T>
void Heap<T>::increase_key(std::size_t i, const T& x) {
	while (i > 0 && compare(arr[(i - 1) / 2], x) < 0) {
		arr[i] = arr[(i - 1) / 2];
		i = (i - 1) / 2;
	}
	arr[i] = x;
}

template<typename T>
T Heap<T>::pop() {
	T root = arr[0];
	arr[0] = arr[siz - 1];
	siz--;
	heapify(arr, 0, siz);
	return root;
};

#endif