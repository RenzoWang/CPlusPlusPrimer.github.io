/*
 * File: ex9_20.cpp
 * Project: Chapter9
 * Author: Renzo WANG (you@you.you)
 * -----
 * Modified By: Renzo WANG (you@you.you>)
 * -----
 * Brief: Write a program to copy elements from a list<int> into two deques. 
 *        The even-valued elements should go into one deque and the odd ones into the other.
 * -----
 */

#include <iostream>
#include <deque>
#include <list>
using std::deque; using std::list; using std::cout; using std::cin; using std::endl;

int main()
{
    list<int> num;
    deque<int> odd, even;
    for(int i; cin >> i; num.push_back(i));

    for(auto i : num)
        ((i % 2) ? odd : even).push_back(i);

    for(auto i : odd) cout << i << " ";
    cout <<endl;
    cout<< "=================="<<endl;
    for(auto i : even) cout << i << " ";
    cout <<endl;
    return 0;
}
