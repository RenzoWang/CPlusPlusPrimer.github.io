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
std::cout << u2 - u << std::endl;   // 42-10 = 32
std::cout << u - u2 << std::endl;   // 10 - 42 = -32 mod 
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
> Explain whether each of the following is a declaration or a definition:
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

## Exercise 2.15
>Which of the following definitions, if any, are invalid? Why?
- (a) int ival = 1.01;
- (b) int &rval1 = 1.01;
- (c) int &rval2 = ival;
- (d) int &rval3;

```
(a) valid
(b) invalid, intializaer must be an object.
(c) valid
(d) invalid. a reference must be intialized.
```

## Exercise 2.16
>Which, if any, of the following assignments are invalid? If they are valid, explain what they do.

    int i = 0, &r1 = i; double d = 0, &r2 = d;
- (a) r2 = 3.14159;
- (b) r2 = r1;
- (c) i = r2;
- (d) r1 = d;

```
(a): valid, let d = 3.14159
(b): valid, automatic convert will happen.
(c): valid, but value will be truncated.
(d): valid, but value will be truncated.
```
## Exercise 2.17
>What does the following code print?
```cpp
int i, &ri = i;
i = 5; ri = 10;
std::cout << i << " " << ri << std::endl;
```

```
10 10
```

## Exercise 2.18
>Write code to change the va lue of a pointer. Write code to change the value to which the pointer points.

```cpp
int a = 0, b = 1;
int *p1 = &a, *p2 = p1;

// change the value of a pointer.
p1 = &b;
// change the value to which the pointer points
*p2 = b;

```

## Exercise 2.19
>Explain the key differences between pointers and references.

#### definition:

the pointer is "points to" any other type.

the reference is "another name" of an **object**.

#### key difference:

1. a reference is another name of an **already existing** object.
a pointer is an object in its **own right**.
2. Once initialized, a reference remains **bound to** its initial object.
There is **no way** to rebind a reference to refer to a different object.
a pointer can be **assigned** and **copied**.
3. a reference always get the object to which the reference was initially bound.
a single pointer can point to **several different objects** over its lifetime.
4. a reference must be initialized.
a pointer need **not be** initialized at the time it is defined.


## Exercise 2.20
>What does the following program do?
```cpp
int i = 42;
int *p1 = &i; *p1 = *p1 * *p1;
```

`p1` pointer to `i`, `i`'s value changed to 1764(42*42)

## Exercise 2.21
>Explain each of the following definitions. Indicate whether any are illegal and, if so, why.

    int i = 0;

- (a) double* dp = &i;
- (b) int *ip = i;
- (c) int *p = &i;

```
(a): illegal, cannot initialize a variable of type `double *` with an rvalue of type `int *` 
(b): illegal, cannot initialize a variable of type `int *` with an lvalue of type `int`
(c): legal
```

## Exercise 2.22
Assuming p is a pointer to int, explain the following code:
```cpp
if (p) // ...
if (*p) // ...
```
if (p) // whether p is nullptr
if(*p) // whether the value pointed by p is zero

## Exercise 2.23
>Given a pointer p, can you determine whether p points to a valid object? If so, how? If not, why not?

NO, more information needed. type/intialization/...


## Exercise 2.24
>Why is the initialization of p legal but that of lp illegal?

```cpp
int i = 42;
void *p = &i;
long *lp = &i;
```
In a word, the types of pointer are different.

Inherited from C, `void*` is a special pointer that may point to any type, hence the second line is legal.

For type safety, C++ forbids implicit conversions like `long *lp = &i;`, thus such code is illegal.

## Exercise 2.25
>Determine the types and values of each of the following
variables.
- (a) int* ip, i, &r = i;
- (b) int i, *ip = 0;
- (c) int* ip, ip2;

(a) ip is a pointer to int, i is an int, r is a reference to int i
(b) i is an int, ip is a valid, null pointer
(c) ip is a pointer to int, ip2 is an int.

## Exercise 2.26
>Which of the following are legal? For those that are illegal,
explain why.

```cpp
const int buf;      // illegal, buf is uninitialized const.
int cnt = 0;        // legal.
const int sz = cnt; // legal.
++cnt;              // legal.
++sz;               // illegal, attempt to write to const object(sz).
```

## Note:
 若在多个文件之间共享const object, 必须在变量的定义之前添加external 关键字

