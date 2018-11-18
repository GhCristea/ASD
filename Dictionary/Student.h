#pragma once

#include <string>
#include <iostream>

using namespace std;

class Student {
	friend ostream &operator<<(ostream&, const Student &);
public:
	Student(string, string, string);
	Student();
	~Student(){}
	string getName() const{ return name; }
	void setname(string n){ name = n; }
	string getSurname() const{ return surname; }
	string getID() const{ return id; }
	void print() const;
private:
	string name;
	string surname;
	string id;
};



Student::Student(string n, string c, string m)
{
	name = n;
	surname = c;
	id = m;
}

Student::Student()
{
	name = "";
	surname = "";
	id = "";
}


void Student::print() const
{
	cout << "name: " << name << "\n";
	cout << "surname: " << surname << "\n";
	cout << "id: " << id << "\n";
}

ostream &operator<<(ostream &os, const Student &s)
{
	return (os << s.getID() << " - " << s.getSurname() << " " << s.getName());
}
