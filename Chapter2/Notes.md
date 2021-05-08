### top-level const & low-level const
top-level const to indicate that the pointer itself is a const. When a pointer can point to a const object, we refer tothat const as a low-level const.
* 一般的变量来说，其实没有顶层const和底层const的区别
1.一个指针本身添加const限定符就是顶层const。（指针被限定则 顶）
　　　　　　　　　　　　　　　　  2.而指针所指的对象添加const限定符就是底层const。（对象被限则 底）

* 执行对象拷贝时有限制，常量的底层const不能赋值给非常量的底层const。
```cpp
int num_c = 3;  
const int *p_c = &num_c;  //p_c为底层const的指针     还有一点记住  就是不能通过p_c去修改变量的值
//int *p_d = p_c;  //错误，不能将底层const指针赋值给非底层const指针  
const int *p_d = p_c; //正确，可以将底层const指针复制给底层const指针  
```
* 使用命名的强制类型转换函数const_cast时，需要能够分辨底层const和顶层const，因为const_cast只能改变运算对象的底层const
```cpp
int num_e = 4;  
const int *p_e = &num_e;  
//*p_e = 5;  //错误，不能改变底层const指针指向的内容  
int *p_f = const_cast<int *>(p_e);  //正确，const_cast可以改变运算对象的底层const。但是使用时一定要知道num_e不是const的类型。  
*p_f = 5;  //正确，非顶层const指针可以改变指向的内容  
cout << num_e;  //输出5 
```