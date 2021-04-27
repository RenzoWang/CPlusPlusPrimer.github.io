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
    vector<string> str;
    for(string word; cin >> word; str.push_back(word));
    for( auto &str1 : str) for (auto &c : str1) c = toupper(c);

    for(string::size_type i = 0; i != str.size(); ++i)
    {
       cout << str[i] << " "<<endl;
    }
    cout <<endl;
    return 0;
}