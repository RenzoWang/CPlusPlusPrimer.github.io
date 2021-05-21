#include<iostream>

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

    read(std::cin);
    return 0;
}