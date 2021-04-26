
### cctype 头文件中的函数
-- isalnum(c) 
-- isalpha(c)
-- iscntrl(c)
-- isdigit(c)
-- isgraph(c)
-- islower(c)
-- isprint(c)
-- ispunct(c)
-- isspace(c)
-- isupper(c)
-- isxdigit(c)
-- tolower(c)
-- toupper(c)
### 处理每个字符，可使用基于范围的`for`语句

```
for (declaration : expression)
    statement
```
 expression is an object; declaration is the defination of a variable `c`. In each iteration, the variable in the declaration part is initialized to the value of the next element in the expression part.

> Example

```cpp
string str("some string");
for (auto c : str)          //Use the auto  to let the compiler determine the type of variable c
    cout << c << endl;
```

or
```cpp
string str("some string");
for (auto &c : str)          //here c is a reference so that we can change the value of str
    c = toupper(c);
cout << c << endl;
```
### 处理一部分字符
Use the subscript operator `[ ]`, indicate the position of the accessed character, and the return value is a reference to the character at that position. 
> From zero(0)