#pragma once
#include<stdexcept>

using std::invalid_argument;
using std::domain_error;

struct NodoNullo :public invalid_argument
{
	NodoNullo() :invalid_argument("Parametro Nullo!\n") {}
};

struct DimRaggiunta: public invalid_argument
{
	DimRaggiunta() :invalid_argument("Dimensione massima raggiunta!\n") {}
};

struct RadiceEsistente : public domain_error 
{
	RadiceEsistente() :domain_error("La radice e' gia' presente!\n"){}
};

struct AlberoVuoto :public domain_error
{
	AlberoVuoto() :domain_error("L'albero e' vuoto!\n"){}
};

struct NodoEsistente :public domain_error
{
	NodoEsistente() :domain_error("Il nodo e' gia' presente!\n"){}
};