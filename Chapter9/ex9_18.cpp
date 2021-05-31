/*
 * File: ex9_18.cpp
 * Project: Chapter9
 * Author: Renzo WANG (you@you.you)
 * -----
 * Modified By: Renzo WANG (you@you.you>)
 * -----
 * Brief: Write a program to read a sequence of strings from the standard input into a deque. Use iterators 
 *        to write a loop to print the elements in the deque.
 * -----
 */

#include <iostream>
#include <string>
#include <deque>

using std::string; using std::deque; using std::cout; using std::cin; using std::endl;

int main()
{
    deque<string> save;
    for(string str; cin >> str; save.push_back(str));
    for(auto it = save.cbegin(); it != save.cend(); ++it)
        cout << *it <<endl;
    return 0;
}