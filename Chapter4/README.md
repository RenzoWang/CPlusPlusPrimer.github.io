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
>The following expression fails to compile due to operator precedence.
Using Table 4.12 (p. 166), explain why it fails. How would you fix it?
```cpp
string s = "word";
string pl = s + s[s.size() - 1] == 's' ? "" : "s" ;
```

Operator Precedence: `?:` < `+`s
Fix it:
```cpp
string pl = s + (s[s.size() - 1] == 's' ? "" : "s") ;
```