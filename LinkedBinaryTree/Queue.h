#pragma once
#include<iostream>

template<typename T>
class Coda
{
public:
	using info_type = T;

	//Coda() { _max_lung = 100; create(); }
	Coda(int n = 100) { _max_lung = n; create(); }
	~Coda() { delete[] _elements; }
	void create();
	bool empty()const { return (_lunghezza == 0); }
	info_type read()const { if (!empty()) return(_elements[_head]); }
	void pop();
	void push(const info_type&);
private:
	info_type *_elements;
	int _head, _lunghezza, _max_lung;
};

template<typename T>
void Coda<T>::create() {
	_elements = new info_type[_max_lung];
	_head = 0;
	_lunghezza = 0;
}

template<typename T>
void Coda<T>::pop() {
	if (!empty()) {
		_head = (_head + 1) % _max_lung;
		_lunghezza--;
	}
}

template<typename T>
void Coda<T>::push(const info_type& el) {
	if (_lunghezza != _max_lung) {
		_elements[(_head + _lunghezza) % _max_lung] = el;
		_lunghezza++;
	}
}

template<typename T>
void print_tail(Coda<T>& c) {
	if (!c.empty())
	{
		auto el = c.read();
		c.pop();
		print_tail(c);
		std::cout << el << " ";
		c.push(el);
	}
	tail(c);
}

template<typename T>
void tail(Coda<T>& c) {
	if (!c.empty())
	{
		auto el = c.read();
		c.pop();
		tail(c);
		//std::cout << el << " ";
		c.push(el);
	}
}