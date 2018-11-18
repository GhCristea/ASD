#pragma once

#include"nTree.h"

//returns the sum of all nodes of level level
int sum_level(NTree<int> &tree, Cell<int>* n, int level) {
	int sum = 0;

	if (level == 0)
		return tree.read_node(n);
	else {
		n = tree.first_child(n);
		while (!tree.last_sibling(n)) {
			sum += sum_level(tree, n, level - 1);
			n = tree.next_sibling(n);
		}

		sum += sum_level(tree, n, level - 1);
	}

	return sum;
}

int sum_level(NTree<int> &tree, int level) {
	return sum_level(tree, tree.root(), level);
}




void avverage_level_value(NTree<int> tree ,Cell<int>* n, Queue<int> &ls, int level, int curr) {
	if (n != nullptr && curr <= level) {
		while (n != nullptr) {
			if (level == curr)
				ls.push(n->_getInfo());

			avverage_level_value(tree,tree.first_child(n), ls, level, curr + 1);
			n = tree.next_sibling(n);
		}
	}
}


void media(NTree<double> tree, Cell<double>* n) {
	double sum = 0;
	int e = 0;
	double S = 0;
	int E = 0;

	if (!tree.leaf(n))
	{
		Cell<double>* p = tree.first_child(n);
		do {
			sum = 0;
			e = 0;
			media(tree, p);
			S = S + sum;
			E = E + e;
			p = tree.next_sibling(p);
		} while (!tree.last_sibling(p));
		sum = S + tree.read_node(n);
		e = E + 1;
		tree.write_node(n, S / e);
	}
	else {
		sum = tree.read_node(n);
		e = 1;
	}
}

//counts the internal nodes
int internal_nodes(NTree<double> A, Cell<double> * n) {
	int count = 0;
	Cell<double> * k = new Cell<double>;

	k = A.first_child(n);

	if (!A.leaf(n)) {
		count += internal_nodes(A, k);
		while (!A.last_sibling(k))
		{
			k = A.next_sibling(k);
			count += internal_nodes(A, k);
		}
	}
	return ((A.leaf(n)) ? count : count + 1);
}

//counts the nodes of even level
int even_level_nodes(NTree<double> tree) {
	struct cell { Cell<double> *n; int l; };
	Queue<cell> C;
	cell k;
	k.n = tree.root();
	k.l = 0;

	int current_level = 0;
	int acc = 0;

	C.push(k);
	while (!C.empty())
	{
		cell h;
		h = C.leggi();
		C.pop();

		if (h.l != current_level)
			current_level++;

		if ((current_level % 2) == 0)
			acc++;

		if (!tree.leaf(h.n))
		{
			Cell<double>* i = tree.first_child(h.n);
			while (i != nullptr)
			{
				cell g;
				g.n = i;
				g.l = h.l + 1;
				C.push(g);
				i = tree.next_sibling(i);
			}
		}
	}
	return acc;
}

//counts the nodes of odd level
int odd_level_nodes(NTree<double> tree) {
	struct cell { Cell<double> *n; int l; };
	Queue<cell> C;
	cell k;
	k.n = tree.root();
	k.l = 0;

	int current_level = 0;
	int acc = 0;

	C.push(k);
	while (!C.empty())
	{
		cell h;
		h = C.leggi();
		C.pop();

		if (h.l != current_level)
			current_level++;

		if ((current_level % 2) != 0)
			acc++;

		if (!tree.leaf(h.n))
		{
			Cell<double>* i = tree.first_child(h.n);
			while (i != nullptr)
			{
				cell g;
				g.n = i;
				g.l = h.l + 1;
				C.push(g);
				i = tree.next_sibling(i);
			}
		}
	}
	return acc;
}

//retrieve the max value in a given n-ary tree tree
double max_val(NTree<double> tree)
{
	Queue<Cell<double>*> C;

	double max = tree.read_node(tree.root());
	C.push(tree.root());
	while (!C.empty())
	{
		Cell<double>* h;
		h = C.leggi();
		C.pop();
		if (tree.read_node(h) > max)
			max = tree.read_node(h);

		if (!tree.leaf(h))
		{
			Cell<double>* i = tree.first_child(h);
			while (i != nullptr)
			{
				C.push(i);
				i = tree.next_sibling(i);
			}
		}
	}
	return max;
}

