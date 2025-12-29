#include <iostream>

template <typename T>
class Example{
public:
    typename T::SubType* ptr;   //声明SubType是一种类型

    //T::SubType * ptr      可能认为SubType是静态成员，编译器理解为乘法
};

class MyType{
public:
    using SubType = int;        //类型别名也可以是
    static int SubType;         //也可以是静态成员变量
};

Example<MyType> obj;

/*
    编译器在编译模板时不知道 T 的具体类型，因此无法判断 T::SubType 到底是什么
    他不知道T::SubType到底是什么意思

    !!!编译器的默认规则:在模板中，依赖于模板参数的名字默认不是类型

    两阶段编译
    1.模板定义(必须用typename告诉编译器这是类型)
    2.模板实例化(知道T的具体类型，去验证是否真的为类型)
*/