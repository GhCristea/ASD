

#include "stdafx.h"
#include<iostream>
#include"PriorityQueue.h"

using namespace std;

int main()
{
	int A[] = { 5,3,2,4,5,6,2,1,35,6 };
	for (int i = 0; i < 10; i++)
		cout << A[i] << " ";
	cout << endl;

	//heap_sort(A, 0, 10);

	PriorityQueue<int> mc;
	mc.insert(4);
	
	mc.insert(6);
	mc.insert(2);

	for (int i = 0; i < 3; i++) {
		cout << mc.read() << " ";
		mc.erase();
	}
	cout << endl;


	system("pause");
    return 0;
}

