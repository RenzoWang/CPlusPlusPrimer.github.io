## [Exercise 7.1](ex7_01.cpp)
>使用2.6.1节定义的Sales_data类为1.6节的交易处理程序编写一个新版本。
## [Exercise 7.2](ex7_02.h)
>曾在2.6.2节的练习中编写了一个Sales_data类，请向这个类添加combine函数和isbn成员。
## [Exercise 7.3](ex7_03.cpp)
>修改7.1.1节的交易处理程序，令其使用这些成员。
## [Exercise 7.4](ex7_04.h)
>编写一个名为Person的类，使其表示人员的姓名和地址。使用string对象存放这些元素，接下来的练习将不断充实这个类的其他特征。
## [Exercise 7.5](ex7_05.h)
>在你的Person类中提供一些操作使其能够返回姓名和地址。这些函数是否应该是const的呢？解释原因。

`const`. There will be a const object `Person` 
## [Exercise 7.6](ex7_06.h)
>对于函数add、read和print，定义你自己的版本。
## [Exercise 7.7](ex7_07.cpp)
>使用这些新函数重写7.1.2节练习中的程序。

## Exercise 7.8
>为什么read函数将其Sales_data参数定义成普通的引用，而print函数将其参数定义成常量引用？

Define `read`'s Sales_data parameter as plain reference since it's intended to change the `revenue`'s value.

Define `print`'s Sales_data parameter as a reference to const since it isn't intended to change any member's value of this object.

## [Exercise 7.9](ex7_09.h)
>对于7.1.2节练习中代码，添加读取和打印Person对象的操作。

## Exercise 7.10
>在下面这条if语句中，条件部分的作用是什么？
```cpp
if (read(read(cin, data1), data2))
```

we can try to divide it like that:
```
//pseudo code
std::istream &firstStep = read(cin, data1);
std::istream &secondStep = read(firstStep, data2);
if (secondStep)
```
the condition of the `if` statement would read 2 Sales_data object at one time.

## Exercise 7.11 [Header](ex7_11.h)|[CPP](ex7_11.cpp)
>> 在你的Sales_data类中添加构造函数，然后编写一段程序令其用到每个构造函数。
## [Exercise 7.12](ex7_12.h)

> 把只接受一个istream 作为参数的构造函数移到类的内部。
## [Exercise 7.13](ex7_13.cpp)
> 使用istream构造函数重写第229页的程序。
## Exercise 7.14
> 编写一个构造函数，令其用我们提供的类内初始值显式地初始化成员。

```cpp
Sales_data() : bookNo(""), units_sold(0) , revenue(0){ }
```
## [Exercise 7.15](ex7_15.h)
>为你的 Person 类添加正确的构造函数。
## Exercise 7.16
>在类的定义中对于访问说明符出现的位置和次数有限定吗？如果有，是什么？什么样的成员应该定义在public 说明符之后？什么样的成员应该定义在private 说明符之后？

There are no restrictions on how often an access specifier may appear.  The specified access level remains in effect ubtil the next access specifier or the end of the class bpdy.

The members which are accessible to all parts of the program should define after a publci specifer.

The members which are accessible to the member functions of the class but are not accessibble to code that uses the class should define after a privater specifier.

## Exercise 7.17
>使用class 和 struct 时有区别吗？如果有，是什么？

The only difference between using `class` and using `struct` to define a class is the default access level. `class` is private, `struct` is public.

## Exercise 7.18
>封装（encapsulation）是何含义？它有什么用处？

**encapsulation** is the separation of implement from interface. It hides the implementation details of a type. (In C++, encapsulation is enforced by putting the implementation in the private part of a class)

-----

Importtant advantages:


- User code cannot inadvertently corrupt the state of an encapsulation object.
- The implementation of an encapsulated class can change over time without requiring changes in user-level code.
## Exercise 7.19
>在你的Person 类中，你将把哪些成员声明成public 的？哪些声明成private 的？解释你这样做的原因。

public include: constructors, `getName()`, `getAddress()`.

private include: `name`, `address`.

The interface shold be defined as public, the data shouldn't expose to outside of the class.

## Exercise 7.20
>友元在什么时候有用？请分别举出使用友元的利弊。

