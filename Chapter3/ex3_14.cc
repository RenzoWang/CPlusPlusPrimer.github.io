#include<iostream>
#include<vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{
    int i, cnt = 0;
    vector<int> vi;

    while(cin >> i){
         vi.push_back(i); cout << vi[cnt] <<endl;
         ++cnt;
    }  

    return 0;
}