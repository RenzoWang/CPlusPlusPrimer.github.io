/*
 * File: ex9_15.cpp
 * Project: Chapter9
 * Author: Renzo WANG (you@you.you)
 * -----
 * Modified By: Renzo WANG (you@you.you>)
 * -----
 * Brief: Write a program to determine whether two vector<int>s are equal.
 * -----
 */

#include <iostream>
#include <vector>

int main()
{
    std::vector<int> vec1{1,2,3,4,5};
    std::vector<int> vec2{1,2,3,4,5};
    std::vector<int> vec3{1,2,3,4};

    std::cout <<((vec1 == vec2) ? "true" : "false") << std::endl;
    std::cout <<((vec1 == vec3) ? "true" : "false" )<< std::endl;
    
    return 0;
}