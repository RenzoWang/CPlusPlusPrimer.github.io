#include <vector>
#include <iostream>
#include <iterator>
using std::vector; using std::iterator; using std::cout;

int main()
{   
    vector<int> vec{0,1,2,3,4,5,6,7,8,9};
    for(auto it = vec.begin(); it != vec.end(); ++it ) *it *=2;
    for (auto i : vec) cout <<i<<" " <<std::endl;
    return 0;
}