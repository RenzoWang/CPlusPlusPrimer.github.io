#include <iostream>
#include <string>

using std::cout; using std::cin; using std::endl; using std::string; using std::pair;

int main()
{
    int count = 0, maxCnt = 0;
    string str, prestr, dup_Str;
    while (cin >> str)
    {
        
        if(str == prestr) ++count;
        else count = 0;

        if (count > maxCnt) 
        {
            maxCnt = count; 
            if(dup_Str != str ) dup_Str = str;
            else ;
        }
        prestr = str;
    }
    if (maxCnt == 0) cout << "There is no duplicated string." <<endl;
    else cout << "the word " << dup_Str << " occurred " <<  maxCnt+1 << " time(s)"<<endl;

    return 0;
}