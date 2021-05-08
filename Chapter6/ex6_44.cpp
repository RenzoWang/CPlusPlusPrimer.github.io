#include <iostream>
#include <string>
using std::string; using std::cout; using std::endl;

inline bool is_shorter(const string &lft, const string &rht) // defining in the header is better.
{
    return lft.size() < rht.size();
}

int main()
{
    cout << is_shorter("pezy", "mooophy") << endl;
    return 0;
}