#ifndef CH5_ex7_50_h
#define CH5_ex7_50_h

#include<string>
#include<iostream>

class Person{

    friend std::istream &read(std::istream &is, Person &person);
    friend std::ostream &print(std::ostream &os, const Person &person);

public:
    // new constructor
    Person() = default;
    Person(const std::string sname, const std::string saddr): name(sname), address(saddr){ }
    explicit Person(std::istream &is) { read(is,*this); } // only for the constructor with one-argument
    
    
    std::string const& get_name() const{ return name; }
    std::string const& get_addr() const {return address; }

private:

    std::string name;
    std::string address;


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