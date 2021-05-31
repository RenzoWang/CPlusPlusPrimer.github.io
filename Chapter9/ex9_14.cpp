/*
 * File: ex9_14.cpp
 * Project: Chapter9
 * Author: Renzo WANG (you@you.you)
 * -----
 * Modified By: Renzo WANG (you@you.you>)
 * -----
 * Brief:  Write a program to assign the elements from a list of char* pointers
// to C-style character strings
 * -----
 */
#include <iostream>
#include <string>
#include <vector>
#include <list>

int main()
{
    std::list<const char*> l{"Alice", "Bob", "Ceb"};
    std::vector<std::string> v;

    v.assign(l.cbegin(),l.cend());
    for(auto ptr:v)
    {
         std::cout << ptr << std::endl;
    }

    return 0;
}