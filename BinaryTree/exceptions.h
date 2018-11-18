#pragma once
#include<stdexcept>

using std::invalid_argument;
using std::domain_error;

struct NullNode :public invalid_argument
{
	NullNode() :invalid_argument("Null Parameter!\n") {}
};

struct MaxDim: public invalid_argument
{
	MaxDim() :invalid_argument("Maximum dimension reached!\n") {}
};

struct ExistingRoot : public domain_error 
{
	ExistingRoot() :domain_error("The root already exists!\n"){}
};

struct EmptyTree :public domain_error
{
	EmptyTree() :domain_error("The tree is empty!\n"){}
};

struct ExistingNode :public domain_error
{
	ExistingNode() :domain_error("The node already exists!\n"){}
};
