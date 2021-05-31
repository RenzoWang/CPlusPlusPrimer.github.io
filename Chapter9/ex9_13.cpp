/*
 * File: ex9_13.cpp
 * Project: Chapter9
 * Author: Renzo WANG (you@you.you)
 * -----
 * Modified By: Renzo WANG (you@you.you>)
 * -----
 * Brief: // How would you initialize a vector<double> from a list<int>?
// From a vector<int>?
// Write code to check your answers.
 * -----
 */
#include <iostream>
#include <string>
#include <vector>
#include <list>
using std::list; using std::vector; using std::cout; using std::endl;

int main()
{
    list<int> lst(3,4);
    vector<int> vec(3,5);

    //from list<int> to vector<double>
    vector<double> dvec(lst.begin(),lst.end());
    cout << "===================" << endl;
    for(auto dv : dvec) cout << dv << " ";
    cout << endl;

    cout << "===================" << endl;  
    for(auto l : lst) cout << l << " ";
    cout << endl;

    //from vector<int> to vector<double>
    vector<double> dvec2(vec.begin(), vec.end());
    cout << "===================" << endl;  
    for(auto i : vec) cout << i << " ";
    cout <<endl;

    cout << "===================" << endl;  
    for(auto d:dvec2) cout << d <<" ";
    cout << endl;

    



    

    return 0;
}
