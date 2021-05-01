#include <iostream>
#include <string>
using std::cout; using std::cin; using std::endl; using std::string;

int main()
{
    string str, temp;
    while(cin >> str)
        if(isupper(str[0]) && str == temp) break; 
        else temp = str;
    
    if (cin.eof())
        cout << "no word repeated." <<endl;
    else
        
        cout<< str << " occurs twice in succession." <<endl;
    
    return 0;
}