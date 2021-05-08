#include <iostream>
#include <string>
#include <stdexcept>

void swap(int* lhs, int* rhs)
{
    int temp;
    temp = * lhs;
    * lhs = * rhs;
    *rhs = temp;
}

int main()
{
    for (int lft, rht; std::cout << "Please Enter:\n", std::cin >> lft >> rht; )
    {
        swap(&lft, &rht);
        std::cout << lft << " " << rht << std::endl;
    }

    return 0;
}