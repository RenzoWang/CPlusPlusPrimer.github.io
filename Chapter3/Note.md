
### cctype 头文件中的函数
-- isalnum(c)   // `c`的值为字母或数字时为真
-- isalpha(c)   // `c`的值为字母时为真
-- iscntrl(c)   // `c`的值为控制字符时为真
-- isdigit(c)   // `c`的值为数字时为真
-- isgraph(c)   // `c`的值不是空格但可以打印时为真
-- islower(c)   // `c`的值为小写字母时为真
-- isprint(c)   // `c`的值为可打印字符时为真（即c是空格或c具有可视形式）
-- ispunct(c)   // `c`的值为标点符号时为真（即c不是控制字符、数字、字母、可打印空白中的一种）
-- isspace(c)   // `c`的值为空白时为真（即c是空格、横向制表符、纵向制表符、回车符、换行符、进纸符`\f`[即换页，将光标位置移到下一页开头])中的一种）
-- isupper(c)   // `c`的值为大写字母时为真
-- isxdigit(c)  // `c`的值为十六进制数字时为真
-- tolower(c)   // 若`c`是大写字母，输出对应的小写字母，否则原样输出`c`
-- toupper(c)   // 若`c`是小写字母，输出对应的大写字母，否则原样输出`c`
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

## 标准库类型 vector
**类模版**(class template)

### 迭代器 iteratot
如果是使用了迭代器的循环体，不要向迭代器所属的容器添加元素，该操作会使vector对象的迭代器失效

## 数组
`a[d]` a 是数组的名字，d是数组的维度。
- 数组的维度必须是一个常量表达式
> 如果不清楚元素的确切个数，使用vector
> 数组生命的含义，可从数组的名字开始由内向外的顺序阅读

### 不允许拷贝和赋值
不能将数组的内容拷贝给其他数组作为初始值，也不能用数组为其他数组赋值。
```cpp
int a[] = {0,1,2};
int a2[] = a;       //illegal.不允许使用一个数组初始化另一个数组。
a2 = a;             //illegal.不能将一个数组直接赋值给另一个数组。 
```

### 标准库函数begin 和end
这两盒函数定义在iterator头文件中
```cpp
int ia[] = {0,1,2,3,4,5,6,7,8,9};
int *beg = begin(ia);       //指向ia首元素的指针
int *last = end(ia);        //指向arr尾元素的下一位置的指针
```

###  C风格字符串
C-style character string. 字符串最后一个字符后面跟着一个空字符`'\0'`.

#### C标准库String函数
可操作性C风格字符串的函数，定义在cstring头文件中
```cpp
strlen(p)       // 返回p的长度，空字符不计算在内
strcmp(p1, p2)  // 比较p1和p2的相等性。 如果p1 == p2， 返回0； 如果p1>p2，返回一个正值；如果p1 < p2，返回一个负值。
strcat(p1, p2)  //将p2 附加给p1后，返回p1
strcpy(p1, p2)  //将p2拷贝给p1，返回p1
```

### 多维数组
>使用范围for语句处理多维数组，除了最内层的循环，其他所有循环的控制变量都应该是引用类型