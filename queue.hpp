#ifndef QUEUE_H_
#define QUEUE_H_

#include <ostream>
#include<exception>

constexpr std::size_t MAX_SIZE = 50000;
template<typename T>
class Queue
{
private:
	std::size_t siz;      
	std::size_t begin;   
	std::size_t end;   
	T * t;   

public:
	Queue();
	Queue(T n);
	~Queue();    
	bool empty();
	bool is_full();
	int  front();
	template<typename U>
	void push(U&& v);
	void pop();
	T& operator[](std::size_t i);
	std::size_t size();
};


template<typename T>
Queue<T>::Queue(T n) :siz(n), t(new T[n]), begin(0), end(0)
{
}

template<typename T>
Queue<T>::Queue() : siz(MAX_SIZE), begin(0), end(0), t(new T[siz]) {

}


template<typename T>
Queue<T>::~Queue()
{
	delete[] t;
}

template<typename T>
bool Queue<T>::empty()
{
	return begin == end;
}

template<typename T>
std::size_t Queue<T>::size() {
	return siz;
}

template<typename T>
T& Queue<T>::operator[](std::size_t i) {
	return t[i];
}

template<typename T>
int Queue<T>::front()
{
	if(!empty()) return t[begin];
	throw std::exception("no elements left in the queue");
}

template<typename T>
bool Queue<T>::is_full() {
	return (begin == end+1) || (begin == 0 && begin == tail)
}
template<typename T>
template<typename U>
void Queue<T>::push(U&& v)
{
	t[end] = v;
	if (end == siz-1) {
		end = 0;
	}
	else
		end = end + 1;
}

template<typename T>
void Queue<T>::pop()
{
	if (begin == siz) {
		begin = 0;
	}
	else {
		begin = begin + 1;
	}
}

#endif