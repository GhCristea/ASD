#pragma once
#include<iostream>

using std::ostream;
using std::cout;
template<typename T>
class Cell
{
public:

	using info_type = T;
	Cell() { _parent = _nextSibling = _firstSon = nullptr; }
	Cell(info_type In) { _parent = _nextSibling = _firstSon = nullptr; _info = In; }
	//~Cell();
	
	void _setInfo(info_type In) { _info = In; }
	void _setNextSibling(Cell<T>* In) { _nextSibling = In; }
	void _setFirstChild(Cell<T>* In) { _firstSon = In; }
	void _setParent( Cell<T>* In) { _parent = In; }

	 info_type _getInfo()const { return _info; }
	 inline Cell<T>* _getParent()const { return (_parent != nullptr) ? _parent : nullptr; }
	 inline Cell<T>* _getNextSibling()const { return (_nextSibling != nullptr) ? _nextSibling : nullptr; }
	 inline Cell<T>* _getFistChild()const { return (_firstSon != nullptr) ? _firstSon : nullptr; }

	 //operators overload
	 bool operator==(Cell<T> _Mycell) { return (_getInfo() == _Mycell._getInfo()); }
	 bool operator<=(Cell<T> _Mycell) { return (_getInfo() <= _Mycell._getInfo()); }

private:
	info_type _info;
	Cell<T>* _nextSibling;
	Cell<T>* _firstSon;
	Cell<T>* _parent;
};


template<typename T>
ostream& operator<<(ostream& _Myout, Cell<T>* _Mycell) {
	cout << _Mycell->_getInfo();
	return _Myout;
}

