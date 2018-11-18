#pragma once
#include"List.h"
template<typename T>
class Node
{

public:
	using info_type = T;
	//costructors
	Node() {}
	Node(const info_type& dat) { this->_Info = dat; }
	Node(const Node<T> &n) :_Next(n._getNext()), _Info(n._getInfo()), _Prev(n._getPrev()){}
	~Node(){}
	//operators
	void _setNext(Node<T>*n) { _Next = n; }
	void _setPrev(Node<T>*n) { _Prev = n; }
	void _setInfo(info_type el) { _Info = el; }
	Node<T>* _getNext()const { return (_Next); }
	Node<T>* _getPrev()const { return (_Prev); }
	info_type _getInfo()const { return (_Info); }

	Node<T>* &operator=(const Node<T>*&);

bool operator==(const Node<T>*&);
private:
	Node<T> * _Next;
	Node<T> * _Prev;
	info_type _Info;
};

//overload cout
template<typename T>
ostream& operator<<(ostream& outNode, const Node<T>& n) {
	cout << n->_getInfo();
	return outNode;
}

//overload =
template<typename T>
Node<T>*& Node<T>::operator=(const Node<T>* &NodeIn) {
	_Next = NodeIn->_Next;
	_Prev = NodeIn->_Prev;
	_Info = NodeIn->_Info;
	return this;
}

//overload ==
template<typename T>
bool Node<T>::operator==(const Node<T>*& right)
{
	return this->_Info == right->_Info;
}