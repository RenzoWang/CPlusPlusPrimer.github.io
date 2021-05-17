#ifndef CH5_ex7_05_h
#define CH5_ex7_05_h

#include<string>

class Person{

private:
    std::string name;
    std::string address;

public:
    std::string const& get_name() const{ return name; }
    std::string const& get_addr() const {return address; }


};

#endif