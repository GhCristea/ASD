#pragma once

#include"Cella.h"
#include"linear_list.h"



template<typename T>
class List : public Linear_list<T, Nodo<T>*>
{
public:
	typedef Nodo<T> * position;
	typedef typename Nodo<T>::info_type info_type;
	List() { create(); }
	~List();
	List(const List<T> &l) { cout << "CC\n"; *this = l; }
	
	void create();
	bool empty()const { return (_Lista->_getPrev() == _Lista->_getNext()); }
	info_type read(position p)const { return p->_getInfo(); }
	void write(const info_type& a, position p) { p->_setInfo(a); }
	position begin()const { return (_Lista->_getNext()); }
	bool end(position p) const { return (p == _Lista); }
	position next(position p)const { return p->_getNext(); }
	position previous(position p)const { return p->_getPrev(); }
	/////
	void insert(const info_type&, position);
	void erase(position);
	//////////
	void push_front(const info_type& a) { position p = _Lista->_getPrev(); insert(a, p); p = next(p); }
	void push_back(const info_type& a) { position p = begin(); insert(a,p); }
	void pop_back() { position p = _Lista->_getNext(); erase(p); }
	void pop_front() { position p = _Lista->_getPrev(); erase(p); }
	
	//servizio
	size_t size()const { return _List_Size; }
	List<T>& operator= (const List<T> &);
	bool operator==(const List<T> &InList);
	void epura();

private:
	size_t _List_Size = 0;
	position _Lista;
};


template<typename T>
void List<T>::create() {
	//const info_type _elNul_;
	_Lista = new Nodo<T>;
	_Lista->_setPrev(_Lista);
	_Lista-> _setNext(_Lista);
	//_Lista->_setElem(_elNul_);
}


template<typename T>
void List<T>::insert(const info_type& a, position p)
{
	
	position tmp = new Nodo<T>;
	tmp->_setInfo(a);
	tmp->_setNext(p);
	tmp->_setPrev(p->_getPrev());
	(p->_getPrev())->_setNext(tmp);
	p->_setPrev(tmp);
	p = tmp;
	_List_Size++;

}

template<typename T>
void List<T>::erase(position p) {
	position tmp = new Nodo<T>;

	tmp = p;
	(p->_getNext())->_setPrev(p->_getPrev());
	(p->_getPrev())->_setNext(p->_getNext());
	p = p->_getNext();
	delete tmp;
	_List_Size--;
}

template<typename T>
List<T>::~List() {
	
	while (_Lista->_getNext() != _Lista->_getPrev()) {
		erase(_Lista->_getNext());
	}
	cout << " \ndistruttore \n";
	system("pause");
	delete _Lista;
}

template<typename T>
void List<T>::epura()
{
	List<T>::position p, q, r;

	p = begin();
	while (!end(p))//finché la position p non è quella finale...
	{
		q = next(p);//punta alla position successiva alla position p
		while (!end(q))//finché la position q non è quella finale...
		{
			//se l'elemento in position p e uguale all'elemento in position q...
			if (read(p) == read(q))
			{
				r = next(q);//memorizza la position prossima alla q
				erase(q);//cancella la position q
				q = r;//la nuova position q e r
			}
			else//altrimenti...
				q = next(q);//...vai alla position successiva a p
		}

		p = next(p);//...vai alla position successiva a q
	}

}

template< class T >
List<T>& List<T>::operator=(const List<T> &InList) {
	
	
	if (!(*this == InList)) {
			this->create();
			position p = InList.begin();
			position m = this->begin();

			while (!InList.end(p)) {
				this->insert(InList.read(p), this->next(m));
				p = InList.next(p);
				m = this->next(m);
			}
		}
	return *this;
}

template< typename T>
bool List<T>::operator==(const List<T> &InList) {
	bool flag = true;

	if (this->size() != InList.size()) {
		return false;
	}
	else {
		position p = this->begin();
		position m = InList.begin();
		while (!this->end(p) && !InList.end(m) && flag) {
			if (this->read(p) != InList.read(m))
				flag = false;
			p = this->next(p);
			m = InList.next(m);
		}
	}

	return flag;
}