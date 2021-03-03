#ifndef LIST_ARRAY
#define LIST_ARRAY

#include<iostream>
#include<algorithm>
#include<vector>

constexpr std::size_t MAX_N = 60000;

using position_t = int;      

template<typename T>
class SortedList {
private:
	std::size_t size_arr;
	T* arr;
	
public:
	SortedList();
	SortedList(T* a, std::size_t siz);
	SortedList(SortedList<T>&& a);
	~SortedList();
	void push(T x);       
	T pop();               
	T erase(position_t i); 
	position_t find(const T& x) const;  
	bool binary_find(const T& x) const;
	int size() const;           
	void remove(const T& x);  
	inline T at(position_t i) const;
	static SortedList<T> merge(const SortedList<T>& a, const SortedList<T>& b);
	void unique();        
	void print() const;  
	
	struct iterator;
	iterator begin() {
		return iterator(arr);
	}
	iterator end() {
		return iterator(arr + size_arr);
	}

	iterator insert(iterator it, const T& x) {
		T temp, buf = x;
		size_arr++;
		iterator fin = this->end();
		iterator it_new = it;
		while (it != this->end()) {
			temp = *it;
			*it = buf;
			buf = temp;
		    it++;
		}
	   return it_new;
	}

	iterator erase(iterator it) {
		size_arr--;
		iterator e = this->end();
		iterator next = ++it;
		while (it != e) {
			*it = *(it + 1);
			 it = it+1;
		}
		return next;
	}
};

template<typename T>
void erase(position_t i, std::size_t count) {
	for (position_t j = i; j < size_arr - count; j++) {
		arr[j] = arr[j + count];
	}
	size_arr -= count;
};

template<typename T>
struct SortedList<T>::iterator{
	T* data;
	iterator(T* ar): data(ar) {

	};
	T& operator*() {
		return *data;
	}
	iterator& operator++() {
		++data;
		return *this;
	}
	iterator operator++(int) {
		T* new_d = this->data++;
		iterator res(new_d);
		return res;
	}
	iterator operator+(int i) {
		T* new_d = this->data+i;
		iterator res(new_d);
		return res;
	}

	iterator operator-(int i) {
		T* new_d = this->data - i;
		iterator res(new_d);
		return res;
	}
	iterator& operator--() {
		--data;
		return *this;
	}

	iterator operator--(int) {
		T* new_d = this->data--;
		iterator res(new_d);
		return res;
	}

	iterator& operator=(const iterator& it) {
		this->data = it.data;
		return *this;
	}

	bool operator==(const iterator& a) const{
		return this->data == a.data;
	}
	bool operator!=(const iterator& a) const{
		return this->data != a.data;
	}
};

template<typename T>
SortedList<T>::SortedList() : arr(new T[MAX_N]), size_arr(0) {
	//std::cout << "cnstr" << std::endl;
}

template<typename T>
SortedList<T>::SortedList(T * a, std::size_t siz): arr(new T[MAX_N]), size_arr(siz)
{
	//std::cout << "cnstr 1" << std::endl;
	for (std::size_t i = 0; i < siz; i++) {
		arr[i] = a[i];
	}
	delete[] a;
}

template<typename T>
SortedList<T>::SortedList(SortedList<T>&& a): arr(new T[MAX_N]), size_arr(0)
{
	//std::cout << "move-cnstr" << std::endl;
	for (std::size_t i = 0; i < a.size(); i++) {
		push(a.at(i));
	}
}

template<typename T>
SortedList<T>::~SortedList() {
	//std::cout << "des" << std::endl;
	delete[] arr;
}

template<typename T>
void SortedList<T>::push(T x) {
	if (this->size_arr + 1 < MAX_N) {
		T* it = std::lower_bound(arr, arr + size_arr, x);
		if (it == arr + size_arr) {
			*(arr + size_arr) = x;
		}
		else {
			T temp;
			while (it != arr + size_arr+1) {
				temp = *it;
				*it = x;
				x = temp;
				it++;
			}		
		}
		size_arr++;
	}
}

template<typename T>
T SortedList<T>::pop() {
	size_arr--;
	return arr[size_arr+1];
}

template<typename T>
T SortedList<T>::erase(position_t i) {
	T res = arr[i];
	for (position_t j = i; j < size_arr - 1; j++) {
		arr[j] = arr[j + 1];
	}
	size_arr--;
	return res;
}

template<typename T>
position_t SortedList<T>::find(const T& x) const {
	position_t j = -1;
	for (std::size_t i = 0; i < size_arr; i++) {
		if (arr[i] == x) {
			j = i;
			break;
		}
	}
	return j;
}

template<typename T>
bool SortedList<T>::binary_find(const T& x) const {
	T* it = std::lower_bound(arr, arr + size_arr, x);
	return (!(it == arr + size_arr) && !(x < *it));
}

template<typename T>
int SortedList<T>::size() const{
	return size_arr;
}

template<typename T>
void SortedList<T>::remove(const T& x) {
	std::vector<int> a;
	for (position_t i = 0; i < size_arr; i++) {
		if (arr[i] == x) {
			a.push_back(i);
		}
	}
	for (int b : a) {
		erase(b);
	}
}

template<typename T>
inline T SortedList<T>::at(position_t i) const
{
	return arr[i % size_arr];
}

template<typename T>
SortedList<T> SortedList<T>::merge(const SortedList<T>& a, const SortedList<T>& b)
{
	T* ar = new T[a.size() + b.size()];
	//SortedList<T> d;
	std::size_t siz  = a.size() + b.size();
	position_t k = 0, j = 0;
	position_t i = 0;
		while (k < a.size() && j < b.size()) {
			if (a.at(k) <= b.at(j)) {
				ar[i] = a.at(k);
				//d.push(a.at(k));
				k++;
			}
			else {
				ar[i] = b.at(j);
				//d.push(b.at(j));
				j++;
			}
			i++;
		}
		while (k < a.size()) {
			ar[i] = a.at(k);
			i++;
			//d.push(a.at(k));
			k++;
		}
		while (j < b.size()){
			ar[i] = b.at(j);
			i++;
			//d.push(b.at(j));
			j++;
		}
	std::cout << "merged" << std::endl;
	return SortedList<T>(ar, siz);
	//return std::move(d);
}

template<typename T>
void SortedList<T>::unique() {

	std::size_t count = 0;
	for (position_t i = 0; i < size_arr - 1; i++) {
		for (position_t j = i + 1; arr[j] == arr[i] && j < size_arr; j++) {
			count++;
		}
		erase(i+1, count);
		count = 0;
	}
}

template<typename T>
void SortedList<T>::print() const{
	cout << "List:\n";
	for (position_t i = 0; i < size_arr; i++) {
		cout << arr[i] << " ";
	}
	cout << "\n";
}

#endif