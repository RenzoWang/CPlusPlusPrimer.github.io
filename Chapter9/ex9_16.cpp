/*
 * File: ex9_16.cpp
 * Project: Chapter9
 * Author: Renzo WANG (you@you.you)
 * -----
 * Modified By: Renzo WANG (you@you.you>)
 * -----
 * Brief: Repeat the previous program, but compare elements in a list<int> to a vector<int>.
 * -----
 */

#include <iostream>
#include <vector>
#include <list>

int main()
{
    std::list<int> l {1,2,3,4,5};
    std::vector<int> v1 {1,2,3,4,5};
    std::vector<int> v2 {1,2,3,4};

    std::cout << (std::vector<int>(l.cbegin(),l.cend()) == v1 ? "true" : "false") << std::endl;
    std::cout << (std::vector<int>(l.cbegin(),l.cend()) == v2 ? "true" : "false") << std::endl;
    return 0;
}