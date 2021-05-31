/*
 * File: ex9_41.cpp
 * Project: Chapter9
 * Author: Renzo WANG (you@you.you)
 * -----
 * Modified By: Renzo WANG (you@you.you>)
 * -----
 * Brief:  Write a program that initializes a string from a vector<char>.
 * -----
 */

#include <iostream>
#include <vector>
#include <string>

using std::vector; 
using std::cout; 
using std::endl; 
using std::string;

int main()
{
    vector<char> v{'t', 'e', 's', 't'};
    string str(v.cbegin(),v.cend());
    cout <<str <<endl;

    return 0;
}