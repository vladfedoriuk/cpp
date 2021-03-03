#ifndef LINKED_LIST
#define LINKED_LIST

#include<iostream>
#include<vector>


template<typename T>
class SortedLinkedList {
private:
	std::size_t siz;
	struct node {
		T data;
		node* prev;
		node* next;
	};

	node* body;
	//body->prev == tail
	//body->next == head
public:
	using position_t = node*;
	SortedLinkedList();
	SortedLinkedList(SortedLinkedList<T>&& a);
	~SortedLinkedList();
	void push(const T& x);
	template<typename U>
	void push(U&& obj);
	T pop();
	T pop_front();
	T erase(position_t i);
	void push_front(const T& v);
	template<typename U>
	void push_front(U&& v);
	void insert_before(node* e, const T& v);
	template<typename U>
	void insert_before(node* e, U&& v);
	void push_back(const T& v);
	template<typename U>
	void push_back(U&& v);

	position_t get_head() const{
		return body->next;
	}

	position_t find(const T& x) const
	{
		position_t p = body->next;
		while (p && p->data != x) {
			p = p->next;
		}
		return p;
	}

	position_t at(std::size_t pos) {
		position_t p = body->next;
		for (std::size_t i = 0; i < pos; i++) {
			p = p->next;
		}
		return p;
	}
	
	std::size_t size() const;
	void remove(const T& x);
	inline T at(std::size_t i) const;
	static SortedLinkedList<T> merge(const SortedLinkedList<T>& a, const SortedLinkedList<T>& b);
	void unique();
	void print() const;
	struct iterator;
	struct iterator;

	iterator begin() {
		return iterator(body->next);
	}
	iterator end() {
		return iterator(nullptr);
	}

	iterator insert(iterator it,const T& x) {
		iterator it_new;
		if (!it.d) {
			insert_before(body->prev, x);
			it_new = body->prev;
		}
		else {
			it_new = it;
			insert_before(it.d, x);
		}
		return it_new;
	}

	iterator erase(iterator it) {
		iterator next;
		if (!it.d) {
			erase(body->prev);
			next = body->prev;
		}
		else {
			next = it++;
			erase(it.d);
		}
		return next;
	}
};


template<typename T>
struct SortedLinkedList<T>::iterator {
	node* d;
	iterator() : d(nullptr) {

	};

	iterator(node* d) : d(d){

	};
	T& operator*() {
	  return d->data;
	}
	iterator& operator++() {
		if (d) {
			d = d->next;
		}
		return *this;
	}
	iterator operator++(int) {
		node* new_d; //post_incrementation
		if (d) new_d = d->next; else
			new_d = d;
		iterator res(new_d);
		return res;
	   }

	iterator& operator--() {
		if(d) d = d->prev;
		return *this;
	}

	iterator operator--(int) {
		node* new_d; //post_decrementation
		if (d) new_d = d->prev; else
			new_d = d;
		iterator res(new_d);
		return res;
	}

	iterator& operator=(const iterator& it) {
		this->d = it.d;
		return *this;
	}

	bool operator==(const iterator& a) const {
		return this->d == a.d;
	}
	bool operator!=(const iterator& a) const {
		return this->d != a.d;
	}
};
template<typename T>
inline SortedLinkedList<T>::SortedLinkedList(): siz(0)
{
	//std::cout << "constr linked 1" << std::endl;
	body = new node;
	body->next = nullptr;
	body->prev = nullptr;
}

template<typename T>
inline SortedLinkedList<T>::SortedLinkedList(SortedLinkedList<T>&& a): siz(0)
{
	//std::cout << "Move-cnstr" << std::endl;
	body = new node;
	body->next = nullptr;
	body->prev = nullptr;
	while(a.size()) push(a.pop());
}

template<typename T>
SortedLinkedList<T>::~SortedLinkedList() {
	//std::cout << "des linked" << std::endl;
	while (size()) pop();
	delete body;
}

template<typename T>
void SortedLinkedList<T>::push_front(const T& v)
{
	node * p;
	p = new node;
	p->data = v;

	p->prev = nullptr;
	p->next = body->next;
	body->next = p;
	siz++;
	if (p->next) p->next->prev = p;
	else body->prev = p;
} 

template<typename T>
template<typename U>
inline void SortedLinkedList<T>::push_front(U && v)
{
	std::cout << "T&& push_front" << std::endl;
	node * p;
	p = new node;
	p->data = std::move(v);

	p->prev = nullptr;
	p->next = body->next;
	body->next = p;
	siz++;
	if (p->next) p->next->prev = p;
	else body->prev = p;
}

