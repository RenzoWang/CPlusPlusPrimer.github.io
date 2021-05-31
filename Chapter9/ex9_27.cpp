/*
 * File: ex9_27.cpp
 * Project: Chapter9
 * Author: Renzo WANG (you@you.you)
 * -----
 * Modified By: Renzo WANG (you@you.you>)
 * -----
 * Brief: Write a program to find and remove the odd-valued elements in a forward_list<int>.
 * -----command: g++ -std=c++1y ex9_27.cpp -o ex9_27
 */
#include<iostream>
#include<forward_list>

using std::cout; using std::cin; using std::forward_list;

auto remove_odd(forward_list<int> & flist)
{
    auto is_odd = [](int i) {return (i & 0x1);};
    flist.remove_if(is_odd);
}
int main()
{
    forward_list<int> data;
    auto it = data.cbefore_begin();
    for(int i; cin >> i; ++it )
        data.insert_after(it, i);

    remove_odd(data);

    for(auto i:data)
        cout << i << " ";

    return 0;
}

