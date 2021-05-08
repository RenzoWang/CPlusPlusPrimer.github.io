#include <iostream>
#include <string>
using std::cout; using std::endl; using std::string;

bool is_capital(string const& str)
{
    for(auto c : str)
        if (isupper(c)) return true;
    return false;
}

void to_lowercase(string & str)
{
    for(auto &c : str) c = tolower(c);
}

int main()
{
    string hello("Hello World!");
    cout << is_capital(hello) << endl;

    to_lowercase(hello);
    cout << hello << endl;

    return 0;
}