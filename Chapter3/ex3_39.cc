#include <iostream>
#include <string>
#include <cstring>
using std::cout; using std::endl; using std::string;

int main()
{
    string s1="Hello World"; string s2 = "Hello world";
    if(s1 == s2)
        cout << " The two strings are equal"<<endl;
    else if(s1 < s2)
        cout << s2 << " > "<< s1 << endl;
    else
        cout << s1 << " > "<< s2 << endl;
    
    cout << "=========" << endl;    

    //use c-style string
    const char *cs1 = "hello world";
    const char *cs2 = "hello World";
    auto result = strcmp(cs1,cs2);
    if(result == 0)
        cout << " The two strings are equal"<<endl;
    else if(result < 0)
        cout << cs2 << " > "<< cs1 << endl;
    else
        cout << cs1 << " > "<< cs2 << endl; 

    cout << "=========" << endl;   

    string s3="ACB"; string s4 = "ABCD";
    if(s3 == s4)
        cout << " The two strings are equal"<<endl;
    else if(s3 < s4)
        cout << s4 << " > "<< s3 << endl;
    else
        cout << s3 << " > "<< s4 << endl;
    return 0;
}