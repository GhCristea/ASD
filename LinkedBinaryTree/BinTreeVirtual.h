#pragma once
#include<iostream>
#include"Queue.h"
#define NIL -1

using std::cout;

template<typename T, typename N>
class BinTreeVirtual{

public:
	typedef T info_type ;
	typedef N Node;

	//operators

	virtual void create() = 0;
	virtual bool empty()const = 0;

	virtual Node root()const = 0;
	virtual Node dad(Node)const = 0;
	virtual Node left_son(Node)const = 0;
	virtual Node right_son(Node)const = 0;
	
	virtual bool empty_left_son(Node)const = 0;
	virtual bool empty_right_son(Node)const = 0;

	
	virtual void delete_subtree(Node) = 0;
	
	virtual T read(Node)const = 0;
	virtual void write(Node, const info_type) = 0;

	virtual void ins_root(Node) = 0;
	virtual void ins_left_son(Node) = 0;
	virtual void ins_right_son(Node) = 0;

	virtual void invisit(Node);
	virtual void previsit(Node);
	
	void BFS(Node p) const;
	
	virtual void print()const;
private:
	virtual void print_sub_Tree(const Node)const;
};

/**
*print tree
**/
template<typename T, typename N>
void BinTreeVirtual<T, N>::print()const {
	if (!empty())
		print_sub_Tree(root());
	else
		cout << "[]\n\n";
}

/**
*print subtree
**/
template<typename T, typename N>
void BinTreeVirtual<T, N>::print_sub_Tree(const Node n)const {
	if (n != nullptr) {
		cout << "[ " << n << ", ";

		if (!empty_left_son(n)) print_sub_Tree(left_son(n));
		else cout << "NIL";

		cout << ", ";

		if (!empty_right_son(n)) print_sub_Tree(right_son(n));
		else cout << "NIL";

		cout << " ]";
	}
}
/**
*cout operator overload
**/
template<typename T, typename N>
std::ostream& operator<<(std::ostream& print, const BinTreeVirtual<T, N>& t) {
	t.print();
	return print;
}

/**
* Breath First Search
**/
template <class T, class N>
void BinTreeVirtual<T, N>::BFS(Node p) const {
	Queue<N> q;
	q.push(p);
	//int lev = 1;
	while (!q.empty()) {
		p = q.read();
		q.pop();
		info_type a = read(p);
		cout << a << " ";
		if (!empty_left_son(p)) {
			q.push(left_son(p));
		}
		if (!empty_right_son(p)) {
			q.push(right_son(p));
		}
	}
}

template <typename T,typename N>
void BinTreeVirtual<T,N>::invisit(Node p) {
	if (p != nullptr) {
		if (!empty_left_son(p))
			invisit(left_son(p));

		info_type a = read(p);
		cout << a << " ";
		if (!empty_right_son(p))
			invisit(right_son(p));
	}
}

template <typename T, typename N>
void BinTreeVirtual<T, N>::previsit(Node p) {
	if (p != nullptr) {
		info_type a = read(p);
		cout << a << " ";
		if (!empty_left_son(p))
			previsit(left_son(p));
		if (!empty_right_son(p))
			previsit(right_son(p));
	}
}