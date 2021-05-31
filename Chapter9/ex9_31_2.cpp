/*
 * File: ex9_31_2.cpp
 * Project: Chapter9
 * Author: Renzo WANG (you@you.you)
 * -----
 * Modified By: Renzo WANG (you@you.you>)
 * -----
 * Brief: The program on page 354 to remove even-valued elements and 
          duplicate odd ones will not work on a list or forward_list. Why? 
          Revise the program so that it works on these types as well. 
 * -----
 */

#include <iostream>
#include <forward_list>

using std::forward_list;
using std::cout;
using std::advance;

auto remove_evens_and_double_odds(forward_list<int>& data)
{
    for(auto cur = data.begin(), prev = data.before_begin(); cur != data.end();)
        if (*cur & 0x1)
            cur = data.insert_after(prev, *cur), advance(cur, 2), advance(prev,2);
        else
            cur = data.erase_after(prev);
}

int main()
{
    forward_list<int> data { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    remove_evens_and_double_odds(data);
    for (auto i : data) cout << i << " ";

    return 0;
}