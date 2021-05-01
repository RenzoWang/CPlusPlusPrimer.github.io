#include <iostream>
#include <vector>

using std::cout; using std::vector;

bool isPrefix(vector<int> const& lhs, vector<int> const& rhs)
{
    if(lhs.size() > rhs.size())
        return isPrefix(rhs,lhs);
    for(auto lit = lhs.begin(), rit = rhs.begin(); lit != lhs.end(); ++lit,++ rit)
        if(*lit != *rit ) return false;
    return true;

}

int main()
{
    vector<int> l{ 0, 1, 1, 2 ,5};
    vector<int> r{ 0, 1, 1, 2, 3, 5, 8 };
    cout << (isPrefix(r, l) ? "yes\n" : "no\n");
}