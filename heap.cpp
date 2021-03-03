#include"heap.h"

Heap::Heap() : arr(new int[max_len]), siz(0) {

};

void Heap::heapify(int* a, int i, int n) {
	int largest = i;
	do {
		int root = largest;
		int left = 2 * root + 1;
		int right = 2 * root + 2;
		if (left < n && a[left] > a[largest]) {
			largest = left;
		}
		if (right < n && a[right] > a[largest]) {
			largest = right;
		}
		if (largest == root) break;
		int temp = a[root];
		a[root] = a[largest];
		a[largest] = temp;
	} while (true);
};

Heap::~Heap() {
	if (arr) delete[] arr;
};

void Heap::build(int* a, int n) {
	for (int i = (n-1)/2; i >= 0; i--) {
		heapify(a, i, n);
	}
	
};

void Heap::sortIter(int* a, int n) {
	build(a, n);
	for (int i = n - 1; i > 0; i--) {
		int temp = a[0];
		a[0] = a[i];
		a[i] = temp;
		heapify(a, 0, i);
	}
};

void Heap::push(int x) {
	siz++;
	increase_key(siz-1, x);
};

void Heap::increase_key(int i, int x) {
	while (i > 0 && arr[(i-1) / 2] < x) {
		arr[i] = arr[(i-1) / 2];
		i = (i-1) / 2 ;
	}
	arr[i] = x;
}

int Heap::pop() {
	int root = arr[0];
	arr[0] = arr[siz - 1];
	siz--;
	heapify(arr, 0, siz);
	return root;
};