//retrieve the min value in a given n-ary tree tree
double min_val(NTree<double> tree)
{
	Queue<Cell<double>*> C;

	double min = tree.read_node(tree.root());
	C.push(tree.root());
	while (!C.empty())
	{
		Cell<double>* h;
		h = C.leggi();
		C.pop();
		if (tree.read_node(h) < min)
			min = tree.read_node(h);

		if (!tree.leaf(h))
		{
			Cell<double>* i = tree.first_child(h);
			while (i != nullptr)
			{
				C.push(i);
				i = tree.next_sibling(i);
			}
		}
	}
	return min;
}

//see if the value x is present in the tree
bool presente(NTree<double> tree, double x)
{
	Queue<Cell<double>*> C;
	C.push(tree.root());
	
	while (!C.empty()) {
		Cell<double>* h = C.leggi();
		C.pop();
		if (x == tree.read_node(h))
			return true;
		if (!tree.leaf(h)) {
			Cell<double>* i = tree.first_child(h);
			while (i != nullptr)
			{
				C.push(i);
				i = tree.next_sibling(i);
			}

		}
	}
	return false;
}

//calculate the tree deep
template<typename T>
int tree_deep(NTree<T> tree, Cell<T>* n)
{
	int cont = 0;
	int max = 0;

	if (tree.leaf(n))
		return 0;
	
	Cell<T>* m = tree.first_child(n);
	while (m != nullptr)
	{
		cont = tree_deep(tree, m);
		if (cont > max)
			max = cont;
		m = tree.next_sibling(m);
	}
	return max+1;
}

//calculate the tree width
template<typename T>
int tree_width(NTree<T> tree)
{
	struct cell { Cell<T> * n; int l; };
	Queue<cell> C;

	cell k;
	k.n = tree.root();
	k.l = 1;

	int current_level = 1;
	int max = 0;
	int acc = 0;

	C.push(k);
	while (!C.empty())
	{
		cell h = C.leggi();
		C.pop();

		if (h.l == current_level)
			acc++;
		if (h.l != current_level)
		{
			if (acc > max)
				max = acc;
			current_level++;
			acc = 1;
		}
		
		if (!tree.leaf(h.n))
		{
			Cell<T>* i = tree.first_child(h.n);
			while (i != nullptr)
			{
				cell g;
				g.n = i;
				g.l = h.l + 1;
				C.push(g);
				i = tree.next_sibling(i);
			}
		}
	}
	return max;
}

template<typename T>
int number_of_leaves(NTree<T> A, Cell<T> * R)
{
	//R = A.root();
	if (R == nullptr) return 0;
	
	if (A.leaf(R))
		return 1 + number_of_leaves(A, A.next_sibling(R));
	else
		return(number_of_leaves(A, A.first_child(R)) +
			number_of_leaves(A, A.next_sibling(R)));
}

template<typename T>
int nodiKFigli(NTree<T> A, Cell<T> * R, int k)
{
	int kl = 0;
	Cell<T> * temp = nullptr;
	//NTree<T> temp;
	if (R == nullptr) return 0;

	else
	{
		temp = A.first_child(R);
		while (temp != nullptr)
		{
			kl++;
			temp = A.next_sibling(temp);
		}
		return((k == kl) ? (1 + nodiKFigli(A, A.next_sibling(R), k)+ nodiKFigli(A, A.first_child(R), k)) :
			(nodiKFigli(A, A.next_sibling(R), k)+ nodiKFigli(A, A.first_child(R), k)));
	}

}


//check if every even node has only odd children

int paridispari(NTree<int> A, Cell<int> * R)
{
	Cell<int> * tmp = nullptr;
	int ris = 1;
	if (R == nullptr)
		return 1;

	if (A.read_node(R) % 2)// !(read(R)%2 == 0) <=> node is odd
	{
		tmp = A.first_child(R);
		while (tmp != nullptr)
		{
			ris = ris && paridispari(A,tmp);
			tmp = A.next_sibling(tmp);
		}
		return ris;
	}
	else//node is even
	{
		tmp = A.first_child(R);
		while (tmp != nullptr)
		{
			ris = ris && (tmp->_getInfo() % 2) && paridispari(A,tmp);
			tmp = A.next_sibling(tmp);
		}
		return ris;
	}
}