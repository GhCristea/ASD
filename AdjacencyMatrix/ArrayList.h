#pragma once

#include "eccezioni.h"
#include"linear_list.h"

#include<iostream>

using namespace std;

template<typename T>
class ArrayList :public Linear_list<T, size_t>
{
public:
	typedef typename Linear_list<T, size_t>::position position;
	typedef typename Linear_list<T, size_t>::info_type info_type;
	ArrayList();   //constructor
	ArrayList(size_t);   //constructor
	ArrayList(const ArrayList<T>&);    //copy constructor
	~ArrayList() { delete [] _elements; }   //distructor
				
// operators
	void create() { lenght = 0; }
	bool empty() const{ return(lenght == 0); }
	info_type read(position) const;
	void write(info_type, position);
	position begin() const{ return(1); }
	bool end(position) const;
	position next(position) const;
	position previous(position) const;
	void insert(info_type, position);
	void erase(position);
	size_t size()const { return lenght; }

	// service methods

	void print_list();
	void change_dimension_(T*& a, size_t, size_t );
	ArrayList<T>& operator=(const ArrayList<T>& l);
	bool operator==(const ArrayList<T> &l) const;

private:
	info_type *_elements;
	size_t lenght; 
	size_t max_dimention;
};



// Implementazione 

// costruttore di copia 
template <typename T>
ArrayList<T>::ArrayList(const ArrayList<T>& L)
{
	this->max_dimention = L.max_dimention;
	this->lenght = L.lenght;
	this->_elements = new T[max_dimention];
	for (size_t i = 0; i<max_dimention; i++)
		this->_elements[i] = L._elements[i];
}


// operators
template <typename T>
ArrayList<T>::ArrayList() {
	max_dimention = 1024;
	_elements = new T[max_dimention];
	this->create();
}

template <typename T>
ArrayList<T>::ArrayList(size_t dim) {
	max_dimention = dim;
	_elements = new T[max_dimention];
	this->create();
}

template <typename T> 
typename ArrayList< T >::position ArrayList<T>::next(position p) const
{
	if ((p > 0) && (p < lenght + 1)) 
		return(p + 1);
	else
		throw List_por();
}



template <typename T> 
typename ArrayList< T >::position ArrayList<T>::previous(position p) const
{
	if ((p > 0) && (p < lenght + 1))
		return(p - 1);
	else
		throw List_por();
}


template <typename T> 
bool ArrayList<T>::end(position p) const
{
	if ((p>0) && (p <= lenght + 1)) // precondition
		return(p == lenght + 1);
	else
		return(false);
}



template <typename T> 
typename ArrayList<T>::info_type ArrayList<T>::read(position p) const
{

	if ((p > 0) && (p < lenght + 1)) // precondition
	{
		if(!empty())
			return(_elements[p - 1]);
	}
		
	else
		throw List_por();
}


template <typename T> 
void ArrayList<T>::write(info_type a, position p)
{
	if ((p>0) && (p<lenght + 1)) // precondition
		_elements[p - 1] = a;
}



template <typename T> 
void ArrayList<T>::insert(info_type a, position p)
{
	if (lenght == max_dimention) {
		change_dimension_(_elements, max_dimention, max_dimention * 2);
		max_dimention = max_dimention * 2;
	}

	if ((p>0) && (p <= lenght + 1)) // precondition
	{
		for (size_t i = lenght; i >= p; i--)
			_elements[i] = _elements[i - 1];

		_elements[p - 1] = a;
		lenght++;
	}
}



template <typename T> 
void ArrayList<T>::erase(position p)
{
	if ((p > 0) && (p < lenght + 1))// precondition
	{
		if (!empty())
		{
			for (size_t i = p - 1; i < (lenght - 1); i++)
				_elements[i] = _elements[i + 1];
			lenght--;
		}
	}
}



template <typename T> 
void ArrayList<T>::print_list()
{
	cout << "[";
	int index = begin();

	while (!end(index))
	{
		cout << read(index);
		if (!end(next(index)))
			cout << ", ";

		index = next(index);
	}
	cout << "]\n";
}



template<class T>
void ArrayList< T >::change_dimension_(T*& a, size_t old_dimention, size_t new_dimention) {
	T* temp = new T[new_dimention];
	int number;

	if (old_dimention < new_dimention)
		number = old_dimention;
	else
		number = new_dimention;
	for (int i = 0; i<number; i++)
		temp[i] = a[i];
	delete[] a;
	a = temp;
}

/* overload of = */
template<class T>
ArrayList<T>& ArrayList<T>::operator=(const ArrayList<T>& l) {
	if (this != &l) {   
		this->max_dimention = l.max_dimention;
		this->lenght = l.lenght;
		delete this->_elements;
		this->_elements = new T[max_dimention_];
		for (int i = 0; i<l.max_dimention_; i++)
			this->_elements[i] = l._elements[i];
	}
	return *this;
}

//overload of ==
template<class T>
bool ArrayList<T>::operator==(const ArrayList<T> &l) const {
	if (l.lenght != this->lenght)
		return false;
	for (int i = 0; i<this->max_dimention; i++)
		if (this->_elements[i] != l._elements[i])
			return false;
	return true;
}
