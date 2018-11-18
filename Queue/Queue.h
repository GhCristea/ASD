#pragma once
#include<iostream>

template<typename T>
class Queue
{
public:
	using info_type = T;

	//Queue() { _max_length = 100; create(); }
	Queue(int n = 100) { _max_length = n; create(); }
	Queue(const Queue<T>&);
	~Queue() { delete[] _elements; }
	void create();
	bool empty()const { return (_length == 0); }
	info_type read()const { if (!empty()) return(_elements[_head]); }
	void pop();
	void push(const info_type&);
private:
	info_type *_elements;
	int _head, _length, _max_length;
};


template<typename T>
Queue<T>::Queue(const Queue<T>& c)
{

}

template<typename T>
void Queue<T>::create() {
	_elements = new info_type[_max_length];
	_head = 0;
	_length = 0;
}

template<typename T>
void Queue<T>::pop() {
	if (!empty()) {
		_head = (_head + 1) % _max_length;
		_length--;
	}
}

template<typename T>
void Queue<T>::push(const info_type& el) {
	if (_length != _max_length) {
		_elements[(_head + _length) % _max_length] = el;
		_length++;
	}
}

template<typename T>
void print_tail(Queue<T>& c) {
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
void tail(Queue<T>& c) {
	if (!c.empty())
	{
		auto el = c.read();
		c.pop();
		tail(c);
		//std::cout << el << " ";
		c.push(el);
	}
}