`friend` is a mechanism by which a class grants access to its nonpublic members. They have the same rights as members.

**Pros**
- the useful function can refer to class members in the class scope without needing to explicitly prefix them with the class name.
- you can access all the nonpublic members conveniently
- sonmetimes, more readable to the users of class.

**Cons**:
- lessens encapsulation and therefore maintainability.
- code verbosity, declarations inside the class, outside the class.

## [Exercise 7.21](ex7_21.h)
>修改你的Sales_data 类使其隐藏实现的细节。你之前编写的关于Sales_data操作的程序应该继续使用，借助类的新定义重新编译该程序，确保其正常工作

## [Exercise 7.22](ex7_22.h)
>修改你的Person 类使其隐藏实现的细节。

## [Exercise 7.23](ex7_23.h)
>编写你自己的Screen 类型。

## [Exercise 7.24](ex7_24.h)
>给你的Screen 类添加三个构造函数：一个默认构造函数；另一个构造函数接受宽和高的值，然后将contents 初始化成给定数量的空白；第三个构造函数接受宽和高的值以及一个字符，该字符作为初始化后屏幕的内容。

## Exercise 7.25
>Screen 能安全地依赖于拷贝和赋值操作的默认版本吗？如果能，为什么？如果不能？为什么？

Of course, the class only used `string` and `built-in type`, it can rely on the default version of copy and assignment. (It can be seen at 7.1.5) 

## Exercise 7.26 [Header](ex7_26.h)
>将Sales_data::avg_price 定义成内联函数。

## Exercise 7.27 [Class](ex7_27.h)|[Test](ex7_27_TEST.cpp)
>给你自己的Screen 类添加move、set 和display 函数，通过执行下面的代码检验你的类是否正确。
```cpp
Screen myScreen(5, 5, 'X');
myScreen.move(4, 0).set('#').display(cout);
cout << "\n";
myScreen.display(cout);
cout << "\n";
```

## Exercise 7.28
>如果move、set和display函数的返回类型不是Screen& 而是Screen，则在上一个练习中会发生什么？

The second call to `display` couldn't print `#` among the output, cause the call to `set` would change the **temporary copy**, not myScreen.


## Exercise 7.29
>修改你的Screen 类，令move、set和display函数返回Screen并检查程序的运行结果，在上一个练习中你的推测正确吗？

```
#with '&'
XXXXXXXXXXXXXXXXXXXX#XXXX
XXXXXXXXXXXXXXXXXXXX#XXXX
                   ^^^
# without '&'
XXXXXXXXXXXXXXXXXXXX#XXXX
XXXXXXXXXXXXXXXXXXXXXXXXX
                   ^^^
```

## Exercise 7.30

**Pros**
- more explicit
- less scope for misreading
- can use the member function parameter which name is same as the member name.

        void setAddr(const std::string &addr) { this->addr = addr; }

**Cons**

- more to read
- sometimes redundant

        std::string getAddr() const { return this->addr; } // unnecessary

## [Exercise 7.31](ex7_31.h)

>定义一对类X 和Y，其中X 包含一个指向 Y 的指针，而Y 包含一个类型为 X 的对象。

## [Exercise 7.32](ex7_32.h)

>定义你自己的Screen 和 Window_mgr，其中clear是Window_mgr的成员，是Screen的友元。

## Exercise 7.33
>如果我们给Screen 添加一个如下所示的size成员将发生什么情况？如果出现了问题，请尝试修改它。


[clang]error: unknown type name 'pos'

fixed:
```cpp
Screen::pos Screen::size() const
{
    return height*width;
}
```

## Exercise 7.34
>如果我们把第256页Screen类的pos的typedef放在类的最后一行会发生什么情况？

There is an error in

    dummy_fcn(pos height)
               ^
    Unknown type name 'pos'
    
## Exercise 7.35    
>解释下面代码的含义，说明其中的Type和initVal分别使用了哪个定义。如果代码存在错误，尝试修改它。
```cpp
typedef string Type;
Type initVal(); 
class Exercise {
public:
    typedef double Type;
    Type setVal(Type);
    Type initVal(); 
private:
    int val;
};
Type Exercise::setVal(Type parm) { 
    val = parm + initVal();     
    return val;
}
```

