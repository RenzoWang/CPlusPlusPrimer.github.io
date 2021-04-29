#include <iostream>
#include <vector>
#include <iterator>

using std::begin; using std::end; using std::cout; using std::endl; using std::vector;

bool compare(int* const bg1, int * const ed1, int *const bg2, int *const ed2)
{
    if((ed1 -bg1) != (ed2 - bg2))
        return false;
    else
    {
        for(int* i = bg1, *j = bg2; (i != ed1)&&(j != ed2); ++i,++j)
            if(*i != *j) return false;
    }
    return true;
}

int main()
{
    int arr1[3] = {0,1,2};
    int arr2[3] = {0,1,3};
    if(compare(begin(arr1),end(arr1),begin(arr2),end(arr2)))
        cout << "The two arrays are equal" <<endl;
    else
        cout<< "The two arrays are not equal" <<endl;

    cout << "=======================" <<endl;

    vector<int> vec1 = {0,1,2};
    vector<int> vec2 = {0,1,2};

    if(vec1 == vec2)
        cout << "The two vectors are equal" <<endl;
    else
        cout << "The two vectors are not equal" <<endl;
    
    return 0;
}