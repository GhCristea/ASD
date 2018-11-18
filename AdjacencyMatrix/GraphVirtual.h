#pragma once

#include"ArrayList.h"

template<typename P, typename N>
struct _vertex {
	N node1_, node2_;
	P _weight;
};


template<typename E, typename P, typename N>
class Graph
{
public:
	//Types
	using Label = E;
	using Weight = P;
	using Edge = N;

	typedef _vertex<Weight, Edge> Vertex;
	typedef ArrayList<Edge*> EdgeList;
	typedef typename ArrayList<Edge*>::position list_position;
	typedef ArrayList<Vertex> ListVertex;

	//
	virtual bool empty()const = 0;
	virtual void insert_node(Edge&) = 0;
	virtual void ins_vertex(Edge, Edge, Weight) = 0;
	virtual void rem_node(Edge) = 0;
	virtual void rem_vertex(Edge, Edge) = 0;
	
	virtual EdgeList adiacenti(Edge) const = 0;
	//
	virtual EdgeList list_edges()const = 0;
	virtual Label read_label(Edge) const = 0;
	virtual void write_label(Edge, Label) = 0;
	virtual Weight read_weight(Edge, Edge)const = 0;
	virtual void write_weight(Edge, Edge, Weight) = 0;


};