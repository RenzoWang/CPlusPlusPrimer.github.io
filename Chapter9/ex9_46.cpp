/*
 * File: ex9_46.cpp
 * Project: Chapter9
 * Author: Renzo WANG (you@you.you)
 * -----
 * Modified By: Renzo WANG (you@you.you>)
 * -----
 * Brief: Rewrite the previous exercise using a position and length to manage the strings.
          This time use only the insert function.
 * -----
 */


#include <iostream>
#include <string>

auto add_pre_and_suffix(std::string name, std::string const& pre, std::string const& su)
{
    name.insert(0, pre);
    name.insert(name.size(), su);
    return name;
}

int main()
{
    std::string name("alan");
    std::cout << add_pre_and_suffix(name, "Mr.", ",Jr.");
    return 0;
}