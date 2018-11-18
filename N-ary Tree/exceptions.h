#pragma once
#include<stdexcept>

using std::invalid_argument;
using std::domain_error;

struct NullNode :public invalid_argument
{
	NullNode() :invalid_argument("Parametro Nullo!\n") {}
};


struct ExistingRoot : public domain_error 
{
	ExistingRoot() :domain_error("The root already exits!\n"){}
};

struct EmptyTree :public domain_error
{
	EmptyTree() :domain_error("The tree is empty!\n"){}
};

struct ExistingNode :public domain_error
{
	ExistingNode() :domain_error("The node already exits!\n"){}
};


struct RootParent :public invalid_argument
{
	RootParent() :invalid_argument("The root can't have a parent!\n") {}
};

