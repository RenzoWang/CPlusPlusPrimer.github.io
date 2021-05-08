## Exercise 6.1
>实参(Arguments)和形参(Parameters)的区别的什么？
**Parameters**: Local variable declared inside the function parameter list.
they are initialized by the **arguments** provided in the each function call.

**Arguments**: Values supplied in a function call that are used to initialize the function's **parameters**.

## Exercise 6.2
>请指出下列函数哪个有错误，为什么？应该如何修改这些错误呢？
```cpp
(a) int f() {
          string s;
          // ...
          return s;
    }
(b) f2(int i) { /* ... */ }
(c) int calc(int v1, int v1) { /* ... */ }
(d) double square (double x)  return x * x; 
```
Solution:

```cpp
(a) string f() {  // return should be string, not int
          string s;
          // ...
          return s;
    }
(b) void f2(int i) { /* ... */ }  // function needs return type
(c) int calc(int v1, int v2) { /* ... */ }  // parameter list cannot use same name twice
(d) double square (double x) { return x * x; }  // function body needs braces
```
## Exercise 6.3
>编写你自己的fact函数，上机检查是否正确。
```cpp
#include <iostream>

int fact(int i)
{
    if(i<0)
    {
        runtime_error err("Input cannot be a negative number");
        cout << err.what() << endl;
    }
    return i > 1 ? i * fact( i - 1 ) : 1;
}

int main()
{
    std::cout << std::boolalpha << (120 == fact(5)) << std::endl;
    return 0;
}
```
## [Exercise 6.4](ex6_4.cpp)
>编写一个与用户交互的函数，要求用户输入一个数字，计算生成该数字的阶乘。在main函数中调用该函数。
## Exercise 6.5
>编写一个函数输出其实参的绝对值
```cpp
#include <iostream>

int abs(int i)
{
    return i > 0 ? i : -i;
}

int main()
{
    std::cout << abs(-5) << std::endl;
    return 0;
}
```

## Exercise 6.6
>说明形参、局部变量以及局部静态变量的区别。编写一个函数，同时达到这三种形式。
形参定义在函数形参列表里面；局部变量定义在代码块里面；局部静态变量在程序的执行路径第一次经过对象定义语句时初始化，并且直到程序终止时才被销毁。
**local variable**: Variables defined inside a **block**;

**parameter**: **Local variables** declared inside the **function parameter list**

**local static variable**: **local static variable（object）** is initialized before the first time execution passes through the object’s definition.**Local statics** are not destroyed when a function ends; they are **destroyed when the program terminates.**
```cpp
// example
size_t count_add(int n)       // n is a parameter.
{
    static size_t ctr = 0;    // ctr is a static variable.
    ctr += n;
    return ctr;
}

int main()
{
    for (size_t i = 0; i != 10; ++i)  // i is a local variable.
      cout << count_add(i) << endl;

    return 0;
}
```
## Exercise 6.7
>编写一个函数，当它第一次被调用时返回0，以后每次被调用返回值加1。
```cpp
int callCnt()
{
    static int cnt = 0;
    return cnt++;
}
```
## [Exercise 6.8](Chapter6.h)
>编写一个名为Chapter6.h 的头文件，令其包含6.1节练习中的函数声明。

## Exercise 6.9 [fact.cc](fact.cc) | [factMain.cc](factMain.cc)

>编写你自己的fact.cc 和factMain.cc ，这两个文件都应该包含上一小节的练习中编写的 Chapter6.h 头文件。通过这些文件，理解你的编译器是如何支持分离式编译的。
 ```shell
 g++ -std=c++11 factMain.cc fact.cc -o factMain
 ```
## [Exercise 6.10](ex6_10.cpp)
## [Exercise 6.11](ex6_11.cpp)
## [Exercise 6.12](ex6_12.cpp)
>Rewrite the program from exercise 6.10 in § 6.2.1 (p. 210) to use references instead of pointers to swap the value of two ints. Which version do you think would be easier to use and why?

The version using reference is easier.

## Exercise 6.13
>假设 T 是某种类型的名字，说明以下两个函数声明的区别：一个是void f(T), 另一个是 void f(&T)。

`void f(T)` pass the argument by value.**nothing the function does to the parameter can affect the argument**.

`void f(T&)` pass a reference, will be **bound to** whatever T object we pass.
## Exercise 6.14
>举一个形参应该是引用类型的例子，再举一个形参不能是引用类型的例子。

a parameter should be a reference type(change the values):
```cpp
void reset(int &i)
{
        i = 0;
}
```

a parameter should not be a reference:
```cpp
void print(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
        for (std::vector<int>::iterator iter = begin; iter != end; ++iter)
                std::cout << *iter << std::endl;
}
```
## Exercise 6.15
>why is `s` a reference to const but `occurs` is a plain reference?

