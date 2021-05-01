# Chapter 5 Statements

## 5.1 简单语句

* 表达式语句（expression statement）
* 空语句（null statement）
* 复合语句（compound statement）， 也被称作块block
> 块不以分号作为结束

## 5.2 语句作用域
可以在if, switch,while,for语句的控制结构内定义变量。定义在block内的变量只在相应语句的内部可见，一旦语句结束，变量也就超出了其控制范围。

## 5.3 条件语句

### 5.3.1 if
- **悬垂else**（dangling else）：用来描述在嵌套的`if else`语句中，如果`if`比`else`多时如何处理的问题。C++使用的方法是`else`匹配最近没有配对的`if`。
### 5.3.2 switch

## 5.4 迭代语句
A [reference](https://stackoverflow.com/questions/2950931/for-vs-while-in-c-programming)
### 5.4.1 while
### 5.4.2 for
### 5.4.3 range for
### 5.4.4 do while

## 5.5 跳转语句

- **break**：`break`语句负责终止离它最近的`while`、`do while`、`for`或者`switch`语句，并从这些语句之后的第一条语句开始继续执行。
- **continue**：终止最近的循环中的当前迭代并立即开始下一次迭代。只能在`while`、`do while`、`for`循环的内部。

## try语句块和异常处理

- **throw表达式**：异常检测部分使用 `throw`表达式来表示它遇到了无法处理的问题。我们说 `throw`引发 `raise`了异常。
- **try语句块**：以 `try`关键词开始，以一个或多个 `catch`字句结束。 `try`语句块中的代码抛出的异常通常会被某个 `catch`捕获并处理。 `catch`子句也被称为**异常处理代码**。
- **异常类**：用于在 `throw`表达式和相关的 `catch`子句之间传递异常的具体信息。