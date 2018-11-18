#pragma once
#include"eccezioni.h"

template<typename T>
class PriorityQueue
{
public:
	using _info_type = T;
	PriorityQueue(size_t);
	PriorityQueue() :PriorityQueue(100){}
	~PriorityQueue() { delete[] _heap; }

	void create() { _length = 0; }
	void insert(_info_type);
	
	/**
	* read the minimum element from the queue
	*/
	_info_type read() { if (_length != 0) return _heap[0]; else throw PilaVuota(); }
	
	/**
	* erase the minumum from the queue
	*/
	void erase();

private:
	size_t MAX_LEGTH;
	_info_type *_heap;
	size_t _length;

	/**
	 * to restore uphill constraints - insertion
	*/
	void fixup(); 
	/**
	* to restore downward restraints - cancellation
	*/
	void fixdown(size_t, size_t);
};


/**
 * allocate space for 100 items if a parameter is not specified
*/
template<typename T>
PriorityQueue<T>::PriorityQueue(size_t len = 100) : MAX_LEGTH(len)
{
	_heap = new _info_type[MAX_LEGTH]; 
	create();
}

template<typename T>
void PriorityQueue<T>::insert(_info_type x)
{
	if (_length < MAX_LEGTH)
	{
		_heap[++_length -1] = x;
		//_length++;

		fixup();
	}
	else throw FullQueue();
}

template<typename T>
void PriorityQueue<T>::erase()
{
	if (_length != 0)
	{
		_heap[0] = _heap[_length - 1]; //overwrite the root
		_length--;
		fixdown(1, _length);

	}
	else throw PilaVuota();
}


/**
 * to restore uphill constraints - insertion
*/
template<typename T>
void PriorityQueue<T>::fixup()
{
	size_t k = _length; //from the last leaf
	while (k > 1 && _heap[k - 1] < _heap[k / 2 - 1])
	{
		_My_swap(_heap[k - 1], _heap[k / 2 - 1]);

		k = k / 2;
	}
}

/**
* to restore downward restraints - cancellation
*/
template<typename T>
void PriorityQueue<T>::fixdown(size_t x1, size_t x2)
{
	int change = 1;

	while ((x1 <= x2 / 2) && change)  //if there is a son of x1
	{
		size_t j = 2 * x1; // j is the son of x1
		
		/*
		if the son of dx is lower then the sun of sx,
		go to the son of dx
		*/
		if (change = (j < x2) && (_heap[j - 1] < _heap[x1 - 1])) ++j;

		if (_heap[j - 1] < _heap[x1 - 1]) {
			
			_My_swap(_heap[x1 - 1], _heap[j - 1]);
			
			x1 = j;
		}

	}
}


/**
 Heap Sort
 Ordina il sottoarray A[] da A[begin] fino ad A[end]
*/
template<typename T>
void heap_sort(T A[], size_t _begin, size_t _end)
{
	if (_begin <= _end) { //se la lunghezza inserita e' valida 
		
		size_t in_lenght = _end - _begin + 1;  //stabilisco lo spazio per allocare alla coda
		
		PriorityQueue<T> cP(in_lenght);

		size_t i;
		for (i = _begin; i <= _end; i++)  //scorre il sottoarray array
			cP.insert(A[i]);  //inserisci in coda in modo ordinato
		for (i = _end; i >= _begin; i--)
		{
			A[i] = cP.read();
			cP.erase();
		}

	}
	else throw LunghezzaNegativa();
}


//
template<typename T>
void _My_swap(T _left, T _right)
{
	int temp = _left;
	_left = _right;
	_right = temp;
}