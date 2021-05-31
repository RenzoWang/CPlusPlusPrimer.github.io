/*
 * File: ex9_47_2.cpp
 * Project: Chapter9
 * Author: Renzo WANG (you@you.you)
 * -----
 * Modified By: Renzo WANG (you@you.you>)
 * -----
 * Brief: Write a program that finds each numeric character
          and then each alphabetic character in the string "ab2c3d7R4E6".
          Write two versions of the program. The first should use find_first_of,
          and the second find_first_not_of.
 * -----
    Version find_first_not_of
 */
#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

int main()
{
    string numbers{"1234567890"};
    string alphabet {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};

    string str {"ab2c3d7R4E6"};

    cout << "numeric characters: ";
    for(size_t pos = 0; (pos = str.find_first_not_of(alphabet, pos)) != str.npos; ++pos )
        cout << str[pos] <<" ";

    cout << "\n alphabetic characters: ";
    for(size_t pos = 0;(pos = str.find_first_not_of(numbers, pos)) != str.npos; ++pos)
        cout << str[pos] <<" ";

    cout << endl;

    return 0;
}