## Exercise 5.1
>What is a null statement? When might you use a null statement?
A null statement is the empty statement. like this:
```cpp
; // null statement
```
The null statement may be used as a placeholder when a statement is expected. For example:
```cpp
// read until we hit end-of-file or find an input equal to sought
while (cin >> s && s != sought)
    ; // null statement.
```

## Exercise 5.2
>What is a block? When might you might use a block?

A block is a (possibly empty) sequence of statements and declarations surrounded by a pair of curly braces.It's used when multiple statements are needed.For example:
```cpp
while (val <= 10)
{
    sum += val;
    ++val;
}
```
## Exercise 5.3
>Use the comma operator (§ 4.10, p. 157, p. 140 chinese edition) to rewrite the while loop from § 1.4.1 (p. 11, p. 11 chinese edition) so that it no longer requires a block. Explain whether this rewrite improves or diminishes the readability of this code.

```cpp
#include <iostream>
int main()
{
    int sum = 0, val = 1;
    while (val <= 10)
        sum += val, ++val;
    std::cout << "Sum of 1 to 10 inclusive is " << sum << std::endl;

    return 0;
}
```
This rewritten version diminishes the readability. 
## Exercise 5.4
>Explain each of the following examples, and correct any problems you detect.
    - (a) while (string::iterator iter != s.end()) { /* . . . */ }
    - (b) while (bool status = find(word)) { /* . . . */ } if (!status) { /* . . . */ }

Solution:
(a) illegal declaration: `string::iterator iter != s.end()`
```cpp
string::iterator iter = s.begin;
while (iter != s.end()) { /* . . . */ }
```

(b)  Variable `status` is only declared inside scope of while condition.
```cpp
//corrrected as:
bool status;
while (status = find(word)) { /* ... */ }
if (!status) { /* ... */ }
```  
## [Exercise 5.5](ex5_5.cpp)
## [Exercise 5.6](ex5_6.cpp)
## Exercise 5.7
>Correct the errors in each of the following code fragments:
```cpp
(a) if (ival1 != ival2) ival1 = ival2
    else ival1 = ival2 = 0;
(b) if (ival < minval) minval = ival;
    occurs = 1;
(c) if (int ival = get_value())
    cout << "ival = " << ival << endl;
    if (!ival)
    cout << "ival = 0\n";
(d) if (ival = 0)
    ival = get_value();
```