//file_1.cc
extern const int bufSize = fcn();

//file_1.h
extern const bufSize;

## Exercise 2.27
> Which of the following initializations are legal? Explain why.

```cpp
int i = -1, &r = 0;         // illegal, r must refer to an object.
int *const p2 = &i2;        // legal.
const int i = -1, &r = 0;   // legal. there is a hide line `const int __temp = 0; const int &r = __temp;`
const int *const p3 = &i2;  // legal.
const int *p1 = &i2;        // legal
const int &const r2;        // illegal, r2 is a reference that cannot be const.
const int i2 = i, &r = i;   // legal.
```
>Note: As for why `const int i = -1, &r = 0; ` is `legal` and  `int i = -1, &r = 0;   ` is 'illegal' [Answer](https://stackoverflow.com/questions/34525109/why-int-r-0-is-illegal-while-const-int-r-0-is-legal)

A non-const lvalue reference must bind directly to an lvalue. `0` is not an lvalue, so `int &r = 0;` fails.

A const lvalue reference may be bound to an rvalue. When this happens, it is not bound directly. Instead, a temporary (of type `const int` here) is created and copy-initialized from the rvalue. The temporary has its lifetime extended by virtue of this binding.

So `const int &r = 0;` is legal and has a similar effect to `const int __temp = 0; const int &r = __temp;`

 > About lvalue & rvalue etc. [Here](https://zhuanlan.zhihu.com/p/138210501). And the difference about const reference and reference [Here](https://blog.csdn.net/sinat_38104725/article/details/100057974)
 
## Exercise 2.28

>Explain the following definitions. Identify any that are illegal.

```cpp
int i, *const cp;       // illegal. const pointer cp must be initialized
int *p1, *const p2;     // illegal. const pointer p2 must be initialized
const int ic, &r = ic;  // illegal. const int ic must be initialized
const int *const p3;    // illegal. const pointer p3 must be initialized
const int *p;           // legale. a pointer to const int
```

## Exercise 2.29
>Uing the variables in the previous exercise, which of the following assignments are legal? Explain why.
```cpp
i = ic;     // legal. 
p1 = p3;    // illegal. const pinter p3 to const int. int pointer cannot point to const value. 
/* 
error: invalid conversion from 'const int*' to 'int*' [-fpermissive]
     p1 = p3;
        ^
*/
p1 = &ic;   // illegal. ic is a const int, normal pointer cannot point to const int.
/*
error: invalid conversion from 'const int*' to 'int*' [-fpermissive]
     p1 = &ic;
        ^
*/
p3 = &ic;   // illegal. p3 is a const pointer. cannot  change value 
/*
error: assignment of read-only variable 'p3'
     p3 = &ic;
        ^
*/
p2 = p1;    // illegal. p2 is a const pointer. cannot change value.
/*
error: assignment of read-only variable 'p2'
     p2 = p1;
        ^
*/
ic = *p3;   // illegal. ic is const int. cannot change value.
/*
assignment of read-only variable 'ic'
     ic =*p3;
        ^
*/
```
Test code is [here](/Chapter2/exercise2_29.cc)

>普通指针不能指向 const 变量。
```cpp
int a = 10;
const int *p = &a;

int *r = p;
std::cout << *r << std::endl;
```
Error:
```cpp
error: cannot initialize a variable of type 'int *' with an lvalue of type 'const int *'
    int *r = p;
         ^   ~
1 error generated.
```

### Note
底层const（low-level const）表示其指向（所引用）的对象是const的。 
顶层const（top-level const）表示本身是const的，不可变
`*const`代表的是顶层const，指针存的地址不能改变。
`const int`代表的是底层const，指针指向一个常量，常量自然不能改变。
## Exercise 2.30
>For each of the following declarations indicate whether the object being declared has top-level or low-level const.
```cpp
const int v2 = 0; int v1 = v2;
int *p1 = &v1, &r1 = v1;
const int *p2 = &v2, *const p3 = &i, &r2 = v2;
```

```cpp
v2 is top-level const;

p2 is low-level;

p3 is top-level(cannot change) & low-level(the object pointed to cannot change) 

r2 is low-level;
```

## Exercise 2.31
>Given the declarations in the previous exercise determine whether the following assignments are legal. Explain how the top-level or low-level const applies in each case.

```cpp
r1 = v2;    // legal. top-level const in v2 is ignored
p1 = p2;    // illegal. p2 has a low-level conten but p1 not
p2 = p1;    // legal.  int * can be converted to const int *
p1 = p3;    // illegal. don not have the same level const
p2 =p3;     // legal. p2 has the same level const qualification as p3 
```

## Exercise 2.32
>Is the following code legal or not? If not, how might you make it legal?

    int null = 0, *p = null;

illegal. 
```cpp
int null = 0, *p = &null;
//or
int null = 0, *p = nullptr;
```

## Exercise 2.33
>Using the variable definitions from this section, determine what happens in each of these assignment
```cpp
a=42;   // set 42 to int a
b=42;   // set 42 to int b
c=42;   // set 42 to int c
d=42;   // illegal. d is a int pointer. *d = 42 is correct
e=42;   // illegal. e is a const int*. e = &c is correct.
g=42;   // illegal. g is reference bound to const int ci.
```
## Exercise 2.34
>Write a program containing the variables and assignments from the
previous exercise.
Print the variables before and after the assignments to check
whether your predictions in the previous exercise were correct.
If not, study the examples until you can convince yourself you know
￼￼what led you to the wrong conclusion.

[Here](/Chapter2/exercise2_34.cc) is the code.

## Exercise 2.35
>Determine the types deduced in each of the following definitions. Once you’ve figured out the types, write a program to see whether you were correct.

```cpp
const int i = 42;   // i is a const int
auto j = i;         // j is an int
const auto &k = i;  // k is a const int *
auto *p = &i;       // p is a const int pointer
const auto j2 = i, &k2 = i; //j2 is a const int, k2 is a const int reference.
```
[Code](/Chapter2/exercise2_35.cc) example
```
// print i means int, and PKi means pointer to const int.
j is i
k is i
p is PKi
j2 is i
k2 is i
```
## Exercise 2.36
>In the following code, determine the type of each variable and the value each variable has when the code finishes:
```cpp
int a = 3, b = 4;
decltype(a) c = a;
decltype((b)) d = a;
++c;
++d;
```

`c` is an int.
`b` is a reference of `a`.
all their value is `4`

## Exercise 2.37
>Assignment is an example of an expression that yields a reference type. The type is a reference to the type of the left-hand operand. That is, if i is an int, then the type of the expression i = x is int&. Using that knowledge, determine the type and value of each variable in this code:
```cpp
int a = 3, b = 4;
decltype(a) c = a;
decltype(a = b) d = a;
```
`c` is an int.

`d` is a reference of int.

value a =3; b = 4, c = 3, d = 3.
## Exercise 2.38
>Describe the differences in type deduction between decltype and auto. Give an example of an expression where auto and decltype will deduce the same type and an example where they will deduce differing types.

The way `decltype` handles top-level const and references differs **subtly** from the way `auto` does.
Another important difference between `decltype` and `auto` is that the deduction done by decltype depends on the **form** of its given expression.

so the key of difference is **subtly** and **form**.

```cpp
int i = 0, &r = i;
//相同
auto a = i;
decltype(i) b = i;

//不同 d 是一个 int&
auto c = r;
decltype(r) d = r;
```
More? Look at [here](http://stackoverflow.com/questions/21369113/what-is-the-difference-between-auto-and-decltypeauto-when-returning-from-a-fun) and [here](http://stackoverflow.com/questions/12084040/decltype-vs-auto)

## Exercise 2.39
>Compile the following program to see what happens when
you forget the semicolon after a class definition. Remember the message for
future reference.
```cpp
struct Foo { /* empty  */ } // Note: no semicolon
int main()
{
    return 0;
}
```
> Error message: [Error] expected ';' after struct definition

## Exercise 2.40
>Write your own version of the Sales_data class.
```cpp
struct Sale_data
{
    std::string bookNo;
    std::string bookName;
    unsigned unuts_sold = 0;
    double revenue = 0.0;
    double price = 0.0;
    //...

};
```
## Exercise 2.41
>Use your Sales_data class to rewrite the exercises in § 1.5.1(p. 22), § 1.5.2(p. 24), and § 1.6(p. 25). For now, you should define your Sales_data class in the same file as your main function.
####1.5.1
```cpp
#include <iostream>
#include <string>

struct Sale_data
{
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

int main()
{
    Sale_data book;
    double price;
    std::cin >> book.bookNo >> book.units_sold >> price;
    book.revenue = book.units_sold * price;
    std::cout << book.bookNo << " " << book.units_sold << " " << book.revenue << " " << price;

    return 0;
}
```
####1.5.2

```cpp
#include <iostream>
#include <string>

struct Sale_data
{
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

int main()
{
    Sale_data book1, book2;
    double price1, price2;
    std::cin >> book1.bookNo >> book1.units_sold >> price1;
    std::cin >> book2.bookNo >> book2.units_sold >> price2;
    book1.revenue = book1.units_sold * price1;
    book2.revenue = book2.units_sold * price2;

    if (book1.bookNo == book2.bookNo)
    {
        unsigned totalCnt = book1.units_sold + book2.units_sold;
        double totalRevenue = book1.revenue + book2.revenue;
        std::cout << book1.bookNo << " " << totalCnt << " " << totalRevenue << " ";
        if (totalCnt != 0)
            std::cout << totalRevenue / totalCnt << std::endl;
        else
            std::cout << "(no sales)" << std::endl;
        return 0;
    }
    else
    {
        std::cerr << "Data must refer to same ISBN" << std::endl;
        return -1;  // indicate failure
    }
}
```
####1.6

```cpp
#include <iostream>
#include <string>

struct Sale_data
{
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

int main()
{
    Sale_data total;
    double totalPrice;
    if (std::cin >> total.bookNo >> total.units_sold >> totalPrice)
    {
        total.revenue = total.units_sold * totalPrice;

        Sale_data trans;
        double transPrice;
        while (std::cin >> trans.bookNo >> trans.units_sold >> transPrice)
        {
            trans.revenue = trans.units_sold * transPrice;

            if (total.bookNo == trans.bookNo)
            {
                total.units_sold += trans.units_sold;
                total.revenue += trans.revenue;
            }
            else
            {
                std::cout << total.bookNo << " " << total.units_sold << " " << total.revenue << " ";
                if (total.units_sold != 0)
                    std::cout << total.revenue / total.units_sold << std::endl;
                else
                    std::cout << "(no sales)" << std::endl;

                total.bookNo = trans.bookNo;
                total.units_sold = trans.units_sold;
                total.revenue = trans.revenue;
            }
        }

        std::cout << total.bookNo << " " << total.units_sold << " " << total.revenue << " ";
        if (total.units_sold != 0)
            std::cout << total.revenue / total.units_sold << std::endl;
        else
            std::cout << "(no sales)" << std::endl;

        return 0;
    }
    else
    {
        std::cerr << "No data?!" << std::endl;
        return -1;  // indicate failure
    }
}
```
## Exercise 2.42
>Write your own version of the Sales_data.h header and use it to rewrite the exercise from § 2.6.2(p. 76)
####1.5.1
```cpp
#include <iostream>
#include "ex2_42.h"

int main()
{
    Sales_data book;
    double price;
    std::cin >> book.bookNo >> book.units_sold >> price;
    book.CalcRevenue(price);
    book.Print();

    return 0;
}
```
####1.5.2
```cpp
#include <iostream>
#include "ex2_42.h"

int main()
{
    Sales_data book1, book2;
    double price1, price2;
    std::cin >> book1.bookNo >> book1.units_sold >> price1;
    std::cin >> book2.bookNo >> book2.units_sold >> price2;
    book1.CalcRevenue(price1);
    book2.CalcRevenue(price2);

    if (book1.bookNo == book2.bookNo)
    {
        book1.AddData(book2);
        book1.Print();
        return 0;
    }
    else
    {
        std::cerr << "Data must refer to same ISBN" << std::endl;
        return -1;  // indicate failure
    }
}

```

####1.6
```cpp
#include <iostream>
#include "ex2_42.h"

int main()
{
    Sales_data total;
    double totalPrice;
    if (std::cin >> total.bookNo >> total.units_sold >> totalPrice)
    {
        total.CalcRevenue(totalPrice);
        Sales_data trans;
        double transPrice;
        while (std::cin >> trans.bookNo >> trans.units_sold >> transPrice)
        {
            trans.CalcRevenue(transPrice);
            if (total.bookNo == trans.bookNo)
            {
                total.AddData(trans);
            }
            else
            {
                total.Print();
                total.SetData(trans);
            }
        }
        total.Print();
        return 0;
    }
    else
    {
        std::cerr << "No data?!" << std::endl;
        return -1;  // indicate failure
    }
}
```