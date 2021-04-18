#Exercise
## Exercise 2.1
> What are the differences between int, long, long long, and short? Between an unsigned and a signed type? Between a float and a double?

C++ guarantees `short` and `int` is **at least** 16 bits, `long` **at least** 32 bits, `long long` **at least** 64 bits.

The `signed` can represent positive numbers, negative numbers and zero, while `unsigned` can only represent numbers no less than zero.

The C and C++ standards do not specify the representation of float, double and long double.

## Exercise 2.2
> To calculate a mortgage payment, what types would you use for the rate, principal, and payment? Explain why you selected each type.

use `double`, or also `float`.

## Exercise 2.3
> What output will the following code produce?
```cpp
unsigned u = 10, u2 = 42;
std::cout << u2 - u << std::endl;
std::cout << u - u2 << std::endl;
int i = 10, i2 = 42;
std::cout << i2 - i << std::endl;
std::cout << i - i2 << std::endl;
std::cout << i - u << std::endl;
std::cout << u - i << std::endl;
```
Output:
```
32
4294967264 // = (-32 + 4294967295) mod 4294967295
32
-32
0
0
```
## Exercise 2.4
> Write a program to check whether your predictions were correct. If not, study this section until you understand what the problem is.

[code](exercise2_4.cpp)

## Exercise 2.5
> Determine the type of each of the following literals. Explain
the differences among the literals in each of the four examples:
- (a) 'a', L'a', "a", L"a"
- (b) 10, 10u, 10L, 10uL, 012, 0xC
- (c) 3.14, 3.14f, 3.14L
- (d) 10, 10u, 10., 10e-2

(a): character literal, wide character literal, string literal, string wide character literal.

(b): decimal, unsigned decimal, long decimal, unsigned long decimal, octal, hexadecimal.

(c): double, float, long double.

(d): decimal, unsigned decimal, double, double.

## Exercise 2.6
> What, if any, are the differences between the following
definitions:
```cpp
int month = 9, day = 7;
int month = 09, day = 07;
```
The first line's integer is decimal.

The second line:

1. `int month = 09` is invalid, cause octal don't have digit `9`.
2. `day` is octal.

## Exercise 2.7
> What values do these literals represent? What type does each
have?
- (a) "Who goes with F\145rgus?\012"
- (b) 3.14e1L
- (c) 1024f
- (d) 3.14L

(a): Who goes with Fergus?(new line) "string"

(b): 31.4 "long double"

(c): ERROR: The suffix f is valid only with floating point literals, but 1024 is integer

(d): 3.14 "long double"

## Exercise 2.8
> Using escape sequences, write a program to print 2M followed by a newline. Modify the program to print 2, then a tab, then an M, followed by a newline.

```cpp
#include <iostream>

int main()
{
    std::cout << 2 << "\115\012";
    std::cout << 2 << "\t\115\012";
    return 0;
}
```
## Exercise 2.9
>Explain the following definitions. For those that are illegal, explain what’s wrong and how to correct it.
- (a) std::cin >> int input_value;
- (b) int i = { 3.14 };
- (c) double salary = wage = 9999.99;
- (d) int i = 3.14;

Solution:
(a): error: expected '(' for function-style cast or type construction.
```cpp
int input_value = 0;
std::cin >> input_value;
```
(b):---when you compile the code without the argument "-std=c++11", you will get the warning below:
    warning: implicit conversion from 'double' to 'int' changes value from 3.14 to 3.
---when you compile the code using "-std=c+11", you will get a error below:
    error: type 'double' cannot be narrowed to 'int' in initializer list
---conclusion: Obviously, list initialization becomes strict in c++11.
```cpp
double i = { 3.14 };
```

(c): --if you declared 'wage' before, it's right. Otherwise, you'll get a error:
    error: use of undeclared identifier 'wage'
```cpp
double wage;
double salary = wage = 9999.99;
```

(d): ok: but value will be truncated.
```cpp
double i = 3.14;
```

## Exercise 2.10
>What are the initial values, if any, of each of the following variables?
```cpp
std::string global_str;
int global_int;
int main()
{
    int local_int;
    std::string local_str;
}
```
`global_str` is global variable, so the value is empty string.
`global_int` is global variable, so the value is zero.
`local_int` is a local variable which is uninitialized, so it has a undefined value.
`local_str` is also a local variable which is uninitialized, but it has a value that is defined by the class. So it is empty string.
PS: please read P44 in the English version, P40 in Chinese version to get more.
The note: Uninitialized objects of built-in type defined inside a function body have a undefined value. Objects of class type that we do not explicitly inititalize have a value that is defined by class.

## Exercise 2.11
> Explain whether each of the following is a declaration or a
definition:
- (a) extern int ix = 1024;
- (b) int iy;
- (c) extern int iz;

    (a): definition.
    (b): definition.
    (c): declaration.

## Exercise 2.12
>Which, if any, of the following names are invalid?
- (a) int double = 3.14;
- (b) int _;
- (c) int catch-22;
- (d) int 1_or_2 = 1;
- (e) double Double = 3.14;

`a`, `c`, `d` are invalid.

## Exercise 2.13
>What is the value of j in the following program?
```cpp
int i = 42;
int main()
{
    int i = 100;
    int j = i;
}
```

`100`, since the global `i` was hidden by the local `i`.

## Exercise 2.14
>Is the following program legal? If so, what values are printed?
```cpp
    int i = 100, sum = 0;
    for (int i = 0; i != 10; ++i)
        sum += i;
    std::cout << i << " " << sum << std::endl;
```

Legal. Output:

```100 45```

Note: in for scope, i = 0, break when i = 10;