#pragma once
#include<stdexcept>

using std::domain_error;


struct List_por :public domain_error
{
	//posizione lista out-of-range
	List_por() :domain_error("Position out of range"){}

};