* the 1st `Type` use `string`
* the 2nd and 3rd 'Type' use `double`
* for the 
    ```cpp
        Type Exercise::setVal(Type parm) { // 1st is `string` , 2nd is `double`
        val = parm + initVal();     // Exercise:: initVal
        return val;
    }
    ```

**fixed**

```cpp
Exercise::Type Exercise::setVal(Type parm) {
    val = parm + initVal();
    return val;
}
```
and `Exercise::initVal()` should be defined.

## Exercise 7.36
>下面的初始值是错误的，请找出问题所在并尝试修改它。
```cpp
struct X {
	X (int i, int j): base(i), rem(base % j) {}
	int rem, base;
};
```
>In this case, the constructor initializer makes it appear as if `base` is initialized with `i` and then `base` is used to initialize `rem`. However, `rem` is initialized first. The effect of this initializer is to initialize `rem` with the undefined value of `base`!
**fixed**
```cpp
struct X {
    
	X (int i, int j): base(i), rem(base % j) {}
	int base, rem; // the order 
};
```
## Exercise 7.37
>使用本节提供的Sales_data类，确定初始化下面的变量时分别使用了哪个构造函数，然后罗列出每个对象所有的数据成员的值。

```cpp
Sales_data first_item(cin); // use Sales_data(std::istream &is) ; its value are up to your input.
int main() {
	Sales_data next; // use Sales_data(std::string s = ""); bookNo = "", cnt = 0, revenue = 0.0

	
	Sales_data last("9-999-99999-9");  // use Sales_data(std::string s = ""); bookNo = "9-999-99999-9", cnt = 0, revenue = 0.0
}
```

## Exercise 7.38
>有些情况下我们希望提供cin作为接受istream& 参数的构造函数的默认实参，请声明这样的构造函数。
```cpp
Sales_data(std::istream &is = std::cin) { read(is,*this); }
```

## Exercise 7.39
>如果接受string 的构造函数和接受 istream& 的构造函数都使用默认实参，这种行为合法吗？如果不，为什么?

illegal.. cause the call if overloaded `Sales_data()` is **ambiguous**. cannot to disrinct which is overloaded.

## Exercise 7.40
>从下面的抽象概念中选择一个（或者你自己指定一个），思考这样的类需要哪些数据成员，提供一组合理的构造函数并阐明这样做的原因
```
(a) Book
(b) Data
(c) Employee
(d) Vehicle
(e) Object
(f) Tree
```

**Book**
```cpp
class Book
{
public:
    Book() = default;
    Book(unsigned isbn, std::string const& name, std::string const& author, std::string const&pubdate)
        : isbn_no(isbn), book_name(name), book_author(author), book_pubdate(pubdate) { }

    explicit Book(std::istream &is) //
    {
        is >> isbn_no >> book_name >> book_author >> book_pubdate;
    }

private:
    unsigned isbn_no;
    std::string book_name;
    std::string book_author;
    std::string book_pubdate;
};
```

## Exercise 7.41 [Header](ex7_41.h)|[Cpp](ex7_41.cpp)
>使用委托构造函数重新编写你的Sales_data 类，给每个构造函数体添加一条语句，令其一旦执行就打印一条信息。用各种可能的方式分别创建 Sales_data 对象，认真研究每次输出的信息直到你确实理解了委托构造函数的执行顺序
The result is shown as following:
```
1. default way: 
----------------
Sales_data(const std::string &s, unsigned n, double p)
default Sales_data(,0,0)

2. use std::string as parameter: 
----------------
Sales_data(const std::string &s, unsigned n, double p)
Sales_data(const std::string &s)

3. complete parameters:
----------------
Sales_data(const std::string &s, unsigned n, double p)

4. use istream as parameter:
----------------
Sales_data(const std::string &s, unsigned n, double p)
default Sales_data(,0,0)
1 2 3
Sales_data(std::istream &is)
```

