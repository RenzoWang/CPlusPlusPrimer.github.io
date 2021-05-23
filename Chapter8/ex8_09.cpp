#include<iostream>
#include <sstream>

std::istream& read(std::istream& is)
{   
    std::string str;
    for(;is >> str;)
    //while(is >> str)
        std::cout << str << std::endl;
    is.clear();
    return is;
}

int main()
{
    std::istringstream iss("hello");
    read(iss);
    return 0;
}