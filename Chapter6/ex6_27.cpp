#include <iostream>
#include <initializer_list>

using std::cout; using std::initializer_list;

int sum(initializer_list<int> const& il)
{
    int sum = 0;
    for(auto i:il) sum += i;
    return sum;
}

int main()
{
    auto il = {1,2,3,4,5,6,7,8,9,10};
    cout << sum(il) <<std::endl;
    return 0;
}