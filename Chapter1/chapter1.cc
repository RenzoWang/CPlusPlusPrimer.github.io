#include <iostream>
int main()
{
    std::cout << "enter 2 numbers:" <<std::endl;
    int v1 = 0, v2 = 0;
    std::cin >> v1 >> v2;
    std::cout << "Hello, world." <<std::endl;
    std::cout <<" the sum of " << v1 <<"and"<< v2 << " is " << v1+v2 <<std::endl;
    std::cout <<" The product of " << v1 <<" and " <<v2 <<" is " << v1*v2 <<std::endl;
    
    return 0;
}