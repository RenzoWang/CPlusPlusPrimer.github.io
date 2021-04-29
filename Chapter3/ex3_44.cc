#include <iostream>
using std::cout; using std::endl;


int main()
{   
    int arr[3][4] = 
    { 
        { 0, 1, 2, 3 },
        { 4, 5, 6, 7 },
        { 8, 9, 10, 11 }
    };

    // use type alias
    using int_array = int[4];
    //typedef int int_array[4];     //等价的typedef声明
    //range for block
    for(const int_array (&row) : arr)
        for(int col : row) cout << col <<" ";
    cout<<endl;

    // for loop
    for(size_t i = 0; i != 3; ++i){
        for(size_t j = 0; j != 4; ++j){
            cout<< arr[i][j] << " ";
        }
    }
    cout <<endl;

    // pointer
    //use type alias
    for(int_array (*row) = arr; row != arr+3; ++row)
        for(int *col = * row; col != *row + 4; ++col) 
            cout<< *col <<" ";
    cout <<endl;
    return 0;
}