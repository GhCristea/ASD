// albBinLink.cpp : definisce il punto di ingresso dell'applicazione console.
//

#include "stdafx.h"
#include"BinaryTree.h"
#include<string>
#include"utilBinaryTree.h"

using namespace std;


int main()
{
	int k = 1;
	Alb_bin<int> MyBinTree;
	Cell<int> *n = new Cell<int>;
	MyBinTree.ins_root(n);
	MyBinTree.write(MyBinTree.root(), 1);
	
	MyBinTree.ins_left_son(n);
	MyBinTree.ins_right_son(n);
	MyBinTree.write(MyBinTree.left_son(n), 2);
	MyBinTree.write(MyBinTree.right_son(n), 3);

	n = MyBinTree.left_son(n);
	MyBinTree.ins_left_son(n);
	MyBinTree.ins_right_son(n);
	MyBinTree.write(MyBinTree.left_son(n), 4);
	MyBinTree.write(MyBinTree.right_son(n), 5);

	n = MyBinTree.right_son(MyBinTree.dad(n));
	MyBinTree.ins_left_son(n);
	MyBinTree.ins_right_son(n);
	MyBinTree.write(MyBinTree.left_son(n), 6);
	MyBinTree.write(MyBinTree.right_son(n), 7);

	//cout << MyBinTree.altezza(MyBinTree.root());
	//MyBinTree.BFS(MyBinTree.root());
	//cout << MyBinTree;
	//cout << endl;
	//cout << odd(MyBinTree, k);
	//cout << endl;
	//cout << even_leafs(MyBinTree);
	//cout << endl;
	//cout << leafs_with_even_parent(MyBinTree);
	//cout << (MyBinTree.search_el(MyBinTree.root(), 8) ? "true" : "false");
	 //MyBinTree.invisit(MyBinTree.root());
	//MyBinTree.previsit(MyBinTree.root());
	//cout<<number_of_leafs(MyBinTree, MyBinTree.root());
	cout << "\n\n\n";
	system("pause");
    return 0;
}


