链接器错误
hpp:类和其他类型全都放在头文件中

非内联函数模板相比内联函数和宏的重要区别:它们不会再调用处展开，而是当他们实例化时创建一个函数的新副本
可能的情况:
// utils.h
int add(int a, int b) {  // 普通函数定义在头文件
    return a + b;
}

// file1.cpp
#include "utils.h"
int x = add(1, 2);

// file2.cpp
#include "utils.h"
int y = add(3, 4);
file1.cpp → file1.o (包含 add 函数定义)
file2.cpp → file2.o (包含 add 函数定义)
链接时 → 错误！发现两个 add 函数定义
error: multiple definition of 'add(int, int)'

## 模板与inline
inline限定符是为了给编译器实现一个提示:优先在调用处用函数体来做内联替换，而不是通常的函数调用机制
inline：可以通俗理解为：直接替换
函数调用：会有保存，跳转等消耗



## 思考大篇错误信息
"class X has no member 'func'" 
可能的原因:
* 简单类型不匹配（比如lambda中传入不匹配的参数）
* 某些编译器缺少const



## 模板的基本术语

类模板，模板类

替换，实例化和特化

声明和定义

完整类型，非完整类型

模板实参，模板形参

