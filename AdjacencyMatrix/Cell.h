#pragma once
#include"linear_list.h"
template<typename T>
class Nodo
{

public:
	using info_type = T;
	//costruttori
	Nodo() {}
	Nodo(const info_type& dat) { this->_Info = dat; }
	Nodo(const Nodo<T> &n) :_Next(n._getNext()), _Info(n._getInfo()), _Prev(n._getPrev()){}
	~Nodo(){}
	//operatori
	void _setNext(Nodo<T>*n) { _Next = n; }
	void _setPrev(Nodo<T>*n) { _Prev = n; }
	void _setInfo(info_type el) { _Info = el; }
	Nodo<T>* _getNext()const { return (_Next); }
	Nodo<T>* _getPrev()const { return (_Prev); }
	info_type _getInfo()const { return (_Info); }

	Nodo<T>* &operator=(const Nodo<T>*&);
private:
	Nodo<T> * _Next;
	Nodo<T> * _Prev;
	info_type _Info;
};

//overload cout
template<typename T>
ostream& operator<<(ostream& outNode, const Nodo<T>& n) {
	cout << n->_getInfo();
	return outNode;
}

template<typename T>
Nodo<T>*& Nodo<T>::operator=(const Nodo<T>* &nodoIn) {
	_Next = nodoIn->_Next;
	_Prev = nodoIn->_Prev;
	_Info = nodoIn->_Info;
	return this;
}