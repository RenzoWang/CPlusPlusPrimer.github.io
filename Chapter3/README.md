# Chapter3
## Exercise 3.1

##### [part1](/Chapter3/ex3_1a.cc)
##### [part2](/Chapter3/ex3_1b.cc)

## Exercise 3.2

##### [part1](/Chapter3/ex3_2a.cc)
##### [part2](/Chapter3/ex3_2b.cc)

## Exercise 3.3
>Explain how whitespace characters are handled in the string input operator and in the `getline` function.

- For code like `is >> s`, input is separated by whitespaces while reading into string `s`.
- For code like `getline(is, s)` input is separated by newline `\n` while reading into string `s`. Other whitespaces are ignored.
- For code like `getline(is, s, delim)`input is separated by `delim` while reading into string `s`. All whitespaces are ignored.

## Exercise 3.4
##### [part1](/Chapter3/ex3_4a.cc)
##### [part2](/Chapter3/ex3_4b.cc)

## Exercise 3.5
##### [part1](/Chapter3/ex3_5a.cc)
##### [part2](/Chapter3/ex3_5b.cc)

## [Exercise 3.6](/Chapter3/ex3_6.cc)

## Exercise 3.7
>What would happen if you define the loop control variable in the previous exercise as type char? Predict the results and then change your program to use a char to see if you were right.

`c ` would become a `char` rather than `char &`, in such case, `c` won't change anymore.

```cpp
string str("a simple string");
for (char c : str) c = 'X';
```
## [Exercise 3.8](/Chapter3/ex3_8.cc)
The range for statement is better, it does not directly manipulate the index, and is more concise.

## Exercise 3.9
>What does the following program do? Is it valid? If not, why not?
```cpp
string s;
cout << s[0] << endl; 
```
This code was dereferencing and printing the first item stored in `s`.
`s` is empty, the operation is invalid.
a.k.a. **undefined behavior**. 

## [Exercise 3.10](/Chapter3/ex3_10.cc)

## Exercise 3.11
>Is the following range for legal? If so, what is the type of c?
```cpp
const string s = "Keep out!";
for (auto &c : s){ /*... */ }
```

It depends on the code block in loop body. For example,
```cpp
    cout << c;      //legal
    c = 'X'         // illegal, cause c is const char&
```

## Exercise 3.12
>Which, if any, of the following vector definitions are in error? For those that are legal, explain what the definition does. For those that are not legal, explain why they are illegal.
```cpp
vector<vector<int>> ivec;         // legal
vector<string> svec = ivec;       // illegal. type is different
vector<string> svec(10, "null");  // legal. vector have 10 strings: "null"
```
## Exercise 3.13
>How many elements are there in each of the following vectors? What are the values of the elements?
```cpp
vector<int> v1;                 // size:0 value:no value
vector<int> v2(10);             // size:10 value:0
vector<int> v3(10, 42);         // size:10 value:42
vector<int> v4{ 10 };           // size:1 value:10
vector<int> v5{ 10, 42 };       // size:2 value:10 42
vector<string> v6{ 10 };        // size:10 value:""
vector<string> v7{ 10, "hi" };  // size:10 value:"hi"
```
## [Exercise 3.14](/Chapter3/ex3_14.cc)
## [Exercise 3.15](/Chapter3/ex3_15.cc)
## [Exercise 3.16](/Chapter3/ex3_16.cc)
## [Exercise 3.17](/Chapter3/ex3_17.cc)
## [Exercise 3.18](/Chapter3/ex3_18.cc)
Illegal
## Exercise 3.19
>// List three ways to define a vector and give it ten elements,each with the value 42. Indicate whether there is a preferred way to do so and why.
```cpp
//1st
vector<int> ivec(10.42);
//2nd
vector<int> ivec{42,42,42,42,42,42,42,42,42,42};
//3rd
vector<int> ivec;
for(int i = 0; i <10 ; ++i)
{
    ivec.push_back(42);
}
```
The 1st one is better.
## Exercise 3.20
[part1](/Chapter3/ex3_20a.cc)
[part2](/Chapter3/ex3_20b.cc)
## [Exercise 3.21](/Chapter3/ex3_21.cc)
>Redo the first exercise from § 3.3.3 (p. 105) using iterators.

## [Exercise 3.22](/Chapter3/ex3_22.cc)
>Revise the loop that printed the first paragraph in text to instead change the elements in text that correspond to the first paragraph to all uppercase. After you’ve updated text, print its contents.

## [Exercise 3.23](/Chapter3/ex3_23.cc)
>Write a program to create a vector with ten int elements. Using an iterator, assign each element a value that is twice its current value. Test your program by printing the vector.
## [Exercise 3.24](/Chapter3/ex3_24.cc)
>Redo the last exercise from § 3.3.3 (p. 105) using iterators.
## [Exercise 3.25](/Chapter3/ex3_25.cc)
## Exercise 3.26
>In the binary search program on page 112, why did we write `mid=beg+(end-beg)/2;` instead of `mid=(beg+end) /2;`?

There is no operator `+` for adding 2 iterators.

