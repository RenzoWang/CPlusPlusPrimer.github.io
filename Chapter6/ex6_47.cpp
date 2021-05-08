#include <iostream>
#include <vector>
using std::vector; using std::cout; using std::endl;

void print(vector<int>& vec )
{
#ifndef NDEBUG
    cout << "vector size:" << vec.size() << endl;
#endif
    if(!vec.empty())
    {
        auto tmp = vec.back();
        vec.pop_back();
        print(vec);
        cout << tmp << " " ;
    }

}

int main()
{
    vector<int> vec;
    int tmp;
    for(;std::cin >> tmp;)
        vec.push_back(tmp);

    print(vec);
    cout <<endl;

    return 0;

}