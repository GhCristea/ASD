#pragma once

#include"BinTreeVirtual.h"
#include"exceptions.h"

//#define NIL -1

template<typename T>
class BinaryTree :public BinTreeVirtual<T, int>
{
public:
	//types
	typedef typename BinTreeVirtual<T, int>::value_type value_type;
	typedef typename BinTreeVirtual<T, int>::Node Node;

  struct _cell
	{
		Node parent_;
		Node sx;
		Node dx;
		value_type value_;
	};
	
	typedef struct _cell Cell;

	BinaryTree  ();//constructor
	BinaryTree(size_t);//constructor
	~BinaryTree  ();//distructor

	//operators
	void create();
	bool empty()const { return(number_of_nodes == 0); }

	Node root()const { return (_root); }
	Node parent(Node n)const { return (n != _root) ? _space[n].parent_ : n; }
	Node sx(Node n)const { return((sx_empty(n)) ? n: _space[n].sx  ); }
	Node dx(Node n)const { return((dx_empty(n)) ? n : _space[n].dx); }
	
	bool sx_empty(Node n)const { return(_space[n].sx == NIL); }
	bool dx_empty(Node n)const { return(_space[n].dx == NIL); }
	
	void erase(Node);

	T read(Node)const;
	void write(Node, value_type);

	void ins_root(Node);
	void ins_sx(Node);
	void ins_dx(Node);
	
private:
	size_t MAX_LENGTH;
	Cell * _space;
	size_t number_of_nodes;
	Node _root;
	Node empty_node;
};

template<typename T>
BinaryTree<T> ::BinaryTree()
{
	MAX_LENGTH = 100;
	_space = new Cell[MAX_LENGTH];
	create();
}

template<typename T>
BinaryTree<T> ::BinaryTree(size_t n_nodes):MAX_LENGTH(n_nodes)
{
	_space = new Cell[MAX_LENGTH];
	create();
}

template<typename T>
BinaryTree<T> ::~BinaryTree()
{
	if(!empty())
		erase(_root);
	
	delete [] _space;
}

template<typename T>
void BinaryTree<T>::create()
{
	_root = NIL;
	for (size_t i = 0; i < MAX_LENGTH; i++)
		_space[i].sx = (i + 1) % MAX_LENGTH;

	empty_node = 0;
	number_of_nodes = 0;
}


template<typename T>
void BinaryTree<T>::erase(Node n)
{
	
	if (n != NIL)
	{

		if (!sx_empty(n))
			erase(_space[n].sx);

		if (!dx_empty(n))
			erase(_space[n].dx);

		if (n != _root) 
		{
			Node p = parent(n);
			if (_space[n].sx == n)
				_space[n].sx = NIL;
			else
				_space[n].dx = NIL;
		}

		else _root = NIL;

		number_of_nodes--;
		_space[n].sx = empty_node;
		empty_node = n;
	}

	else	
		throw NullNode();
}


template<typename T>
T BinaryTree<T>::read(Node n)const
{
	if (n != NIL)
		return(_space[n].value_);
	else
		throw NullNode();
}

template<typename T>
void BinaryTree<T>::write(Node n, value_type a)
{
	if (n != NIL)
		_space[n].value_ = a;
	else
		throw NullNode();
}

template<typename T>
void BinaryTree<T>::ins_root(Node n)
{
	
	if (_root == NIL)
	{
		_root = n;
		empty_node = _space[empty_node].sx;
		_space[_root].sx = _space[_root].dx = NIL;
		
		number_of_nodes++;
	}
	else throw RadiceEsistente();
}


template<typename T>
void BinaryTree<T>::ins_sx(Node n)
{
	if (_root == NIL) throw EmptyTree();
	if (n == NIL) throw NullNode();
	if (_space[n].sx != NIL) throw ExistingNode();
	if (number_of_nodes >= MAX_LENGTH) throw MaxDim();
	else
	{
		Node q = empty_node;
		empty_node = _space[empty_node].sx;
		_space[n].sx = q;
		_space[q].parent_ = n;
		_space[q].dx = _space[q].sx = NIL;//doesn't have children
		number_of_nodes++;
	}
}


template <typename T>
void BinaryTree<T>::ins_dx(Node n)
{
	if (_root == NIL) throw EmptyTree();
	if (n == NIL) throw NullNode();
	if (_space[n].dx != NIL) throw ExistingNode();
	if (number_of_nodes >= MAX_LENGTH) throw MaxDim();

	else
	{
		Node q = empty_node;
		empty_node = _space[empty_node].sx;
		_space[n].dx = q;
		_space[q].parent_ = n;
		_space[q].dx = _space[q].sx = NIL;//doesn't have children
		number_of_nodes++;
	}

}