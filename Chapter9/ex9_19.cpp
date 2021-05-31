/*
 * File: ex9_19.cpp
 * Project: Chapter9
 * Author: Renzo WANG (you@you.you)
 * -----
 * Modified By: Renzo WANG (you@you.you>)
 * -----
 * Brief: Rewrite the program from the previous exercise to use a list.
          List the changes you needed to make.
 * -----
 */
#include <iostream>
#include <string>
#include <list>

using std::string; using std::list; using std::cout; using std::cin; using std::endl;

int main()
{
    list<string> input;
    for(string str; cin >> str; input.push_back(str));

    for(auto it = input.cbegin(); it != input.cend(); ++it)
        cout << *it <<endl;

    return 0;
}