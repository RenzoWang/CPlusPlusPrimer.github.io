#include <iostream>
#include <vector>
using std::vector; using std::cout; using std::endl; using std::begin; using std::end;

int main()
{   
    int arr[] = {0,1,2,3,4,5,6,7,8,9};
    vector<int> vi(begin(arr),end(arr));
    
    for(auto i : vi) cout<<i<<" ";

    cout<<endl;
    return 0;
}