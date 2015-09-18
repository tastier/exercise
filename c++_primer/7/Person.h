#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

class Person{
friend std::istream& operator>>(std::istream&, Person&);
friend std::ostream& operator<<(std::ostream&, const Person&);

private:
	std::string s_name;
	std::string s_address;
public:
	std::string get_name() const {return s_name;}
	std::string get_address() const { return s_address;}

public:
	Person() = default;
	Person(const std::string &name, const std::string &address) :
		s_name(name), s_address(address) { }
	Person(std::istream &is) { is >> *this; }
};

std::istream&
operator>>(std::istream &in, Person &p)
{
	in >> p.s_name >> p.s_address;
	return in;
}

std::ostream&
operator<<(std::ostream &os, const Person &p)
{
	os << p.s_name << p.s_address;
	return os;
}



#endif
