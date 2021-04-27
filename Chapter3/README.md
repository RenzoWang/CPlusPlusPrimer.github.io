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