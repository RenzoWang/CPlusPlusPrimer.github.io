# Chapter 8. The IO Library

## [Exercise 8.1](ex8_01.cpp)
>Write a function that takes and returns an istream&. The function should read the stream until it hits end-of-file. The function should print what it reads to the standard output. Reset the stream so that it is valid before returning the stream.
```cpp
istream& read(istream& is)
{   
    std::string str;
    for(;is >> str;)
        std::cout << str << std::endl;
    is.clear;
    return is;
}
```
## [Exercise 8.2](ex8_02.cpp)
>测试函数，调用参数为cin。

## Exercise 8.3:
>What causes the following while to terminate?
```cpp
while (cin >> i) /*  ...    */
```
putting `cin` in an error state to terminate. such as `failbit`, `eofbit` and `badbit`

## [Exercise 8.4](ex8_04.cpp)
>编写函数，以读模式打开一个文件，将其内容读入到一个string的vector中，将每一行作为一个独立的元素存于vector中。

## [Exercise 8.5](ex8_05.cpp)
>重写上面的程序，将每个单词作为一个独立的元素进行存储。

## [Exercise 8.6](ex8_06.cpp)
>重写7.1.1节的书店程序，从一个文件中读取交易记录。将文件名作为一个参数传递给main。
即使用main处理命令行选项
## [Exercise 8.7](ex8_07.cpp)
>修改上一节的书店程序，将结果保存到一个文件中。将输出文件名作为第二个参数传递给main函数。

## [Exercise 8.8](ex8_08.cpp)
>修改上一题的程序，将结果追加到给定的文件末尾。对同一个输出文件，运行程序至少两次，检验数据是否得以保留。

## [Exercise 8.9](ex8_09.cpp)
>使用你为8.1.2节第一个练习所编写的函数打印一个istringstream对象的内容。

>Use the function you wrote for the first exercise in § 8.1.2 (p.314) to print the contents of an istringstream object.
## [Exercise 8.10](ex8_10.cpp)
>编写程序，将来自一个文件中的行保存在一个vector中。然后使用一个istringstream从vector读取数据元素，每次读取一个单词。

## [Exercise 8.11](ex8_11.cpp)
>本节的程序在外层while循环中定义了istringstream 对象。如果record 对象定义在循环之外，你需要对程序进行怎样的修改？重写程序，将record的定义移到while 循环之外，验证你设想的修改方法是否正确。

## Exercise 8.12:
>Why didn’t we use in-class initializers in PersonInfo?

Here is a aggregate class. So it should have no in-class initializers.
## [Exercise 8.13](ex8_13.cpp)
>重写本节的电话号码程序，从一个命名文件而非cin读取数据。

[another version](ex8_13b.cpp)

## Exercise 8.14:
>Why did we declare entry and nums as const auto &?

cause they are all class type, not the built-in type. so reference more effective.

output shouldn't change their values. so we added the `const`.