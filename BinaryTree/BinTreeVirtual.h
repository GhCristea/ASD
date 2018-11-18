#pragma once
#include<iostream>

#define NIL -1

using std::cout;

template<typename T, typename N>
class Alb_bin_virt{
	//friend ostream& operator<<(std::ostream& , const Alb_bin_virt<T, N>& );
public:
	typedef T value_type ;
	typedef N Nodo;

	//operatori

	virtual void create() = 0;
	virtual bool empty()const = 0;

	virtual Nodo root()const = 0;
	virtual Nodo parent(Nodo)const = 0;
	virtual Nodo sx(Nodo)const = 0;
	virtual Nodo dx(Nodo)const = 0;
	
	virtual bool sx_empty(Nodo)const = 0;
	virtual bool dx_empty(Nodo)const = 0;

	//virtual void constr(Alb_bin<T, N>&);
	
	virtual void erase(Nodo) = 0;
	
	virtual T read(Nodo)const = 0;
	virtual void write(Nodo, value_type) = 0;

	virtual void ins_root(Nodo) = 0;
	virtual void ins_sx(Nodo) = 0;
	virtual void ins_dx(Nodo) = 0;

	//funz servizio implemantare qui
	/*
	virtual void previsit(Nodo);
	virtual void invisit(Nodo);
	virtual void postvisit(Nodo);
	*/
	virtual void print()const;
private:
	virtual void printSubTree(const Nodo)const;
};

template<typename T, typename N>
void Alb_bin_virt<T, N>::print()const {
	if (!empty())
		printSubTree(root());
	else
		cout << "[]\n\n";
}

template<typename T, typename N>
void Alb_bin_virt<T, N>::printSubTree(const Nodo n)const {
	cout << "[ " << n << ", ";
	
	if (!sx_empty(n)) printSubTree(sx(n));
	else cout << "NIL";

	cout << ", ";

	if (!dx_empty(n)) printSubTree(dx(n));
	else cout << "NIL";

	cout << " ]";
}

template<typename T, typename N>
std::ostream& operator<<(std::ostream& stampa, const Alb_bin_virt<T, N>& t) {
	t.print();
	return stampa;
}