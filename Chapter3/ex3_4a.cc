#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;


int main()
{
    string str1, str2;
    while(cin >> str1 >> str2){
        if (str1 == str2)
            cout << "The 2 strings are equal!" <<std::endl;
        else
            cout << "The larger one is: " << ((str1 > str2) ? str1:str2);
    }
    return 0;
}