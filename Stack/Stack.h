#pragma once
#include"StackVirtual.h"
#include"Cell.h"


template<typename T>
class Stack :public StackVirtual<T>
{
	friend ostream& operator<<(ostream&, Stack<T> &);
public:
	typedef typename Cell<T>::info_type info_type;
	using pos = Cell<T> *;
	
	Stack() { _elements = new Cell<T>[100]; MAX_LENGTH = 100; create(); }
	Stack(int n) { _elements = new info_type[n]; MAX_LENGTH = n; create(); }
	Stack(const Stack<T> &);
	~Stack() { delete[] _elements; }

	void create() { _head = 0; }
	bool empty()const { return _head == 0; }
	info_type read()const { return _elements[_head - 1]._getInfo(); }
	void push(const info_type&);
	void pop();
	
	//service
	void printTail();
	int size()const { return _size; }
	void print();
private:
	pos _elements;
	int _head;
	int MAX_LENGTH;
	size_t _size;
};

template<typename T>
void Stack<T>::push(const info_type& el) {
	if (_head == MAX_LENGTH) std::cout << "Max legth riched!\n";
	else { _elements[_head]._setInfo(el); _head++; _size++; }
}

template<typename T>
void Stack<T>::pop() {
	if (!empty()) {
		_head--; 
		_size--;
	}
 	else std::cout << "The stack is empty!\n";
}

template<typename T>
void Stack<T>::printTail() {
	Stack<T>::info_type el;
	while (!empty()) {
	    el = read();
		pop();
		std::cout << el<<" ";
	
	}
	push(el);
}

template< typename T >
Stack<T>::Stack(const Stack &Stack) {
	this->create();
	this->MAX_LENGTH = Stack.MAX_LENGTH;
	this->head = Stack.head;
	for (int i = 0; i < MAX_LENGTH; i++) {
		info_type e = Stack.elements[i]._setInfo();
		this->_elements[i]._setInfo(e);
	}
}

template <typename T>
void Stack<T>::print()
{
	Stack<T> pil;
	if (!empty())
	{
		cout << "> "<<endl;
		while (!empty()) {
			cout << read() <<endl;
			pil.push(read());
			pop();
		}
		while (!pil.empty()) {
			push(pil.read());
			pil.pop();
		}
		cout <<">";
	}

	else
		cout << "nessun elemento nella Stack" << endl;
}

template<typename T>
ostream& operator<<(ostream& My_out, Stack<T> &p) {
	p.print();
	return My_out;
}