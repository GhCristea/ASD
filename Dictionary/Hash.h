#pragma once
#include<string>

using std::string;

using HashValue = size_t;

HashValue _hash(string str)
{
	HashValue _hash = 5381;
	
	size_t l = str.length();

	for (size_t i = 0; i < l; i++)
	{
		size_t c = str[i];
		_hash = _hash * 33 + c;
	}
	return _hash;
}