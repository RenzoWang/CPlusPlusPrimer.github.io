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

    for(int i = 0; i <ivec.size()-1; ++i)
    {
        cout << "The sum of "<<ivec[i] <<" to " <<ivec[i+1]<<" is "<<ivec[i] + ivec[i+1] << " "<<endl;

    }
    cout <<endl;
    return 0;
}