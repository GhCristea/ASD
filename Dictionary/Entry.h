#pragma once

template<typename K, typename V>
class Entry
{
public:

	using value = V;
	using key = K;

	Entry(){}
	Entry(const K &_k, const V &_val):k(_k),v(_val){}

	key _getKey()const { return k; }
	value _getValue()const { return v; }

private:
	key k;
	value v;
};
