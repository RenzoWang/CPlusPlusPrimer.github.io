/*
 * File: ex9_28.cpp
 * Project: Chapter9
 * Author: Renzo WANG (you@you.you)
 * -----
 * Modified By: Renzo WANG (you@you.you>)
 * -----
 * Brief: Write a function that takes a forward_list and two additional string arguments. 
 *          The function should find the first string and insert the second immediately following the first. 
 *          If the first string is not found, then insert the second string at the end of the list.
 * -----
 */
#include<iostream>
#include<forward_list>
#include<string>

using std::string; using std::forward_list; using std::string;

void find_and_insert(forward_list<string> &lst, string const& to_find, string const& to_add)
{
    auto prev = lst.cbefore_begin();
    for(auto curr = lst.cbegin(); curr != lst.cend(); ++curr)
    {
        if(*curr == to_find)
        {
            lst.insert_after(curr, to_add);
            return;
        }
        prev = curr;
    }
    
    lst.insert_after(prev, to_add);
}

int main()
{
    forward_list<string> PSG_LGD{"Ame", "Maybe", "Chalice", "Fy", "xNova"};
    string str1 = "Nothingtosay";
    string str2 = "Faith_bian";
    string str3 = "Ame";
    find_and_insert(PSG_LGD, str2, str1);

    for(auto i : PSG_LGD)
        std::cout << i <<" ";

    std::cout <<std::endl;
    return 0;
}