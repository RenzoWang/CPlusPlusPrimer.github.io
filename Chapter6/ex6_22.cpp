#include <iostream>
#include <string>

void swap(int* (&lhi), int* (&rhi))
{
    int tmp;
    tmp = *lhi;
    *lhi = *rhi;
    *rhi = tmp;
}

int main()
{
    int i = 9,j = 8;
    int *p1 = &i, *p2 = &j;
    swap(p1, p2);
    std::cout << *p1 <<"   "<< *p2 <<std::endl; 
    return 0;
}