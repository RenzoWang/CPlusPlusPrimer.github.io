## Exercise 4.1
>What is the value returned by 5 + 10 * 20/2?

105
## Exercise 4.2
>Using Table 4.12 (p. 166)(p. 147 Chinese edition), parenthesize the following expressions to indicate the order in which the operands are grouped:

```cpp
* vec.begin() //=> *(vec.begin())
* vec.begin() + 1 //=> (*(vec.begin())) + 1
```

## Exercise 4.3
>Order of evaluation for most of the binary operators is left undefined to give the compiler opportunities for optimization. This strategy presents a trade-off between efficient code generation and potential pitfalls in the use of the language by the programmer. Do you consider that an acceptable trade-off? Why or why not?

No, It depends on programmer rather than make a rule for it.
## Exercise 4.4
>Parenthesize the following expression to show how it is evaluated. Test your answer by compiling the expression (without parentheses) and printing its result.
```cpp
12 / 3 * 4 + 5 * 15 + 24 % 4 / 2
// parenthesize
((12 / 3) * 4) + (5 * 15) + ((24 % 4) / 2)
```
16 + 75 + 0 = 91

## Exercise 4.5
>Determine the result of the following expressions.
```cpp
-30 * 3 + 21 / 5  // -90 + 4 = -86
-30 + 3 * 21 / 5  // -30 + 63 / 5 = -30 + 12 = -18
30 / 3 * 21 % 5   // 10 * 21 % 5 = 210 % 5 = 0
-30 / 3 * 21 % 4  // -10 * 21 % 4 = -210 % 4 = -2
```
## Exercise 4.6
>Write an expression to determine whether an int value is even or odd.
```cpp
a) if((i % 2) == 0)     // 0 is even, not is odd
b)  i & 0x1 
```
## Exercise 4.7
>What does overflow mean? Show three expressions that will overflow.

from the book:
>Some arithmetic expressions yield undefined results. Some of these undefined espressions are due to the nature of mathematics-for example, division by zero. Others are undefined due to the nature of computers-for example, due to overflow. Overflow happens when a value is computed that is outside the range of values that the type can represent.

```cpp
short svalue = 32767; ++svalue; // -32768
unsigned uivalue = 0; --uivalue;  // 4294967295
unsigned short usvalue = 65535; ++usvalue;  // 0
```

## Exercise 4.8
>Explain when operands are evaluated in the logical `AND`, logical `OR`, and equality operators.

from the book:
> The logical `AND` and `OR` operators always evaluate their left operand before the right. Moreover, the right operand is evaluated if and only if the left operand does not determine the result. This strategy is known as **short-circuit evaluation**.

- logical `AND` : the second operand is evaluated if and only if the left side is `true`.
- logical `OR`  : the second operand is evaluated if and only if the left side is `false`
- equality operators `==` : undefined.

## Exercise 4.9
>Explain the behavior of the condition in the following if:
```cpp
const char *cp = "Hello World";
if (cp && *cp)
```
- 1st.  cp is a pointer to `const char *`, and it's not a nullptr, true.
- 2nd. `*cp` is a const char: `'H'`, and it's ASCII value is not a zero. true.
- true && true -> true.

## Exercise 4.10
>Write the condition for a while loop that would read ints from the standard input and stop when the value read is equal to 42.
```cpp
int i = 0;
while(cin >> i &&  i != 42) /*...*/
```
## Exercise 4.11
>Write an expression that tests four values, a, b, c, and d, and ensures that a is greater than b, which is greater than c, which is greater than d.
```cpp
a>b && b > c && c >d;
```

## Exercise 4.12
>Assuming `i`, `j`, and `k` are all ints, explain what `i != j < k` means.

`i != j < k` is equivalent to `i != (j < k)`. Cause `!=` precedence is lower than `<`

## Exercise 4.13
>What are the values of i and d after each assignment?
```cpp
int i;   double d;
d = i = 3.5; // i = 3, d = 3.0
i = d = 3.5; // d = 3.5, i = 3
```
## Exercise 4.14
>Explain what happens in each of the if tests:
```cpp
if (42 = i)   // complie error: expression is not assignable
if (i = 42)   // true. i will be assigned as 42
```

