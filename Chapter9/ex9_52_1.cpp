/*
 * File: ex9_52.cpp
 * Project: Chapter9
 * Author: Renzo WANG (you@you.you)
 * -----
 * Modified By: Renzo WANG (you@you.you>)
 * -----
 * Brief: Use a stack to process parenthesized expressions. 
          When you see an open parenthesis, note that it was seen. 
          When you see a close parenthesis after an open parenthesis, 
          pop elements down to and including the open parenthesis off the stack. 
          push a value onto the stack to indicate that a parenthesized expression was replaced. 
 * -----
 */
#include <stack>
#include <string>
#include <iostream>

using std::string; using std::cout; using std::endl; using std::stack;

int main()
{
    string str{"Blue is the (color)."};
    bool match_parenthesis = false;
    stack<char> stk;
    for(const auto &s : str)
    {
        if(s == '(' ) {match_parenthesis = true; continue;}
        else if (s == ')' ) match_parenthesis = false;

        if (match_parenthesis) stk.push(s);
    }
    
    string repstr;
    while(!stk.empty())
    {
        repstr += stk.top();
        stk.pop();
    }

    str.replace(str.find("(") + 1, repstr.size(), repstr);

    cout << str <<endl;


    return 0;
}