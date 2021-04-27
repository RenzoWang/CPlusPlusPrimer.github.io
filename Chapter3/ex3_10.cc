/**
 * @file ex3_10.cc
 * @author Renzo
 * @brief reads a string of characters including punctuation and writes what 
 *        was read but with the punctuation removed.
 * @version 0.1
 * @date 2021-04-27
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;
int main()
{
    cout << "Enter a string of characters including punctuation." << endl;
    for (string s; getline(cin, s); cout << endl)
        for (auto i : s) 
            if (!ispunct(i)) cout << i; 

    return 0;
}