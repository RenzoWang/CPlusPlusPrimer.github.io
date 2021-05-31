/*
 * File: e9_49.cpp
 * Project: Chapter9
 * Author: Renzo WANG (you@you.you)
 * -----
 * Modified By: Renzo WANG (you@you.you>)
 * -----
 * Brief: A letter has an ascender if, as with d or f, part of the letter extends
          above the middle of the line.
          A letter has a descender if, as with p or g, part of the letter extends below the line.
          Write a program that reads a file containing words and reports the longest word
          that contains neither ascenders nor descenders.
 * -----
 */

#include <string>
#include <fstream>
#include <iostream>

using std::string; using std::cout; using std::endl; using std::ifstream;

string find_longest(const string& s, string& result)
{
    string not_in("aceimnorsuvwxz");
    size_t size;
    if(s.find_first_not_of(not_in) == string::npos)
        result = result.size() < s.size() ? s : result;
    return result;
}

int main()
{
    ifstream ifs("letter.txt");
    if(!ifs)
    {cout << "File open error"; return -1;}

    string longest;

    for(string curr; ifs >> curr;find_longest(curr, longest));
        

    cout << "The longest: " << longest;

    return 0;
}

/*int main()
{
    ifstream ifs("letter.txt");
    if (!ifs) return -1;

    string longest;
    auto update_with = [&longest](string const& curr)
    {
        if (string::npos == curr.find_first_not_of("aceimnorsuvwxz"))
            longest = longest.size() < curr.size() ? curr : longest;
    };
    for (string curr; ifs >> curr; update_with(curr));
    cout << longest << endl;

    return 0;
}*/