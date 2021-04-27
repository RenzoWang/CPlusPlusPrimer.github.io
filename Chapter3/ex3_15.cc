#include<iostream>
#include<vector>
#include<string>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

int main()
{
    string word;
    int cnt = 0;
    vector<string> str;

    while(cin >> word){
         str.push_back(word); cout << str[cnt] <<endl;
         ++cnt;
    }  



    return 0;
}