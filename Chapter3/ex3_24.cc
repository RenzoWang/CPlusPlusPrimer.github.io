#include <iostream>
#include <vector>

using std::vector; using std::cout; using std::endl; using std::cin;

int main()
{
    vector<int> ivec;
    for(int i; cin >>i; ivec.push_back(i));

    if(ivec.empty())
    {
        cout << "input at least one int." <<endl;
        return -1;
    }

    if(ivec.size() == 1)
    {
        cout << "Only one integer " << ivec[0]<<endl;
        return -1;
    }

    for(auto it = ivec.begin(); it+1 !=ivec.end(); ++it)
        cout << *it + *(it+1) << " ";
    cout <<endl;

    for(auto beg = ivec.begin(), end = ivec.end() -1; beg <= end; ++beg, --end)
        cout<< *beg + *end << " ";
    cout <<endl;
    return 0;

}