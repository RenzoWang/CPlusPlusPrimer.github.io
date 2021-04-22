#include<iostream>

int main()
{
    const int i = 0;
    const int j =6;
    int 
    const int * p1 = &i;
    const int *p2 = &j;
    int *const p3 = &j;
    std::cout<< i <<" "<< *p1 << std::endl;
    std::cout << &p1 << std::endl;
    i = j ;
    std::cout<< i <<" "<< *p1 << std::endl;
    std::cout << &p1 << std::endl;
    return 0;
}