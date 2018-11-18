#pragma once

#include"nTreeVirtual.h"
#include"Cell.h"
#include"exceptions.h"

#include".\Projects\Queue\Queue\Queue.h"

template<typename T>
class NTree:public Tree<T, Cell<T>*>
{
public:
	//types
	using Node = Cell<T>*;
	typedef typename Cell<T>::info_type info_type;

	NTree() { create(); }
	//~NTree() { (!leaf(root())) ? rem_subtree(root()) : delete root(); }

	//operators
	void create() { _root = nullptr; }
	bool empty()const { return(_root == nullptr); }
	void set_root(Node In);
	Node root()const { return((!empty()) ? _root : nullptr); }
	Node parent(Node In)const { return( (In != _root)? In->_getParent() : throw NullNode());  }
	bool leaf(Node In)const { return(In->_getFistChild() == nullptr); }//doesn't have cildrens <=> is a leaf	
	
	void ins_first_child(Node In);
	void ins_next_sibling(Node In);

	Node first_child(Node In)const {return ((In->_getFistChild() != nullptr)? In->_getFistChild(): nullptr); }
	bool last_sibling(Node In)const {  return(In->_getNextSibling() == nullptr); }
	Node next_sibling(Node In)const { return (!last_sibling(In))? (In->_getNextSibling()): nullptr; }
	void rem_subtree(Node);
	
	void insert_first_subtree(Node, NTree<T>&);
	void insert_subtree(Node, NTree<T>&);
	
	void write_Node(Node In, info_type InfoIn) { if (In!=nullptr) In->_setInfo(InfoIn); }
	info_type read_Node(Node In)const { return In->_getInfo(); } 
	

	void bfs(Node n);
	void dfs(Node n);
private:
	Node _root;
};


template<typename T>
void NTree<T>::set_root(Node In)
{
	if (empty()) {
		_root = In;
		_root->_setParent(nullptr);
		_root->_setFirstChild(nullptr);
		_root->_setNextSibling(nullptr);
	}
	else throw RootParent();
}

template<typename T>
void NTree<T>::ins_first_child(Node In)
{
	if(leaf(In))
	{
		In->_setFirstChild(new Cell<T>);
		In->_getFistChild()->_setParent(In);
		In->_getFistChild()->_setFirstChild(nullptr);
		In->_getFistChild()->_setNextSibling(nullptr);
	}

	else throw ExistingNode();
}

template<typename T>
void NTree<T>::ins_next_sibling(Node In)
{
	if (In->_getNextSibling() == nullptr)
	{
		In->_setNextSibling(new Cell<T>);
		In->_getNextSibling()->_setNextSibling(nullptr);
		In->_getNextSibling()->_setParent(In->_getParent());
		In->_getNextSibling()->_setFirstChild(nullptr);

	}
	else throw ExistingNode();
}

template<typename T>
void NTree<T>::insert_first_subtree(Node In, NTree<T>& inTree)
{
	if (!inTree.empty())
	{

		inTree.root()->_setNextSibling(In->_getFistChild());//first son of In ---> sibling of the root of inTree
		inTree.root()->_setParent(In);//In ---> parent of the inTree root
		In->_setFirstChild(inTree.root());//the root of inTree ---> first son of In 

	}
	else throw EmptyTree();
}

template<typename T>
void NTree<T>::insert_subtree(Node In, NTree<T>& inTree) 
{
	if(!inTree.empty())  
	{
		if (In != root()) {
			inTree.root()->_setNextSibling(In->_getNextSibling());//sibling of In ---> sibling of the inTree root
			inTree.root()->_setParent(In);//In ---> parent of the inTree root
			In->_setNextSibling(inTree.root());//the root of inTree ---> next son of In 
		}
	}
	else throw EmptyTree();
}

template<typename T>
void NTree<T>::rem_subtree(Node In)
{
	if (In == root())
		delete _root;

	else
	{
		if (In == first_child(parent(In)))//In is the first son
		{
			if (last_sibling(In))
				parent(In)->_setFirstChild(nullptr);
			else
				parent(In)->_setFirstChild(next_sibling(In));//next sibling of In become first son
		}

		else
		{
			Node prev = first_child(parent(In));
			Node curr = next_sibling(prev);

			while (curr != In)
			{
				prev = curr;
				curr = next_sibling(curr);
			}
			if (last_sibling(In))
				prev->_setNextSibling(nullptr);
			else
				prev->_setNextSibling(next_sibling(In));//if In not last son
		}
	}
}


template<typename T>
void NTree<T>::bfs(Node n) {
	Coda<Node> C;
	C.push(n);//memorize the node
	while (!C.empty()) {
		Node i = C.leggi();//catch the node
		cout << i << " ";
		C.pop();//node in use, pop from queue
		if (!leaf(i)) {//if the node is not a leaf
			Node k = first_child(i);//go to first son
			while (k != nullptr) {
				C.push(k);//push every son
				k = next_sibling(k);

			}
		}
	}
}


template<typename T>
void NTree<T>::dfs(Node n)
{
	cout << n << " ";
	if (!leaf(n)) {
		Node k = first_child(n);
		dfs(k);
		while (!last_sibling(k)) {
			k = next_sibling(k);
			dfs(k);
		}
	}
}











