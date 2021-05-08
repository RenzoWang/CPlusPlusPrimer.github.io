#include<iostream>
using std::cout;
using std::cin;

int compare(const int i, const int *const p)
{
    return (i > *p) ? i : *p;
}

int main()
{
    int i = 0,temp;
    int *p = &temp; // 
    cin >> i;
    cout << "please input another num: ";
    cin >> temp;
    *p = temp;
    cout << compare(i,p) <<std::endl;
    cout << "```````````````";
    return 0;
}