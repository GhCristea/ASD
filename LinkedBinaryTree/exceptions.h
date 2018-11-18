#pragma once
#include<stdexcept>

using std::invalid_argument;
using std::domain_error;

struct NullNode :public invalid_argument
{
	NullNode() :invalid_argument("Null parameter!\n") {}
};

struct RootExisting : public domain_error 
{
	RootExisting() :domain_error("The root already exists!\n"){}
};

struct EmptyTree :public domain_error
{
	EmptyTree() :domain_error("Empty tree!\n"){}
};

struct NodeExisting :public domain_error
{
	NodeExisting() :domain_error("The node already exists!\n"){}
};