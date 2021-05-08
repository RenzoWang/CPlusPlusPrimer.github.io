#include<iostream>
#include<vector>

using std::cout; using std::endl; using std::vector; using Iter = vector<int>::const_iterator;

void print(Iter beg, Iter end)
{
    if(beg != end)
    {
        cout << *beg <<" ";
        print(++beg, end);
    }
}

int main()
{
    vector<int> vec{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    print(vec.cbegin(), vec.cend());

    return 0;
}