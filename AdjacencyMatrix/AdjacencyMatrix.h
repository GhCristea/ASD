#pragma once

#include"GraphVirtual.h"

// Vertex info
template<typename P>
class InfoVertex
{
public:
	P weight;
	bool vuoto;
	InfoVertex
() {
		vuoto = true;
	}
};

// Edge info
template<typename E, typename P>
class InfoEdge
{
public:
	
	E label;
	bool vuoto;
	void* info;
	InfoVertex
<P>* vertices;
	
	InfoEdge()
	{
		info = 0;
		vuoto = true;
	}

	~InfoEdge()
	{
		if (!vuoto)
			delete[] vertices;
	}

};


//classe Edge
class Edge
{
public:
	Edge(size_t i) { edgeId = i; }
	Edge() { ; }
	int getId() { return edgeId; }
	void setId(size_t id) { edgeId = id; }
private:
	size_t edgeId;
};

template<typename E, typename P>
class AdjacencyMatrix :public Graph<E, P, Edge>
{
public:

	//tipi
	
	typedef typename Graph<E, P, Edge>::label label;
	typedef typename Graph<E, P, Edge>::weight Weight;
	typedef Edge Edge;
	typedef typename Graph<E, P, Edge>::EdgeList EdgeList;

	//constructor
	AdjacencyMatrix(size_t);
	//distructor
	~AdjacencyMatrix() { delete[] _matrice; }

	//operators

	bool empty()const { return (_nodi == 0); }
	
	void insert_edge(Edge&);
	void insert_vertex(Edge, Edge, Edge);
	
	void rem_node(Edge);
	void rem_vertex(Edge, Edge);

	EdgeList adjacent(Edge) const;

	label read_label(Edge n)const { return _matrice[n.getId()].label; }
	void write_label(Edge n, label e) { _matrice[n.getId()].label = e; }

	weight read_weight(Edge n1, Edge n2)const { return _matrice[n1.getId()].vertices[n2.getId()].weight; }
	void write_weight(Edge n1, Edge n2, weight p) { _matrice[n1.getId()].vertices[n2.getId()].weight = p; }

	EdgeList edges_list()const;
	size_t n_nodi()const { return _nodi; }
	size_t n_vertices()const { return _vertices; }
private:
	InfoEdge<E, P> * _matrice;
	size_t _dimention;
	size_t _nodi;
	size_t _vertices;
};

template<typename E, typename P>
AdjacencyMatrix<E, P>::AdjacencyMatrix(size_t dim)
{
	_dimention = dim;
	_nodi = 0;
	_vertices = 0;
	_matrice = new InfoEdge<E, P>[_dimention];

	for (size_t i = 0; i < _dimention; i++)
		_matrice[i].vertices = new InfoVertex
<P>[_dimention];

}

template<typename E, typename P>
void AdjacencyMatrix<E, P>::insert_edge(Edge& N)
{
	size_t n = 0;

	if (_nodi < _dimention)
	{
		while (!_matrice[n].vuoto)
			n++;
		_nodi++;
		_matrice[n].vuoto = false;
	}
	N.setId(n);
}


template<typename E, typename P>
void AdjacencyMatrix<E, P>::insert_vertex(Edge n1, Edge n2, weight p)
{
	_matrice[n1.getId()].vertices[n2.getId()].weight = p;
	_matrice[n1.getId()].vertices[n2.getId()].vuoto = false;

	_vertices++;
}


template<typename E, typename P>
void AdjacencyMatrix<E, P>::rem_node(Edge n)
{
	bool canc = true;
	size_t i;

	for (i = 0; (i < _dimention) && canc; i++)
	{
		if (!_matrice[n.getId()].vertices[i].vuoto)
			canc = false;
	}


	for (i = 0; (i < _dimention) && canc; i++)
	{
		if (!_matrice[i].vuoto && !_matrice[i].vertices[n.getId()].vuoto)
			canc = false;
	}

	//
	if (canc)
	{
		delete _matrice[n.getId()].vertices;
		_matrice[n.getId()].vuoto = true;
	}

}

template<typename E, typename P>
void AdjacencyMatrix<E, P>::rem_vertex(Edge n1, Edge n2)
{
	_matrice[n1.getId()].vertices[n2.getId()].vuoto = true;
	_vertices--;
}


template<class E, class P>
typename AdjacencyMatrix<E, P>::EdgeList AdjacencyMatrix<E, P>::adjacent(Edge n) const {
	EdgeList l;

	for (size_t i = 0; i < _dimention; i++) {
		if (!_matrice[n.getId()].vertices[i].vuoto) {
			l.insert(new Edge(i), l.begin());
		}
	}
	return l;
}

template<class E, class P>
typename AdjacencyMatrix<E, P>::EdgeList AdjacencyMatrix<E, P>::edges_list() const
{
	EdgeList l;

	for (size_t i = 0; i < _dimention; i++)
	{
		if (_matrice[i].vuoto)
			l.insert(new Edge(i), l.begin());
	}
	return l;
}

