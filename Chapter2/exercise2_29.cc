#include<iostream>

int main()
{
    int _temp = 1;
    int i, *const cp = &_temp;
    int *p1, *const p2 = &_temp;
    const int ic = 2, &r = ic;
    const int *const p3 = &_temp;

    i = ic;
    std::cout<< "i = "<<i << " ic = "<<ic<<std::endl;

    ic =*p3;
    return 0;
}