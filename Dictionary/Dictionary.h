#pragma once
#include"CircularCircularList.h"
#include"Hash.h"
#include"Entry.h"
template<typename K, typename E>
class Dictionary
{
public:
	typedef Entry<K, E> entry;
	Dictionary(size_t n):length(n),num_elements(0),table(new CircularList<entry>[length]){}
	~Dictionary() { delete[] table; }

	bool empty()const { return num_elements == 0; }
	bool contains(const K&);
	E retrieve(const K& key);
	void insert(const K& , const E& );
	void erase(const K& );
	size_t size()const { return num_elements; }
	void print()const;
private:
	//calcola the hash value of the object
	size_t H(const K& key) { return _hash(key) % length; }
	size_t length;//Dictionary max length 
	size_t num_elements;//number of elements into Dictionary
	CircularList<entry> * table; //overflow lists for entries
};

template<typename K, typename E>
bool Dictionary<K, E>::contains(const K& key)
{
	Nodo<entry> * iter;
	bool found = false;
	size_t pos = H(key);
	iter = table[pos].begin();
	while (!table[pos].end(iter) && !found) {
		if (key == table[pos].read(iter)._getKey())
			found = true;
		iter = table[pos].next(iter);
	}
	return found;
}

template<typename K, typename E>
E Dictionary<K, E>::retrieve(const K& key)
{
	Nodo<entry> * iter;
	bool found = false;
	E elem;
	size_t pos = H(key);
	iter = table[pos].begin();

	while(!table[pos].end(iter) && !found) {
		if (key == table[pos].read(iter)._getKey()) {

			found = true;
			elem = table[pos].read(iter)._getValue();
		}
		
		iter = table[pos].next(iter);
	}
	return elem;
}

template<typename K, typename E> 
void Dictionary<K, E>::insert(const K& key, const E& element)
{
	entry e(key, element);
	Nodo<entry>* position = table[H(key)].begin();
	table[H(key)].insert(e, position);
	num_elements++;
};


template<typename K, typename E>
void Dictionary<K, E>::erase(const K& key)
{
	Nodo<entry>* iter;
	bool found = false;
	size_t pos = H(key);

	iter = table[pos].begin();

	while (!table[pos].end(iter) && !found) {
		if (key == table[pos].red(iter)._getKey())
			found = true;
		else
			iter = table[pos].next(iter);
	}

	if (found)
	{
		table[pos].erase(iter);
		num_elements--;
	}
}

template<typename K, typename E>
void Dictionary<K, E>::print() const
{
	for (size_t i = 0; i < length; i++)
	{
		cout << table[i] << endl;
	}
}