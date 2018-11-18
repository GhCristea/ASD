#pragma once

#include"Cella.h"
#include"List.h"



template<typename T>
class CircularList : public List<T, Nodo<T>*>
{
public:
	typedef Nodo<T> * position;
	typedef typename Nodo<T>::info_type info_type;
	CircularList() { create(); }
	~CircularList();
	CircularList(const CircularList<T> &l) { *this = l; }
	
	void create();
	bool empty()const { return (_CircularLista->_getPrev() == _CircularLista->_getNext()); }
	info_type read(position p)const { return p->_getInfo(); }
	void write(const info_type& a, position p) { p->_setInfo(a); }
	position begin()const { return (_CircularLista->_getNext()); }
	bool end(position p) const { return (p == _CircularLista); }
	position next(position p)const { return p->_getNext(); }
	position previous(position p)const { return p->_getPrev(); }
	/////
	void insert(const info_type&, position);
	void erase(position);
	//////////
	void push_front(const info_type& a) { position p = _CircularLista->_getPrev(); insert(a, p); p = next(p); }
	void push_back(const info_type& a) { position p = begin(); insert(a,p); }
	void pop_back() { position p = _CircularLista->_getNext(); erase(p); }
	void pop_front() { position p = _CircularLista->_getPrev(); erase(p); }
	
	//servizio
	size_t size()const { return _CircularList_Size; }
	CircularList<T>& operator= (const CircularList<T> &);
	bool operator==(const CircularList<T> &InCircularList);
	void purge();

private:
	size_t _CircularList_Size = 0;
	position _CircularLista;
};


template<typename T>
void CircularList<T>::create() {
	//const info_type _elNul_;
	_CircularLista = new Nodo<T>;
	_CircularLista->_setPrev(_CircularLista);
	_CircularLista-> _setNext(_CircularLista);
	//_CircularLista->_setElem(_elNul_);
}


template<typename T>
void CircularList<T>::insert(const info_type& a, position p)
{
	
	position tmp = new Nodo<T>;
	tmp->_setInfo(a);
	tmp->_setNext(p);
	tmp->_setPrev(p->_getPrev());
	(p->_getPrev())->_setNext(tmp);
	p->_setPrev(tmp);
	p = tmp;
	_CircularList_Size++;

}

template<typename T>
void CircularList<T>::erase(position p) {
	position tmp = new Nodo<T>;

	tmp = p;
	(p->_getNext())->_setPrev(p->_getPrev());
	(p->_getPrev())->_setNext(p->_getNext());
	p = p->_getNext();
	delete tmp;
	_CircularList_Size--;
}

template<typename T>
CircularList<T>::~CircularList() {
	
	while (_CircularLista->_getNext() != _CircularLista->_getPrev()) {
		erase(_CircularLista->_getNext());
	}
	delete _CircularLista;
}

template<typename T>
void CircularList<T>::purge()
{
	CircularList<T>::position p, q, r;

	p = begin();
	while (!end(p))//while p not pointing at the last the last
	{
		q = next(p);//point the next
		while (!end(q))//while q not pointing at the last the last
		{
			//if p and q are pointng to the same value
			if (p == q)
			{
				r = next(q);//memorize the next of q
				erase(q);//erase position q
				q = r;//exchange q e r
			}
			else
				q = next(q);// go to the next
		}

		p = next(p);// go to the next
	}

}

template< class T >
CircularList<T>& CircularList<T>::operator=(const CircularList<T> &InCircularList) {
	
	
	if (!(*this == InCircularList)) {
			this->create();
			position p = InCircularList.begin();
			position m = this->begin();

			while (!InCircularList.end(p)) {
				this->insert(InCircularList.read(p), this->next(m));
				p = InCircularList.next(p);
				m = this->next(m);
			}
		}
	return *this;
}

template< typename T>
bool CircularList<T>::operator==(const CircularList<T> &InCircularList) {
	bool flag = true;

	if (this->size() != InCircularList.size()) {
		return false;
	}
	else {
		position p = this->begin();
		position m = InCircularList.begin();
		while (!this->end(p) && !InCircularList.end(m) && flag) {
			if (this->read(p) != InCircularList.read(m))
				flag = false;
			p = this->next(p);
			m = InCircularList.next(m);
		}
	}

	return flag;
}