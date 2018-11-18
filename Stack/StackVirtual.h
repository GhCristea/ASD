#pragma once
#include"Cella.h"
#include<iostream>

using namespace std;

template< typename T >
class StackVirtual {
public:
	using info_type = T;

	virtual void create() = 0;
	virtual bool empty() const = 0;
	virtual info_type read() const = 0;
	virtual void pop() = 0;
	virtual void push(const info_type &) = 0;
	virtual int size() const = 0;
	virtual void print() = 0;
	friend ostream& operator<<(ostream&, StackVirtual<T> &);


};

