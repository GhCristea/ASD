#pragma once

#include <iostream>

using std::cout;
using std::endl;
using std::ostream;
using namespace std;
// abstract class List
template< typename T, typename P >
class List{
 public:
	typedef T info_type;   // the type of object, T, stored in the list
	typedef P position;
	
	// operators
	virtual void create() = 0;
	virtual bool empty() const = 0; // true if the list's size is 0
	virtual info_type read(position) const = 0;
	virtual void write(const info_type & x, position p) = 0; // write x at position p
	virtual position begin() const = 0;  // returns a position pointing to the beginning of the list
	virtual bool end(position) const = 0; // returns a position pointing to the end of the list
	virtual position next(position) const = 0; // returns the next position
	virtual position previous(position) const = 0; // return the previous position
	virtual void insert(const info_type &, position) = 0; // insert an element 
	virtual void erase(position pos) = 0; // erases the element at position pos


	virtual size_t size() const = 0;  // returns the size of the list
	virtual void push_front(const info_type &) = 0; // insert a new element at the beginning
	virtual void push_back(const info_type &) = 0; // insert a new element at the end
	virtual void pop_front() = 0; // removes the first element
	virtual void pop_back() = 0; // removes the last element
	virtual void epura() = 0;
	
	virtual void clear();
	
};

/* overload << */
template< typename T, typename P >
ostream& operator<<(ostream& my_out, const List<T, P> &l) {
	if (l.empty())
		cout << "[]";
	else {
		typename List<T, P>::position p;
		p = l.begin();
		cout << "[";
		while (!l.end(p)) {
			if (p != l.begin())
				cout << ", " << l.read(p);
			else
				cout << l.read(p);
			p = l.next(p);
		}
		cout << "]" << endl;
		return my_out;
	}
}

template< typename T, typename P >
void List<T, P>::clear() {

	position p;
	p = this->begin();
	while (!this->end(p)) {
		this->erase(p);
		p = this->next(p);
	}
}