Because `s` shoule not be changed by this function, but `occurs` result must be calculated by the functions.

>Why are these parameters references, but the char parameter `c` is not?

Because `c` may be a temp varable, such as `find_char(s, 'a', occurs)`

>What would happen if we made `s` a plain reference? What if we made `occurs` a reference to const?

`s` could be changed in the function, and `occurs` would not be changed. so `occurs = 0;` is an error.

## Exercise 6.16
>下面的这个函数虽然合法，但是不算特别有用。指出它的局限性并设法改善。
```cpp
bool is_empty(string& s) { return s.empty(); }

```

Since the function doesn't change the argument, `const` should be added when the value no need to change, otherwise this function is misleading and can't be used with const string or in a const function. 
>尽量使用常引用

```cpp
bool is_empty(const string& s) { return s.empty(); }
```
## [Exercise 6.17](ex6_17.cpp)
>编写一个函数，判断string对象中是否含有大写字母。编写另一个函数，把string对象全部改写成小写形式。在这两个函数中你使用的形参类型相同吗？为什么？

Not the same. For the first one "const" was used, since no change need to do for the argument. For the second function, "const" can't be used, because the content of the agument should be changed.
## Exercise 6.18
```cpp
//(a)
bool compare(matrix &m1, matrix &m2);

//(b)
vector<int> change_val(int, vector<int>::iterator)
```

## Exercise 6.19
>假定有如下声明，判断哪个调用合法、哪个调用不合法。对于不合法的函数调用，说明原因。
```cpp
double calc(double);
int count(const string &, char);
int sum(vector<int>::iterator, vector<int>::iterator, int);
vector<int> vec(10);
(a) calc(23.4, 55.1);
(b) count("abcda",'a');
(c) calc(66);
(d) sum(vec.begin(), vec.end(), 3.8);
```
(a) illegal, only one parameter.
(b) legal.
(c) legal.
(d) legal.

## Exercise 6.20

If we can use `const`, just use it. 

If we make a parameter a plain reference when it could be a reference to `const`,the reference value maybe changed.
## [Exercise 6.21](ex6_21.cpp)
>Write a function that takes an int and a pointer to an int and returns the larger of the int value or the value to which the pointer points. What type should you use for the pointer?

如果没有对指针进行初始化，即将其（赋值）指向一个特定的内存单元，无法利用其进行操作。
## [Exercise 6.22](ex6_22.cpp)
>Write a function to swap two int pointers.
## [Exercise 6.23](ex6_23.cpp)
## Exercise 6.24
当数组作为实参的时候，会被自动转换为指向首元素的指针。因此函数形参接受的是一个指针。如果要让这个代码成功运行，可以将实参改为数组的引用。
>Arrays have two special properties that affect how we define and use functions that operate on arrays: We cannot copy an array, and when we use an array it is (usually) **converted to a pointer**.

So we cannot pass an array by value, and when we pass an array to a function, we are actually passing a pointer
to the array's first element.

In this question, `const int ia[10]` is actually same as `const int*`, and the size of the array is **irrelevant**.
we can pass `const int ia[3]` or `const int ia[255]`, there are no differences. If we want to pass an array which size is ten, we should use reference like that:
```cpp
void print10(const int (&ia)[10]) { /*...*/ }
```


see more discusses at http://stackoverflow.com/questions/26530659/confused-about-array-parameters

## [Exercise 6.25 && Exercise 6.26](ex6_25_26.cpp) 
> Exercise 6.25: Write a main function that takes two arguments. Concatenate the supplied arguments and print the resulting string.

> Exercise 6.26: Write a program that accepts the options presented in this section. Print the values of the arguments passed to main.

## [Exercise 6.27](ex6_27.cpp)
>编写一个函数，它的参数是initializer_list类型的对象，函数的功能是计算列表中所有元素的和。

## Exercise 6.28
>在error_msg函数的第二个版本中包含ErrCode类型的参数，其中循环内的elem是什么类型？
```cpp
for (const auto &elem : il)
```
the type of `elem` is `const string&`
## Exercise 6.29

