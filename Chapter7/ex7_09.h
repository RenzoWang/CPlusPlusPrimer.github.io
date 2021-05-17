
#ifndef CH5_ex7_09_h
#define CH5_ex7_09_h

#include<string>
#include<iostream>

class Person{

public:
    std::string name;
    std::string address;

public:
    std::string const& get_name() const{ return name; }
    std::string const& get_addr() const {return address; }


};

std::istream &read(std::istream &is, Person &person)
{
    return is >> person.name >> person.address;
}

std::ostream &print(std::ostream &os, const Person &person)
{
    return os << person.name << " " << person.address;
}

#endif
