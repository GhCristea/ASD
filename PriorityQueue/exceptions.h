#pragma once
#include<stdexcept>

using std::invalid_argument;
using std::domain_error;

struct NegativeLEngth :public invalid_argument
{
	NegativeLEngth() :invalid_argument("The legth can't be negative\n") {}
};


struct FullQueue : public domain_error
{
	FullQueue() :domain_error("Can't insert, the queue is full!\n") {}
};

struct EmptyQueue :public domain_error
{
	EmptyQueue() :domain_error("Can't read, the queue is empty!\n") {}
};
