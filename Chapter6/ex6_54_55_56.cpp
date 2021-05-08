#include <iostream>
#include <string>
#include <vector>
using std::vector; using std::cout;


//
// @brief Exercise 6.54
// @note  define the function type fp
//
inline int f(const int, const int);
typedef decltype(f) fp;//fp is just a function type not a function pointer

inline int add(const int a, const int b) { return a + b; }
inline int subtract(const int a, const int b) { return a - b; }
inline int multiply(const int a, const int b) { return a * b; }
inline int divide(const int a, const int b) { return b != 0 ? a / b : 0; }

vector<fp*> v{add,subtract,multiply,divide};

int main()
{
    // @brief Exercise 6.56
    // @note  Call each element in the vector and print their result.
    //
    for (auto it = v.cbegin(); it != v.cend(); ++it)
        cout << (*it)(2,2) << std::endl;

        return 0;
}