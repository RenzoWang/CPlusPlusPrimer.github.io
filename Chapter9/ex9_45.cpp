/*
 * File: ex9_45.cpp
 * Project: Chapter9
 * Author: Renzo WANG (you@you.you)
 * -----
 * Modified By: Renzo WANG (you@you.you>)
 * -----
 * Brief:   Write a funtion that takes a string representing a name and two other
            strings representing a prefix, such as “Mr.” or “Ms.” and a suffix,
            such as “Jr.” or “III”. Using iterators and the insert and append functions,
            generate and return a new string with the suffix and prefix added to the
            given name.
 * -----
 */
#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

auto add_pre_and_suffix(string name, string const& pre, string const& su)
{
    name.insert(name.begin(), pre.cbegin(), pre.cend());
    return name.append(su);
}

int main()
{
    string name("Wang");
    cout << add_pre_and_suffix(name, "Mr.", ", Jr.") << endl;
    return 0;
}