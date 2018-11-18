#pragma once


#include"Cell.h"
#include"exception.h"
#include"bintreeVirtClass.h"

template<typename T>
class BinTree :public  BinTreeVirtual<T, Cell<T>*>
{
public:
	//types
	typedef  Cell<T>* pos;
	typedef typename Cell<T>::info_type info_type;
	
	//constructor
	BinTree() { create(); }
	//distructor
	~BinTree() { delete_subtree(root()); }

	//operators
	void create() { _root = nullptr; }
	pos root()const { return _root; }
	bool empty()const { return (_root == nullptr); }
	bool empty_dad(pos In)const { return ((In->_getDad()) == nullptr); }
	bool empty_left_son(pos In)const { return ((In->_getLson()) == nullptr); }
	bool empty_right_son(pos In)const { return ((In->_getRson()) == nullptr); }
	bool leaf(pos In)const{return (empty_left_son(In) && empty_right_son(In)); }

	info_type read(pos In)const { return((In != nullptr) ? In->_getInfo() : throw NullNode()); }
	pos dad(pos In)const { return((!empty_dad(In)) ? In->_getDad() :  nullptr); }
	pos left_son(pos In)const { return ((!empty_left_son(In)) ? In->_getLson() : nullptr); }
	pos right_son(pos In)const { return ((!empty_right_son(In)) ? In->_getRson() : nullptr); }

	void ins_root(pos);
	void write(pos n, const info_type in) { (n != nullptr) ? n->_setInfo(in) : throw NullNode(); }
	void ins_left_son(pos);
	void ins_right_son(pos);
	void delete_subtree(pos);

	int hight(pos n);
	bool search_el(Cell<T>*, info_type);
	

private:
	pos _root;
};


template<typename T>
void BinTree<T>::ins_root(pos In)
{

	if (empty())
	{
		_root = In;
		_root->_setDad(nullptr);
		_root->_setLson(nullptr);
		_root->_setRson(nullptr);
	}
	else throw RootExisting();

}

/**
* insert left son at position: In
**/ 
template<typename T>
void BinTree<T>::ins_left_son(pos In)
{

	if (empty_left_son(In))
	{
		In->_setLson(new Cell<T>);
		In->_getLson()->_setDad(In);
		In->_getLson()->_setLson(nullptr);
		In->_getLson()->_setRson(nullptr);
	}
	else throw NodeExisting();

}

/**
* insert right son at position: In
**/ 
template<typename T>
void BinTree<T>::ins_right_son(pos In)
{
	if (empty_right_son(In))
	{
		In->_setRson(new Cell<T>);
		In->_getRson()->_setDad(In);
		In->_getRson()->_setLson(nullptr);
		In->_getRson()->_setRson(nullptr);
	}
	else throw NodeExisting();

}


/**
* delete the tree at position: In
**/ 
template<typename T>
void BinTree<T>::delete_subtree(pos In)
{
	if (In != nullptr) {
		if (!empty_left_son(In))
			delete_subtree(left_son(In));
		if (!empty_right_son(In))
			delete_subtree(right_son(In));

		if (In != _root)
		{

			if (left_son(dad(In)) == In)
				dad(In)->_setLson(nullptr);
			else
				dad(In)->_setRson(nullptr);
		}
		else _root = nullptr;

	}
	else throw NullNode();
}


/**
* get the hight at position: n
**/ 
template<typename T>
int BinTree<T>::hight(pos n) {

	if (n == nullptr) {
		return 0;
	}
	else {
		return ((hight(n->_getLson())) < hight(n->_getRson()) ? hight(n->_getRson()) + 1 : ((hight(n->_getLson())) + 1));
	}
}


/**
* return true if the element is present in the p subtree
**/ 
template<typename T>
bool BinTree<T>::search_el(Cell<T>* p, info_type el){
	if (p == nullptr) return(false);
	else if (p->_getInfo() == el) return(true);
	else return(search_el(p->_getLson(), el) || search_el(p->_getRson(), el));
}
