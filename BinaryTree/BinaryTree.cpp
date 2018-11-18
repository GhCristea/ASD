// AlberoBinario.cpp : definisce il punto di ingresso dell'applicazione console.
//

#include "stdafx.h"
#include"albero_binario.h"

using namespace std;



int main()
{
	
	Alb_binario<int> alb(20);
	Alb_binario<int>::Nodo n1 = 1, n2 = 2, n3=3;
	

	alb.ins_root(n1);
	alb.ins_dx(n1);
	alb.write(alb.dx(n1), 2);
	alb.write(alb.sx(n1), 3);
	//alb.write(alb.sx(alb.root()), 2);
	//alb.ins_dx(alb.root());
	//alb.write(alb.dx(alb.root()), 3);
	//alb.print();


	cout << endl;

	cout << alb;

	//alb.write(n3, 3);
	
	cout << endl;
	system("pause");
    return 0;
}

