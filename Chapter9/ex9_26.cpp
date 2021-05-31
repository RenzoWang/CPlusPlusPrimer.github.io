/*
 * File: ex9_26.cpp
 * Project: Chapter9
 * Author: Renzo WANG (you@you.you)
 * -----
 * Modified By: Renzo WANG (you@you.you>)
 * -----
 * Brief: // Using the following definition of ia, copy ia into a vector and into a list.
 *  Use the single-iterator form of erase to remove the elements with odd values from your list and the even values from your vector.
 * -----
 */

#include <iostream>
#include <vector>
#include <list>

using std::vector; using std::list; using std::cout; using std::endl; using std::end;

int main()
{
    int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };

    vector<int> vec(ia,end(ia));
    list<int> lst (vec.begin(),vec.end());

    for(auto it = lst.cbegin(); it != lst.cend(); )
        if(*it & 0x1) it = lst.erase(it);
        else ++it;

    for(auto it = vec.cbegin(); it != vec.cend();)
        if(!(*it & 0x1)) it = vec.erase(it);
        else ++it; 

        // print
    cout << "list : ";
    for(auto i : lst)   cout << i << " ";
    cout << "\nvector : ";
    for(auto i : vec)   cout << i << " ";
    cout << std::endl;
    
    return 0;
}