Depends on the type of elements of `initializer_list`. When the type is [PODType](http://en.cppreference.com/w/cpp/concept/PODType)(Plain Old Data), reference is unnecessary. Because `POD` is **cheap to copy**(such as `int`). Otherwise, Using reference(`const`) is the better choice.

## [Exercise 6.30](ex6_33.cpp)
>编译第200页的str_subrange函数，看看你的编译器是如何处理函数中的错误的。
```
error: return-statement with no value, in function returning 'bool' [-fpermissive]
             return;
```
Error (Clang):
>Non-void function 'str_subrange' should return a value. // error #1

>Control may reach end of non-void function. // error #2

## Exercise 6.31
>什么情况下返回的引用无效？什么情况下返回常量的引用无效？
当返回的引用的对象是局部变量时，返回的引用无效；当我们希望返回的对象被修改时，返回常量的引用无效。
when you can find the preexisting object that the reference refered.

## Exercise 6.32
>下面的函数合法吗？如果合法，说明其功能；如果不合法，修改其中的错误并解释原因。
```cpp
int &get(int *array, int index) { return array[index]; }
int main()
{
    int ia[10];
    for (int i = 0; i != 10; ++i)
        get(ia, i) = i;
}
```
legal. it gave the values(0~9) to array `ia`

## [Exercise 6.33](ex6_33.cpp)
>编写一个递归函数，输出vector对象的内容。

## Exercise 6.34
>如果factorial 函数的停止条件如下所示，将发生什么？
```cpp
if (val != 0)
```
When the recursion termination condition becomes `var != 0`,

* **case 1**: If the argument is positive,recursion stops at 0.(Note : There is one extra multiplication step though as the combined expression for factorial(5) reads 5 * 4 * 3 * 2 * 1 * 1. In terms of programming languages learning, such subtle difference probably looks quite trivial. In algorithms analysis and proof, however, this extra step may be super important.)
* **case 2** : if the argument is negative, recursion would never stop. As a result, a stack overflow would occur.
## Exercise 6.35
>在调用factorial 函数时，为什么我们传入的值是 val-1 而非 val--？
If the value passed in is `val--`, then the same value will always be passed in to call the function, and the recursion will never end.
## Exercise 6.36
>编写一个函数声明，使其返回数组的引用并且该数组包含10个string对象。不用使用尾置返回类型、decltype或者类型别名
```cpp
string (&func( string (&arrStr)[10] ))[10]
```

## Exercise 6.37
>为上一题的函数再写三个声明，一个使用类型别名，另一个使用尾置返回类型，最后一个使用decltype关键字。你觉得哪种形式最好？为什么？
```cpp
using arrT = string [10];
arrT& func1(arrT& arr);
```

```cpp
auto func2(arrt& arr) -> string(&)[10];
```
```cpp
string arrs[10];
decltype(arrs)& func3(arrT& arr);
```
I pefer the first one. because it is simpler to me.

## Exercise 6.38
>修改arrPtr函数，使其返回数组的引用。
```cpp
decltype(arrStr)& arrPtr(int i)
{
          return (i % 2) ? odd : even;
}
```

## Exercise 6.39
>说明在下面的每组声明中第二条语句是何含义。如果有非法的声明，请指出来。
```cpp
(a) int calc(int, int);
	int calc(const int, const int);
(b) int get();
	double get();
(c) int *reset(int *);
	double *reset(double *);s
```

* (a) legal. repeated declarations(without definition) are legal in C++
~~but if the function called , maybe it's illega. Because the top-level const does not affect the object passed into the function, the second declaration cannot be distinguished from the first declaration.~~

* (b) illegal. only the return type is different

* (c) legal. the parameter type is different and return type is changed

## Exercise 6.40
>下面的哪个声明是错误的？为什么？
```cpp
(a) int ff(int a, int b = 0, int c = 0);
(b) char *init(int ht = 24, int wd, char bckgrnd);	
```
(a) no error

(b) Missing default argument on parameter 'wd', 'bckgrnd'.

## Exercise 6.41
>下面的哪个调用是非法的？为什么？哪个调用虽然合法但显然与程序员的初衷不符？为什么？
```cpp
char *init(int ht, int wd = 80, char bckgrnd = ' ');
(a) init();
(b) init(24,10);
(c) init(14,'*');
```
(a) illegal. No matching function for call to 'init'
(b) legal. match
(c) legal, but not match. 'wd' would be setting to '*'.

## [Exercise 6.42](ex6_42.cpp)
>给make_plural函数的第二个形参赋予默认实参's', 利用新版本的函数输出单词success和failure的单数和复数形式。
>Give the second parameter of make_plural (§ 6.3.2, p. 224) a default argument of 's'. Test your program by printing singular and plural versions of the words success and failure.

## Exercise 6.43
>你会把下面的哪个声明和定义放在头文件中？哪个放在源文件中？为什么？
```cpp
(a) inline bool eq(const BigInt&, const BigInt&) {...}
(b) void putValues(int *arr, int size);
```

Both two should put in a header. (a) is an inline function. (b) is the declaration of useful function. we always put them in the header.
## [Exercise 6.44](ex6_44.cpp)
>将6.2.2节的isShorter函数改写成内联函数。Rewrite the isShorter function from § 6.2.2 (p. 211) to be inline.
```cpp
inline bool is_shorter(const string &lft, const string &rht) 
{
    return lft.size() < rht.size();
}
```
## Exercise 6.45
>回顾在前面的练习中你编写的那些函数，它们应该是内联函数吗？如果是，将它们改写成内联函数；如果不是，说明原因。
* Normally, the inline function shoule be small and called frequently.


For example, the function `arrPtr` in [Exercise 6.38](# Exercise-638) and `make_plural` in [Exercise 6.42](# Exercise-642) should be defined as `inline`. But the function `func` in [Exercise 6.4](# Exercise-64) shouldn't. It is not that small and it's only being called once. Hence, it will probably not expand as inline.

## Exercise 6.46
> Would it be possible to define `isShorter` as a `constexpr`? If so, do so. If not, explain why not.

No

Because `std::string::size()` is not a `constexpr` function and `s1.size() == s2.size()` is not a constant expression.  A `constexpr` function 's parameter shoule be `literal type`

> **For a** non-template, non-defaulted **constexpr function** or a non-template, non-defaulted, non-inheriting
constexpr constructor, **if no argument values exist such that an invocation of the function or constructor
could be an evaluated subexpression of a core constant expression (5.19), the program is ill-formed;** no
diagnostic required. (N3690 §7.1.5 [dcl.constexpr]/5)

## [Exercise 6.47](ex6_47.cpp)
>To turn off debugging, uncomment the following line, or compile the program with '-D NDEBUG' switch

## Exercise 6.48

This loop let user input a word all the way until the word is sought.

It isn't a good use of assert. because if user begin to input a word, the `cin` would be always have content. so the `assert` would be always `true`. It is meaningless. using `assert(s == sought)` is better.
## Exercise 6.49

* candidate function:
> Set of functions that are considered when resolving a function call. (all the functions with the name used in the call for which a declaration is in scope at the time of the call.)

* viable function:
>Subset of the candidate functions that could match a given call.
>It have the same number of parameters as arguments to the call, and each argument type can be converted to the corresponding parameter type.

## Exercise 6.50
(a) illegal. 2.56 match the `double`,  42 match teh `int`;

(b) match `void f(int)`

(c) match `void f(int, int)`

(d) match `void f(double, double = 3.14)`

## [Exercise 6.51](ex6_51.cpp)
## Exercise 6.52
(a) Match through a promotion

(b) Arithmetic type conversion
## Exercise 6.53

(a)
```cpp
int calc(int&, int&); // calls lookup(int&)
int calc(const int&, const int&); // calls lookup(const int&)
```
(b)
```cpp
int calc(char*, char*); // calls lookup(char*)
int calc(const char*, const char*); // calls lookup(const char *)
```
(c)

illegal. both calls lookup(char*), 顶层const不影响传入函数的对象

## Exercise 6.54
>Write a declaration for a function that takes two int parameters and returns an int, and declare a vector whose elements have this function pointer type
```cpp
int func(int a, int b);
std::vector<fecltype(func)*> vec;
```
or

```cpp
int func(int a, int b);
using pFunc1 = decltype(func)*;

typedef decltype(func) *pFunc2;

using pFunc3 = int(*)(int a, int b);

using pFunc4 = int(int a, int b);

typedef int(*pFunc5)(int a, int b);

using pFunc6 = decltype(func);

std::vector<pFunc1> vec1;
std::vector<pFunc2> vec2;
std::vector<pFunc3> vec3;
std::vector<pFunc4*> vec4;
std::vector<pFunc5> vec5;
std::vector<pFunc6*> vec6;
```

## Exercise 6.55
>编写4个函数，分别对两个int值执行加、减、乘、除运算；在上一题创建的vector对象中保存指向这些函数的指针。Write four functions that add, subtract, multiply, and divide two int values. Store pointers to these functions in your vector from the previous exercise.

```cpp
int add(int a, int b)
{
    return a+b;
}

int subtract(int a, int b)
{
    return a-b;
}

int multiply(int a, int b)
{
    return a*b;
}

int divide(int a, int b)
{
    return b != 0 ? a/b : 0;
}

vec.push_back(add);
vec.push_back(subtract);
vec.push_back(multiply);
vec.push_back(divide);
```
## Exercise 6.56
>Call each element in the vector and print their result.
```cpp
std::vector<decltype(func) *> vec{ add, subtract, multiply, divide };
for (auto f : vec)
          std::cout << f(2, 2) << std::endl;
```

* The last 3 exercises' [complete codes](ex6_54_55_56.cpp)