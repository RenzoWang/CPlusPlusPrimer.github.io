#include<iostream>

void reset(int &i)
{
    i = 0;
}

int val_set(int &i)
{
    int j = i;
    j = 0;
    return i+1;
}

int main()
{
    int i = 42;
    int val = val_set(i);
    reset(i);
    
    std::cout << i  << std::endl;
    std::cout << val  << std::endl;
    return 0;
}