## Exercise 4.15
>The following assignment is illegal. Why? How would you correct it?
```cpp
double dval; int ival; int *pi;
dval = ival = pi = 0;
// pi is a pointer to int. can not assign to `int` from type 'int *'
// the right one is
dval = ival = 0;
pi = 0;
```
## Exercise 4.16
>Although the following are legal, they probably do not behave as the programmer expects. Why? Rewrite the expressions as you think they should be.
```cpp
if (p = getPtr() != 0)
if (i = 1024)
```
in the `if` , it always true. use an assigment as a condition.
> the correct 
```cpp
if ((p=getPtr()) != 0)
if (i == 1024)
```


## Exercise 4.17
>Explain the difference between prefix and postfix increment.

prefix increment will return the object itself as the lvalue.
postfix increment will return a copy of original value of the object as an rvalue.

See: [What is the difference between ++i and i++](http://stackoverflow.com/questions/24853/what-is-the-difference-between-i-and-i)

## Exercise 4.18
>What would happen if the while loop on page 148(p. 132 Chinese Edition) that prints the elements from a vector used the prefix increment operator?

It will print the 2nd value and start from it. And at the end it will try to print `v.end()`, but the value is **Undefined**

// Anwser from another repo
It will print from the second element and dereference `v.end()` at last, which is a **UB**.

## Exercise 4.19
>Given that ptr points to an int, that vec is a vector<int>, and that ival is an int, explain the behavior of each of these expressions. Which, if any, are likely to be incorrect? Why? How might each be corrected?

```cpp
ptr != 0 && *ptr++  // check ptr is not a nullptr, and then check the pointer value. Then point ptr to the next element
ival++ && ival // check ival whether is true, and then check ival+1 whether equal zero(0 is also flase by default).
vec[ival++] <= vec[ival] // incorrect. It is an **undefined behavior.** . C++ does not specify the order of evaluation on both sides of the <= operator, it should be changed to
// correct:
vec[ival] <= vec[ival+1]
```
See [order of evaluation](http://en.cppreference.com/w/cpp/language/eval_order).

## Exercise 4.20
>Assuming that iter is a vector<string>::iterator, indicate which, if any, of the following expressions are legal. Explain the behavior of the legal expressions and why those that aren’t legal are in error.
```cpp
(a) *iter++;
(b) (*iter)++;
(c) *iter.empty();
(d) iter->empty();
(e) ++*iter;
(f) iter++->empty();
```
* Solution:
```cpp
(a) *iter++;        //legal. return *iter, and then ++iter
(b) (*iter)++;      //illegal. *iter is a string. cannot increment value.
(c) *iter.empty();  //illegal. iter is a pointer. should use `->` to indicate whether empty. or (*iter).empty()
(d) iter->empty();  //legal. check whether iter is empty
(e) ++*iter;        //illegal. *iter is a string. cannot increment value.
(f) iter++->empty();//legal. return iter->empty(), then ++iter 
```
## [Exercise 4.21](ex4_21.cpp)
>Write a program that uses conditional operators to find out which elements of the vector have odd values, and then double these odd values.
## [Exercise 4.22](ex4_22.cpp)
>本节的示例程序将成绩划分为high pass、pass 和 fail 三种，扩展该程序使其进一步将 60 分到 75 分之间的成绩设定为 low pass。要求程序包含两个版本：一个版本只使用条件运算符；另一个版本使用1个或多个if语句。哪个版本的程序更容易理解呢？为什么？
第二个版本容易理解。当条件运算符嵌套层数变多之后，代码的可读性急剧下降。而if else 的逻辑很清晰。
## Exercise 4.23
>The following expression fails to compile due to operator precedence. Using Table 4.12 (p. 166), explain why it fails. How would you fix it?
```cpp
string s = "word";
string pl = s + s[s.size() - 1] == 's' ? "" : "s" ;
```

Operator Precedence: `?:` < `+`s
Fix it:
```cpp
string pl = s + (s[s.size() - 1] == 's' ? "" : "s") ;
```
## Exercise 4.24
>Our program that distinguished between high pass, pass, and fail depended on the fact that the conditional operator is right associative. Describe how that operator would be evaluated if the operator were left associative.

if the operator were left associative. That's means the code starts from the left.
```cpp
finalgrade = (grade > 90) ? "high pass" : (grade < 60) ? "fail" : "pass";
```

wolud same as:
```cpp
finalgrade = ( (grade > 90) ? "high pass" : (grade < 60) ) ? "fail" : "pass";
```
if `grade > 90`, the 1st conditional operator's result is `high pass`. and the 2nd conditional operator's result is `true` and the final grade is always "fail". 
It's contradictory obviously.

## Exercise 4.25
>What is the value of ~'q' << 6 on a machine with 32-bit ints and 8 bit chars, that uses Latin-1 character set in which 'q' has the bit pattern 01110001?

1st, improve the `char` to `int`, same as `(~ 00000000 00000000 0000000 01110001) << 6`, and the result is `11111111 11111111 11100011 10000000`
and the dimical value is `-7296`
>> Note there is a `~` before `q`.
## Exercise 4.26
>In our grading example in this section, what would happen if we used unsigned int as the type for quiz1?
 The minimum range of `unsigned int` is 0 to 65535. Since some implementations use only the minimum 16 bits for `ubsigned int`, this could cause undefined behavior.

## Exercise 4.27
>What is the result of each of these expressions?
```cpp
unsigned long ul1 = 3, ul2 = 7;
(a) ul1 & ul2 
(b) ul1 | ul2 
(c) ul1 && ul2
(d) ul1 || ul2 
```
Solution:
```cpp
(a) ul1 & ul2   // == 3
(b) ul1 | ul2   // == 7
(c) ul1 && ul2  // true
(d) ul1 || ul2  // true
```
## [Exercise 4.28](ex4_28.cpp)
> Write a program to output the size of the space occupied by each built-in type.
## Exercise 4.29
>Predict the output of the following code and explain your reasoning. Now run the program. Is the output what you expected? If not, figure out why.
```cpp
int x[10];   int *p = x;
cout << sizeof(x)/sizeof(*x) << endl;
cout << sizeof(p)/sizeof(*p) << endl;
```

* the 1st is 10; It return the size of the array.(the space belongs to the array / the type of the elements in the array = the num of elements in the array)
* the 2nd result is undefined.(`sizeof(p)` return the size of the space occupied by the pointer[also the `x[0]` space] /  the size of the type of the first elements in `x` also `x[0]` )

-----
reference: [Why the size of a pointer is 4bytes in C++](http://stackoverflow.com/a/2428809)

## Exercise 4.30
>Using Table 4.12 (p. 166), parenthesize the following expressions to match the default evaluation:
```cpp
sizeof x + y      // (sizeof x)+y . "sizeof" has higher precedence than binary `+`.
sizeof p->mem[i]  // sizeof(p->mem[i])
sizeof a < b      // sizeof(a) < b
sizeof f()        //If `f()` returns `void`, this statement is undefined, otherwise it returns the size of return type.
```

reference: [sizeof operator](http://en.cppreference.com/w/cpp/language/sizeof)
## Exercise 4.31
>The program in this section used the prefix increment and decrement operators. Explain why we used prefix and not postfix. What changes would have to be made to use the postfix versions? Rewrite the program using postfix operators.

As mentioned in Section 4.5 (page 132,chinese edition), unless you have to, you don’t need the post-increment version of the decrement operator.  There is no need for any changes to use the latter version of the increment and decrement operator.

>**Advice: Use Postfix Operators only When Necessary**

>Readers from a C background might be surprised that we use the prefix increment in the programs we've written. The reason is simple: The prefix version avoids unnecessary work. It increments the value and returns the incremented version.The postfix operator must store the original value so that it can return the unincremented value as its result. If we don’t need the unincremented value, there’s no need for the extra work done by the postfix operator.

>For ints and pointers, the compiler can optimize away this extra work. For more complicated iterator types, this extra work potentially might be more costly. By habitually using the prefix versions, we do not have to worry about whether the performance difference matters. Moreover—and perhaps more importantly—we can express the intent of our programs more directly.

So, it's just a good habits. And there are no changes if we have to be made to use the postfix versions. Rewrite:
```cpp
for(vector<int>::size_type ix = 0; ix != ivec.size(); ix++, cnt--)  
    ivec[ix] = cnt;
```

This is not an appropriate example to discuss the difference of prefix and postfix. Look at the section `Built-in comma operator` on [this page](http://en.cppreference.com/w/cpp/language/operator_other).

-----
reference: [Usage of the Built-in Comma Operator](http://stackoverflow.com/questions/22591387/usage-of-the-built-in-comma-operator)
## Exercise 4.32
>Explain the following loop.
```cpp
constexpr int size = 5;
int ia[size] = { 1, 2, 3, 4, 5 };
for (int *ptr = ia, ix = 0;
    ix != size && ptr != ia+size;
    ++ix, ++ptr) { /* ... */ }
```

use the for loop to through the array. the 'ptr' and 'ix' as the count number, the former is a pointer, the later is the index of array.

## Exercise 4.33
>Using Table 4.12 (p. 166, p. 147 chinese edition) explain what the following expression does:
```cpp
someValue ? ++x, ++y : --x, --y
```
Because of the most lowest precedence of the comma operator, the expression is same as:
```cpp
(someValue ? ++x, ++y : --x), --y
```
if `someValue` is `true`, then `++x`, and the result is 'y';
if `someValue` is `false`, then `--x`, and the result is `--y` 

so it is also same as:
```cpp
someValue ? (++x, y) : (--x, --y);
```
Even though the result has nothing to do with `x`, the evaluation of `someValue` does effect the operation on `x`.

## Exercise 4.34
>Given the variable definitions in this section, explain what conversions take place in the following expressions:
    (a) if (fval)
    (b) dval = fval + ival;
    (c) dval + ival * cval;
    
    Remember that you may need to consider the associativity of the operators.

Solution:
```cpp
    (a) if (fval)           // convert to bool
    (b) dval = fval + ival; // ival converted to float, then the result of fval add ival converted to double.
    (c) dval + ival * cval; // cval converted to int, the that int converted to double
```

## Exercise 4.35
>Given the following definitions,
    ```cpp
    char cval; 
    int ival; 
    unsigned int ui; 
    float fval; 
    double dval;
    ```
    identify the implicit type conversions, if any, taking place:

    ```cpp
    (a) cval = 'a' + 3;
    (b) fval = ui - ival * 1.0;
    (c) dval = ui * fval;
    (d) cval = ival + fval + dval;
    ```

Solution:
```cpp
(a) cval = 'a' + 3;             // 'a' promoted to int, then the result of ('a' + 3)(int) converted to char.
(b) fval = ui - ival * 1.0;     // ival converted to double, ui converted to double, then the result will be converted to float(by truncation)
(c) dval = ui * fval;           // ui converted to float, then the result converted to double
(d) cval = ival + fval + dval;  // ival converted to float, then that float cenverted to double. At last that double converted to cahr(by truncation)
```

## Exercise 4.36
>Assuming i is an int and d is a double write the expression i *= d so that it does integral, rather than floating-point, multiplication.

```cpp
i *= static_cast<int>(d);
```

## Exercise 4.37
>Rewrite each of the following old-style casts to use a named cast:
```cpp
int i; double d; const string *ps; char *pc; void *pv;
(a) pv = (void*)ps;
(b) i = int(*pc);
(c) pv = &d;
(d) pc = (char*)pv;
```
Solution:
```cpp
(a) pv = static_cast<void*>(const_cast<string*>(ps));
(b) i = static_cast<int>(*pc);
(c) pv = static_cast<void*>(&d);
(d) pc = static_cast<char*>pv;
```

## Exercise 4.38
>Explain the following expression:
```cpp
double slope = static_cast<double>(j/i);
```
`j/i` is and int, then converted to double and assigned to slope.
