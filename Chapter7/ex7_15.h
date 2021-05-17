#ifndef CH5_ex7_15_h
#define CH5_ex7_15_h

#include<string>
#include<iostream>

struct Person{

    // new constructor
    Person() = default;
    Person(const std::string sname, const std::string saddr): name(sname), address(saddr){ }
    Person(std::istream &is) { read(is,*this); }
    
    // original func
    std::string name;
    std::string address;

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