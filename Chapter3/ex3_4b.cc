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
        if (str1.size() == str2.size())
            cout << "The 2 strings' length are equal!" <<std::endl;
        else
            cout << "The larger one is: " << ((str1.size() > str2.size()) ? str1:str2) << endl;
    }
    return 0;
}