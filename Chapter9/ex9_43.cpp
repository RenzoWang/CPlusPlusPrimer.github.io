/*
 * File: ex9_43.cpp
 * Project: Chapter9
 * Author: Renzo WANG (you@you.you)
 * -----
 * Modified By: Renzo WANG (you@you.you>)
 * -----
 * Brief: Write a function that takes three strings, s, oldVal, and newVal.
          Using iterators, and the insert and erase functions replace
          all instances of oldVal that appear in s by newVal.
	        Test your function by using it to replace common abbreviations,
          such as “tho” by “though” and “thru” by “through”.
 * -----
    This code doesn't compile on GCC. Please use Visual Studio 2015+ or Clang 3.6+ 
 */
#include <iterator>
#include <iostream>
#include <string>
#include <cstddef>

using std::cout; 
using std::endl; 
using std::string;

auto replace_with(string &s, string const& oldVal, string const& newVal)
{
    string str;
    for(auto curr = s.begin(); curr <= s.end() - oldVal.size();)
        if(oldVal == string{ curr, curr + oldVal.size()} )
            curr = s.erase(curr, curr + oldVal.size()),
            curr = s.insert(curr, newVal.begin(), newVal.end()),
            curr += newVal.size();
        else
            ++curr;
}

int main()
{
    string s{ "To drive straight thru is a foolish, tho courageous act." };
    replace_with(s, "tho", "though");
    replace_with(s, "thru", "through");
    cout << s << endl;

    return 0;
}