template<typename T>
void SortedLinkedList<T>::insert_before(node* e,const T& v)
{
	node * p;

	if (e == body->next ) push_front(v);
	else
	{
		p = new node;
		p->data = v;
		p->next = e;
		p->prev = e->prev;
		e->prev->next = p;
		e->prev = p;
		siz++;
	}
}

template<typename T>
template<typename U>
inline void SortedLinkedList<T>::insert_before(node * e, U && v)
{
	std::cout << "T&& insert_before" << std::endl;
	node * p;

	if (e == body->next) push_front(std::forward<U>(v));
	else
	{
		p = new node;
		p->data = std::move(v);
		p->next = e;
		p->prev = e->prev;
		e->prev->next = p;
		e->prev = p;
		siz++;
	}
}

template<typename T>
void SortedLinkedList<T>::push_back(const T& v)
{
	node* p = new node;
	p->data = v;
	p->next = nullptr;
	p->prev = nullptr;

	p->prev = body->prev;
	body->prev = p;
	siz++;
	if (p->prev) p->prev->next = p;
	else body->next = p;
}

template<typename T>
template<typename U>
inline void SortedLinkedList<T>::push_back(U && v)
{
	std::cout << "T&& push_back" << std::endl;
	node* p = new node;
	p->data = std::move(v);
	p->next = nullptr;
	p->prev = nullptr;

	p->prev = body->prev;
	body->prev = p;
	siz++;
	if (p->prev) p->prev->next = p;
	else body->next = p;
}

template<typename T>
void SortedLinkedList<T>::push(const T& x) {

	
	node* k = body->next;
		while (k && k->data <= x) {
			k = k->next;
		}
		if (!k) push_back(x); else
			insert_before(k, x);
}

template<typename T>
template<typename U>
inline void SortedLinkedList<T>::push(U && obj)
{
	std::cout << "T&& push" << std::endl;
	node* k = body->next;
	while (k && k->data <= obj) {
		k = k->next;
	}
	if (!k) push_back(std::forward<U>(obj)); else
		insert_before(k, std::forward<U>(obj));
}

template<typename T>
T SortedLinkedList<T>::pop() {
	T x = body->prev->data;
	erase(body->prev);
	//std::cout << x << " was popped\n";
	return x;
}

template<typename T>
inline T SortedLinkedList<T>::pop_front()
{
	T x = erase(body->next);
	return x;
	
}

template<typename T>
T SortedLinkedList<T>::erase(position_t i) {

	T x = i->data;
	if (i->prev) {
		i->prev->next = i->next;
	}
	else {
		body->next = i->next;
	}
	if (i->next) {
		i->next->prev = i->prev;
	}
	else {
		body->prev = i->prev;
	}

	delete i;
	siz--;
	return x;
}

template<typename T>
std::size_t SortedLinkedList<T>::size() const{
	return this->siz;
}

template<typename T>
void SortedLinkedList<T>::remove(const T& x) {
	node* p = body->next;
	node* k;
	while (p) {
		if (p->data == x) {
			k = p->next;
			erase(p);
			p = k;
		} else
		p = p->next;
	}
}

template<typename T>
T SortedLinkedList<T>::at(std::size_t i) const {
	node* p = body->next;
	for (std::size_t j = 0;j < i % siz; j++) {
		p = p->next;
	}
	return p->data;
}


template<typename T>
inline SortedLinkedList<T> SortedLinkedList<T>::merge(const SortedLinkedList<T>& a, const SortedLinkedList<T>& b)
{
	SortedLinkedList<T> d;
	std::size_t k = 0, j = 0;
	node* el_a = a.get_head();
	node* el_b = b.get_head();
	while (k < a.size() && j < b.size()) {
		if (el_a->data <= el_b->data) {
			d.push_back(el_a->data);
			k++;
			el_a = el_a->next;
		}
		else {
			d.push_back(el_b->data);
			j++;
			el_b = el_b->next;
		}
	}
	while (k < a.size()) {
		d.push_back(el_a->data);
		k++;
		el_a = el_a->next;
	}
	while (j < b.size()) {
		d.push_back(el_b->data);
		j++;
		el_b = el_b->next;
	}
	//std::cout << "merged" << std::endl;
	return std::move(d);
}

template<typename T>
inline void SortedLinkedList<T>::unique()
{
	node *p, *k, *r;
	k = body->next;
	while (k) {
		p = k;
		while (p->next)
			if (p->next->data == k->data) {
				r = p->next;
				p->next = r->next;
				erase(r);
			}
			else
				p = p->next;
		k = k->next;
	}
}

template<typename T>
inline void SortedLinkedList<T>::print() const
{
	std::cout << "Linked list: \n";
	node* p = body->next;
	while (p) {
		std::cout << p->data << " ";
		p = p->next;
	}
	std::cout << '\n';
}


#endif
