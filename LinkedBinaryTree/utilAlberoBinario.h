#pragma once
#include"BinaryTree.h"

/**
* it calculates and returns the number of nodes of level k whose value is odd
**/
int odd(BinaryTree<int>& tree, Cella<int> * n, int k) {

	int sum = 0;
	if (k == 0) {
		if (tree.read(n) % 2 == 1)//odd
			sum = 1;
		else
			sum = 0;
	}

	else {
		if (!tree.empty_left_son(n))//has left son
			sum += odd(tree, tree.left_son(n), k - 1);
		if (!tree.empty_right_son(n))//has right son
			sum += odd(tree, tree.right_son(n), k - 1);
	}
	return sum;
}

/**
* it calculates and returns the number of nodes of level k whose value is odd
**/
int odd(BinaryTree<int>& tree, int k) {
	return(odd(tree, tree.root(), k));
}

/**
* it calculates and returns the number of nodes whose value is even
**/
int even_leafs(BinaryTree<int>& tree, Cella<int> * n) {
	int sum = 0;

	if (tree.leaf(n)) {
		if (tree.read(n) % 2 == 0)
			sum = 1;
		else sum = 0;
	}
	else {
		if (!tree.empty_left_son(n))
			sum += even_leafs(tree, tree.left_son(n));
		if (!tree.empty_right_son(n))
			sum += even_leafs(tree, tree.right_son(n));
	}
	return sum;
}
// 
int even_leafs(BinaryTree<int>& tree) {
	return even_leafs(tree, tree.root());
}


/**
* it calculates and returns the number of leaves that have as a parent a node whose value is even
**/
int leaves_with_even_parent(BinaryTree<int> &tree, Cella<int> *n) {
	int sum = 0;
	if (tree.leaf(n)) {
		if (tree.read(tree.dad(n)) % 2 == 0)
			sum = 1;
		else sum = 0;
	}
	else {
		if (!tree.empty_left_son(n))
			sum += leaves_with_even_parent(tree, tree.left_son(n));
		if (!tree.empty_right_son(n))
			sum += leaves_with_even_parent(tree, tree.right_son(n));
	}
	return sum;
}
//3.
int leaves_with_even_parent(BinaryTree<int> &tree) {
	return leaves_with_even_parent(tree, tree.root());
}

//4.calculate the number of leaves
int number_of_leaves(BinaryTree<int> &tree, Cella<int>* n) {
	int count = 0;
	if (n != nullptr) {
		if (tree.leaf(n)) {
			count++;
		}
		if (!tree.empty_left_son(n))
			count += number_of_leaves(tree, tree.left_son(n));

		if (!tree.empty_right_son(n))
			count += number_of_leaves(tree, tree.right_son(n));
	}
	return count;
}