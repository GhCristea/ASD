// AlberoNare.cpp : definisce il punto di ingresso dell'applicazione console.
//

#include "stdafx.h"
#include"nTree.h"
#include"nTreeUtil.h"

using namespace std;

int main()
{
	NTree<int> a;
	NTree<int>::node p=new Cell<int>;
	NTree<int>::node p2 = new Cell<int>;
	a.set_root(p); 
	a.write_node(p, 1);

	a.ins_first_child(p);
	p = a.first_child(p);
	a.write_node(p, 11);

	a.ins_next_sibling(p);
	p2 = a.next_sibling(p);
	a.write_node(p2, 12);
	
	a.ins_next_sibling(p2);
	p2 = a.next_sibling(p2);
	a.write_node(p2, 13);

	a.ins_next_sibling(p2);
	p2 = a.next_sibling(p2);
	a.write_node(p2, 14);

	a.ins_next_sibling(p2);
	p2 = a.next_sibling(p2);
	a.write_node(p2, 15);
	
	a.ins_next_sibling(p2);
	p2 = a.next_sibling(p2);
	a.write_node(p2, 16);


	a.ins_first_child(p2);
	p2 = a.first_child(p2);
	a.write_node(p2, 161);


	a.ins_first_child(p);
	p = a.first_child(p);
	a.write_node(p, 111);

	a.ins_next_sibling(p);
	p = a.next_sibling(p);
	a.write_node(p, 112);

	
	a.ins_next_sibling(p);
	p = a.next_sibling(p);
	a.write_node(p, 113);

	a.ins_next_sibling(p);
	p = a.next_sibling(p);
	a.write_node(p, 114);
	
	a.ins_next_sibling(p);
	p = a.next_sibling(p);
	a.write_node(p, 115);

	a.ins_first_child(p);
	p = a.first_child(p);
	a.write_node(p, 1151);

	a.ins_first_child(p);
	p = a.first_child(p);
	a.write_node(p, 1161);

	a.ins_next_sibling(p);
	p = a.next_sibling(p);
	a.write_node(p, 1162);

	//cout << min_val(a) << endl;
	//cout << max_val(a)<<endl;
	//cout << nodiLivPari(a)<<endl;
	//cout<<interni(a, a.root());
	//media(a, a.root());
	//a.postorder(a.root());
	//cout << presente(a, 300) << endl;
	//cout << profondita(a, a.root()) << endl;
	//cout << larghezza(a)<<endl;
	//cout << numero_foglie(a, a.root());
	//a.bfs(a.root());
	//a.print_subtree(a.root());
	//cout << sommaLev(a, 5);
	//a.dfs(a.root());

	//cout<<paridispari(a, a.root());

	cout << "\n\n";
	system("pause");
    return 0;
}




