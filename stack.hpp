#ifndef STACK_H_
#define STACK_H_

#include<memory>

template<typename T>
class Stack {
private:

	struct list_el{
		std::shared_ptr<list_el> next;
		T info;
	};


	std::shared_ptr<list_el> S;
public:
	Stack();       
	~Stack();      
	bool empty() const;
	T top() const;
	void push(const T v);
	void pop();
	void print();
	void put_max_in_top();
};

template<typename T>
Stack<T>::Stack() : S(nullptr) {

};

template<typename T>
Stack<T>::~Stack() {
	while (S) pop();
}

template<typename T>
bool Stack<T>::empty() const {
	return !S
}

template<typename T>
T Stack<T>::top() const{
	return S->info;
}

template<typename T>
void Stack<T>::push(const T v) {
	std::shared_ptr<list_el> e(new list_el);
	e->info = v;
	e->next = S;
	S = e;
	
}

template<typename T>
void Stack<T>::pop(){
	if (S)
	{
		S = S->next;
	}
}

template<typename T>
void Stack<T>::print() {
	std::shared_ptr<list_el> p = S;
	cout << "Stack: \n";
	while (p) {
		std::cout << p->info << " ";
		p = p->next;
	}
	cout << std::endl;
}

template<typename T>
void Stack<T>::put_max_in_top() {
	std::shared_ptr<list_el> max = S;
	std::shared_ptr<list_el> p = S;
	while(p) {
		if (p->info > max->info)
			max = p;
		p = p->next;
	}
	if (max != S) {
		p = S;
		while (p->next != max)
			p = p->next;
		p->next = p->next->next;
		max->next = S;
		S = max;
	}
}



#endif
