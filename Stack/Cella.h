#pragma once
#include<iostream>

using namespace std;

template<typename T>
class Cell
{
	friend ostream& operator<<(ostream&, Cell<T>);
public:
	using info_type = T;
	Cell(){}
	~Cell(){}

	Cell<T> * _getNext()const { return _next; }
	info_type _getInfo()const { return _info; }

	void _setNext(Cell<T>* In) { _next = In; }
	void _setInfo(info_type In) { _info = In; }

private:
	Cell<T>* _next;
	info_type _info;
};


template<typename T>
ostream& operator<<(ostream& out, Cell<T> cellIn) {
	cout << cellIn._getInfo();
}