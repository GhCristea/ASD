#pragma once
#include<iostream>

using std::cout;
using std::endl;

template<class T, class N>
class Tree {
public:
	//types
	using info_type = T;
	using node = N;

	//operators
	virtual void create() = 0;
	virtual bool empty() const = 0;
	virtual void set_root(node) = 0;
	virtual node root() const = 0;
	virtual node parent(node) const = 0;
	virtual bool leaf(node) const = 0;
	virtual node first_child(node) const = 0;
	virtual bool last_sibling(node) const = 0;
	virtual node next_sibling(node) const = 0;


	virtual void rem_subtree(node) = 0;
	virtual void write_node(node, info_type) = 0;
	virtual info_type read_node(node) const = 0;
	
	virtual void dfs(node) = 0;
	virtual void bfs(node) = 0;
	
	virtual void postorder(node);
	virtual void invisita(node);
	virtual void print_subtree(node);

};


template<typename T, typename N>
void Tree<T,N>::invisita(node n) {
	node k;
	if (leaf(n))
		cout << read_node(n) << endl;
	else
	{
		bool ultimo = false;
		k = first_child(n);
		invisita(k);
		cout << read_node(n) << endl;
		if (last_sibling(k))
			ultimo = true;

		while (!ultimo)
		{
			k = next_sibling(k);
			
			if (last_sibling(k))
				ultimo = true;

			invisita(k);
		}
	}
}



template<typename T, typename N>
void Tree<T,N>::postorder(node n) {
	node k;
	if (!leaf(n))
	{
		bool ultimo = false;
		k = first_child(n);
		postorder(k);
		if (last_sibling(k))
			ultimo = true;
		while (!ultimo)
		{
			k = next_sibling(k);
			if (last_sibling(k))
				ultimo = true;

			postorder(k);
		}
	}
	cout << read_node(n) << endl;
}


template<typename T, typename N>
void Tree<T, N>::print_subtree(node In)
{
	if (empty()) {
		cout << "[]";
		return;
	}

	if (In->_getInfo())
		cout << "[ " << In << ", ";


	if (!leaf(In))
	{
		if (first_child(In) != nullptr)
			print_subtree(first_child(In));


		node curr = first_child(In);
		while (!last_sibling(curr))
		{
			cout << ", ";
			curr = next_sibling(curr);
			if (curr != nullptr)
				print_subtree(curr);

		}
	}
	else
		cout << "NIL";

	cout << " ]";
}
