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
## [Exercise 7.32](ex7_32.h)