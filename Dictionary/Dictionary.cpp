

#include "stdafx.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <cstdlib>
#include "Student.h"
#include "Dictionary.h"


using namespace std;

void presente(string id, List<Student>& l1, List<Student>& l2)
{
	Dictionary<string, Student> d1(3);
	Dictionary<string, Student> d2(3);
	List<Student>::position element_index = l1.begin();
	while (!l1.end(element_index))
	{
		d1.insert(l1.read(element_index).getid(), l1.read(element_index));
		element_index = l1.next(element_index);
	}
	if (d1.contains(id))
	{
		cout << "Student " << id << " present\n";
		d1.retrieve(id).print();
	}
	else
	{
		element_index = l2.begin();
		while (!l2.end(element_index))
		{
			d2.insert(l2.read(element_index).getid(), l2.read(element_index));
			element_index = l2.next(element_index);
		}
		if (d2.contains(id))
		{
			cout << "Student " << id << " presente\n";
			d2.retrieve(id).print();
		}
		else
			cout << "Student " << id << " assente\n";
	}
}

int conta_1_no_2(List<Student>& l1, List<Student>& l2)
{
	Dictionary<string, Student> d(3);
	List<Student>::position element_index = l2.begin();
	while (!l2.end(element_index))
	{
		d.insert(l2.read(element_index).getid(), l2.read(element_index));
		element_index = l2.next(element_index);
	}
	// ho riempito il Dictionary
	int counter = 0;
	element_index = l1.begin();
	while (!l1.end(element_index))
	{
		if (!d.contains(l1.read(element_index).getid()))
			counter++;
		element_index = l1.next(element_index);
	}
	return counter;
}


int main(int argc, char *argv[])
{
	List<Student> lezione1;
	List<Student> lezione2;
	// studenti

	Student s1("paolo", "rossi", "12354"); // lez1
	Student s2("mario", "bianchi", "12366"); // lez1
	Student s3("antonio", "verdi", "12386"); // lez1 + lez2
	Student s4("pinco", "pallino", "12554"); // lez2
	Student s5("rosa", "berardi", "14386"); // lez1
	Student s6("arianna", "longo", "12777"); // lez 2
	Student s7("anna", "marchesi", "13732"); // lez 2
	Student s8("giulio", "bernardi", "15690"); // lez1 + lez 2

												// riempiamo la prima lista
	List<Student>::position element_index = lezione1.begin();
	lezione1.insert(s1, element_index = lezione1.next(element_index));
	lezione1.insert(s2, element_index = lezione1.next(element_index));
	lezione1.insert(s3, element_index = lezione1.next(element_index));
	lezione1.insert(s5, element_index = lezione1.next(element_index));
	lezione1.insert(s8, element_index = lezione1.next(element_index));
	// riempiamo la seconda lista
	element_index = lezione2.begin();
	lezione2.insert(s3, element_index = lezione2.next(element_index));
	lezione2.insert(s4, element_index = lezione2.next(element_index));
	lezione2.insert(s6, element_index = lezione2.next(element_index));
	lezione2.insert(s7, element_index = lezione2.next(element_index));
	lezione2.insert(s8, element_index = lezione2.next(element_index));

	// stampo i dati acquisiti
	cout << lezione1 <<endl<< lezione2;
	cout << endl;
	presente("13732", lezione1, lezione2);
	cout << endl;
	presente("13731", lezione1, lezione2);
	cout << endl;
	presente("12386", lezione1, lezione2);
	cout << endl;
	cout << "Dopo la prima lezione : " << conta_1_no_2(lezione1, lezione2) << endl;


	system("PAUSE");
	return EXIT_SUCCESS;
}
