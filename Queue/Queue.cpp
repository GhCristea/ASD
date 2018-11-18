
#include "stdafx.h"
#include"Queue.h"

using namespace std;

int main()
{
	Queue<int> c(5);
	int a = 0;
	int b = 1;
	int d = 2;
	c.push(a);
	c.push(b);
	c.push(d);
	/*print_tail(c);
	cout << endl;
	*/
	print_tail(c);
	cout << endl;
	c.pop();
	print_tail(c);
	//cout << endl;
	//print_tail(c);
	c.pop();
	cout << endl;
	print_tail(c);
/*	for (int i = 0; i < 13; i++)
	{
		cout << c.leggi() << " ";
		c.pop();
	}*/
	cout << endl;
	system("pause");
    return 0;
}

