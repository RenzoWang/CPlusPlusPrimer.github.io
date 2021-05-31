/*
 * File: ex9_52_2.cpp
 * Project: Chapter9
 * Author: Renzo WANG (you@you.you)
 * -----
 * Modified By: Renzo WANG (you@you.you>)
 * -----
 * Brief: See ex9_52_1.cpp
 * -----
 */
#include <iostream>
#include <string>
#include <stack>
#include <cctype>

using namespace std;

string calc_paren(string &l, string &r, string &op)
{
    string s;
    if (op == "-")
        s = to_string(stoi(l) - stoi(r));
    
    return s;
}
int main()
{
    string expression("1+2*(7-4)");
    stack<string> stk;
    bool beSeen = false;
    for(auto iter = expression.begin(); iter!= expression.end();)
    {
        if(*iter == '(')
        {
            beSeen = true;
            ++iter;
            stk.push(string(1,*iter));

            while(*iter != ')')
            {
                stk.push(string(1,*iter));
                ++iter;
            }

        }
        else if(*iter == ')' && beSeen)
        {
            string r = stk.top(); stk.pop();
            string op = stk.top();stk.pop();
            string l = stk.top(); stk.pop();
            stk.pop();
            stk.push(calc_paren(l,r,op));

            ++iter;
            beSeen = false;
        }
        else{++iter;}
    }
    string str;

    
    while(!stk.empty())
    {

        str+=stk.top();
        stk.pop();

        
    }
    
    expression.replace(expression.find("(")+1,3, str);
    cout << expression <<endl;
    return 0;
}