## Exercise 3.27
>Assuming txt_size is a function that takes no arguments and returns an int value, which of the following definitions are illegal? Explain why.
数组的维度必须是一个常量表达式
```cpp
unsigned buf_size = 1024;

int ia[buf_size];   // illegal, The dimension value  must be a constant expression.
int ia[4 * 7 - 14]; // legal
int ia[txt_size()]; // illegal, The dimension value must be a constant expression.
char st[11] = "fundamental";  // illegal, the string's size is 12. the dimension shoud be 12
```
## Exercise 3.28
>What are the values in the following arrays?

Note the ground variable will be initialized default.
- if it has pointer type, it is initialized to a NULL pointer;
- if it has arithmetic type, it is initialized to (positive or unsigned) zero;
- if it is an aggregate, every member is initialized (recursively) according to these rules;
- if it is a union, the first named member is initialized (recursively) according to these rules.

```cpp
string sa[10];      //all elements are empty strings
int ia[10];         //all elements are 0

int main() 
{
    string sa2[10]; //all elements are empty strings
    int ia2[10];    //all elements are undefined
}
```

## Exercise 3.29:
>List some of the drawbacks of using an array instead of a vector.

1. Size is fixed at compilign time.
2. No API as that of vector
3. Copy and assignment are not allowed.
## Exercise 3.30
> Identify the indexing errors in the following code:
```cpp
constexpr size_t array_size = 10;
int ia[array_size];
for (size_t ix = 1; ix <= array_size; ++ix)
      ia[ix] = ix;
```

the index starts from `0` rather than `1`. When `ix` equal to 10. `ia[ix]` will out of range. 

## [Exercise 3.31](/Chapter3/ex3_31.cc)
> Write a program to define an array containing 10 ints, so that the value of each element is its subscript value.

## [Exercise 3.32](/Chapter3/ex3_32.cc)
> Copy the array just created in the previous question to another array.  Use vector to rewrite the program to achieve similar functions.

## Exercise 3.33
>What would happen if we did not initialize the scores array in the program on page 116?
all values of array are undefined. like this:
![result](https://db.tt/3T4TQoo8)

## Exercise 3.34
>Given that p1 and p2 point to elements in the same array, what does the following code do? Are there values of p1 or p2 that make this code illegal?
```cpp
p1 += p2 - p1;
```

* It moves `p1` with the offest `p2 - p1`. `p1` and `p2` will point to the same adress.
* any legal value p1 and p2 make the code legal.
## [Exercise 3.35](/Chapter3/ex3_35.cc)
> Write a program that uses pointers to set the elements in the array to 0.

## [Exercise 3.36](/Chapter3/ex3_36.cc)
>Write a program to compare whether two arrays are equal.  Write another program to compare whether two vector objects are equal.
## Exercise 3.37
>What does the following program do?
```cpp
const char ca[] = { 'h', 'e', 'l', 'l', 'o' };
const char *cp = ca;
while (*cp) {
    cout << *cp << endl;
    ++cp;
}
```

This code print all chars in `ca`. **afterwards as no `\0` appended**, **UB** would happen. For most cases, the while loop here won't be terminated as expected and many rubbish would be printed out. 

## Exercise 3.38
>In this section, we noted that it was not only illegal but meaningless to try to add two pointers. Why would adding two pointers be meaningless?
The dimention

the addition of two pointers has no logical meaning, so two pointers cannot be added.

See:
- [Why can't I add pointers](http://stackoverflow.com/questions/2935038/why-cant-i-add-pointers)

## [Exercise 3.39](/Chapter3/ex3_39.cc)
## [Exercise 3.40](/Chapter3/ex3_40.cc)
> Write a program to define two character arrays and initialize them with string literals; then define a character array to store the result of the concatenation of the first two arrays.  Use strcpy and strcat to copy the contents of the first two arrays to the third array.

It's maybe illegal in standard C++, [see](https://www.javaer101.com/en/article/14515687.html), so we'd better avoid C-style string.
- See the answer. [Here](https://stackoverflow.com/questions/35142294/visual-c-expression-must-have-a-constant-value)
## [Exercise 3.41](/Chapter3/ex3_41.cc)
>Write a program to initialize a vector object with an integer array.
## [Exercise 3.42](/Chapter3/ex3_42.cc)
>Write a program to copy a vector object containing integer elements to an integer array.
## [Exercise 3.43](/Chapter3/ex3_43.cc)
>Write 3 different versions of the program, so that all of them can output the elements of ia.  Version 1 uses the range for statement to manage the iterative process; Version 2 and Version 3 both use ordinary for statements, where version 2 requires the use of subscript operators, and version 3 requires the use of pointers.  In addition, the data type must be written directly in all three versions of the program, and type aliases, auto keywords, and decltype keywords cannot be used.
## [Exercise 3.44](/Chapter3/ex3_44.cc)
>Rewrite the program in the previous exercise and use type aliases to replace the types of loop control variables.
## [Exercise 3.45](/Chapter3/ex3_45.cc)
>Rewrite the program again, this time using the `auto` keyword.