## Exercise 7.42
>对于你在练习7.40中编写的类，确定哪些构造函数可以使用委托。如果可以的话，编写委托构造函数。如果不可以，从抽象概念列表中重新选择一个你认为可以使用委托构造函数的，为挑选出的这个概念编写类定义。
```cpp
class Book 
{
public:
    Book(unsigned isbn, std::string const& name, std::string const& author, std::string const& pubdate)
        :isbn_(isbn), name_(name), author_(author), pubdate_(pubdate)
    { }

    Book(unsigned isbn) : Book(isbn, "", "", "") {}

    explicit Book(std::istream &in) 
    { 
        in >> isbn_ >> name_ >> author_ >> pubdate_;
    }

private:
    unsigned isbn_;
    std::string name_;
    std::string author_;
    std::string pubdate_;
};
```

## [Exercise 7.43](ex7_43.cpp)
>假定有一个名为 NoDefault 的类，它有一个接受 int 的构造函数，但是没有默认构造函数。定义类 C，C 有一个 NoDefault 类型的成员，定义C 的默认构造函数。

## Exercise 7.44
>下面这条声明合法吗？如果不，为什么？
`vector<NoDefault> vec(10);`

illegal, cause there are ten elements, each would be default initialized. But no default initializer for the temporary object.
 NoDefault 没有默认构造函数

## Exercise 7.45
>如果在上一个练习中定义的vector的元素类型是C，则声明合法吗？为什么？

legal. cause `C` have the default constructor.

## Exercise 7.46
>下面哪些论断是不正确的？为什么？
```
(a) 一个类必须至少提供一个构造函数。
(b) 默认构造函数是参数列表为空的构造函数。
(c) 如果对于类来说不存在有意义的默认值，则类不应该提供默认构造函数。
(d) 如果类没有定义默认构造函数，则编译器将为其生成一个并把每个数据成员初始化成相应类型的默认值。
```
- (a) A class must provide at least one constructor. 
    * **untrue**. "The compiler-generated constructor is known as the synthesized default constructor."
- (b) A default constructor is a constructor with an empty parameter list. 
    * **untrue**. A default constructor is a constructor that is used if no initializer is supplied.What's more, A constructor that supplies default arguments for all its parameters also defines the default constructor
- (c) If there are no meaningful default values for a class, the class should not provide a default constructor. 
    * **untrue**.  The defalut constructor should be provided. 
- (d) If a class does not define a default constructor, the compiler generates one that initializes each data member to the default value of its associated type.
    * **untrue**.  only if our class does not explicitly define **any constructors**, the compiler will implicitly define the default constructor for us.

## Exercise 7.47
>说明接受一个string 参数的Sales_data构造函数是否应该是explicit的，并解释这样做的优缺点。

Whether the conversion of a `string` to `Sales_data` is desired **depends on how we think our users will use the conversion**. In this case, it might be okay. The `string` in null_book probably represents a nonexistent ISBN.

Benefits:

- prevent the use of a constructor in a context that requires an implicit conversion
- we can define a constructor which is used only with the direct form of initialization

Drawbacks:

- meaningful only on constructors that can be called with a single argument

## Exercise 7.48
>假定Sales_data 的构造函数不是explicit的，则下述定义将执行什么样的操作？如果是explicit的，会发生什么？
```cpp
string null_isbn("9-999-9999-9");
Sales_data item1(null_isbn);
Sales_data item2("9-999-99999-9");
```
Both are nothing happened.

## Exercise 7.49
>对于combine 函数的三种不同声明，当我们调用i.combine(s) 时分别发生什么情况？其中 i 是一个 Sales_data，而 s 是一个string对象。
```cpp
(a) Sales_data &combine(Sales_data); // ok
(b) Sales_data &combine(Sales_data&); // [Error] no matching function for call to 'Sales_data::combine(std::string&)' (`std::string&` can not convert to `Sales_data` type.) 
(c) Sales_data &combine(const Sales_data&) const; // The trailing const mark can't be put here, as it forbids any mutation on data members. This conflicts with combine's semantics. 该成员函数是const 的，意味着不能改变对象。而 combine函数的本意就是要改变对象
```

Some detailed explanation about problem (b) :It's wrong. Because `combine`’s parameter is  a non-const reference , we can't  pass a temporary to that parameter. If `combine`’s parameter is  a  reference to const , we can  pass a temporary to that parameter. Like this :`Sales_data &combine(const Sales_data&); `  Here we call the `Sales_data` `combine` member function with a string argument. This call is perfectly legal; the compiler automatically creates a `Sales_data` object from the given string. That newly generated (temporary) `Sales_data` is passed to `combine`.(Also you can read C++ Primer Page 295(English Edition))

## [Exercise 7.50](ex7_50.h)
>确定在你的Person 类中是否有一些构造函数应该是 explicit 的。

只对含有一个实参的构造函数有效

## Exercise 7.51
>vector 将其单参数的构造函数定义成 explicit 的，而string则不是，你觉得原因何在？

Such as a function like that:

```cpp
int getSize(const std::vector<int>&);
```

if vector has not defined its single-argument constructor as explicit. we can use the function like:

```cpp
getSize(34);
```

What is this mean? It's very confused. The function actually initializes a temporary of a 34-element vector, and then returns 34. But it doesn't make any sense.

But the `std::string` is different. In ordinary, we use `std::string` to replace `const char *`(the C language). so when we call a function like that:

```cpp
void setYourName(std::string); // declaration.
setYourName("pezy"); // just fine.
```

it is very natural.


**从参数类型到类类型的自动转换是否有意义依赖于程序员的看法，如果这种转换是自然而然的，则不应该把它定义成explicit的；如果二者的语义距离较远，则为了避免不必要的转换，应该指定对应的构造函数是explicit的。**

string接收的单参数是`const char*`类型，如果我们得到了一个非常量指针（字符数组），则把它看作`string`对象是自然而然的过程，编译器自动把参数类型转换成类类型也非常符合逻辑，因此我们无须指定为`explicit`的。

与string相反，vector接收的单参数类型是int类型，这个参数的原意是指定vector的容量。如果我们在本来需要vector的地方提供一个int值并且希望这个int值自动转换成vector，则这个过程显得比骄傲牵强，因此把vector的单参数构造函数定义成explicit的更加合理。

## Exercise 7.52
>使用2.6.1节的 Sales_data 类，解释下面的初始化过程。如果存在问题，尝试修改它。

    `Sales_data item = {"987-0590353403", 25, 15.99};`

Sales_data is not a aggregate class, so we cannot initialize it by providing a craced list of member initializers.

FIXED:

```cpp
struct Sales_data {
    std::string bookNo;
    unsigned units_sold;
    double revenue;
};
```
## [Exercise 7.53](ex7_53.h)
>定义你自己的 Debug。

## Exercise 7.54
>Debug中以 set_ 开头的成员应该被声明成 constexpr 吗？如果不，为什么？

in C++11, constexpr member functions are implicitly const, so the "set_xx" functions, which will modify data members, cannot be declared as constexpr. In C++14, this property no longer holds, so constexpr is suitable.

## Exercise 7.55

>7.5.5节的 Data 类是字面值常量类吗？请解释原因。
no.

`std::string` is not a literal type, and it can be verified by following codes:

```cpp
#include <string>
#include <iostream>
#include <type_traits>

struct Data {
    int ival;
    std::string s;
};

int main()
{
    std::cout << std::boolalpha;
    std::cout << std::is_literal_type<Data>::value << std::endl;
    // output: false
}
```
## Exercise 7.56

>What is a static class member?

A class member that is **associated with the class**, rather than with individual objects of the class type.

>What are the advantages of static members?

each object can no need to store a common data. And if the data is changed, each object can use the new value.

>How do they differ from ordinary members?

- a static data member can have **incomplete type**.
- we can use a static member **as a default argument**.

## [Exercise 7.57](ex7_57.h)
>编写你自己的 Account 类。

## Exercise 7.58

>下面的静态数据成员的声明和定义有错误吗？请解释原因。
```cpp
//example.h
class Example {
public:
	static double rate = 6.5;
	static const int vecSize = 20;
	static vector<double> vec(vecSize);
};
//example.c
#include "example.h"
double Example::rate;
vector<double> Example::vec;
```
rate 应该是一个常量表达式。而类内只能初始化整型类型的静态常量，所以不能在类内初始化vec。修改后如下：
```cpp
//example.h
class Example {
public:
	static double rate = 6.5;
	static const int vecSize = 20;
	static vector<double> vec;
};
//example.c
#include "example.h"
constexpr double Example::rate;
vector<double> Example::vec(Examole::vecSize);
```