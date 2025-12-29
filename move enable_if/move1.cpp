/*
    转发传递实参的基本属性泛型代码
    1.可修改对象应该被转发
    2.常量对象作为只读对象转发
    3.可移动对象应该作为可移动对象转发
*/

#include <utility>
#include <iostream>

class X{

};

void g(X&){
    std::cout<<"g(X&)"<<std::endl;
}

void g(X const&){
    std::cout<<"g(X const&)"<<std::endl;
}

void g(X&&){
    std::cout<<"g(X&&)"<<std::endl;
}

//下面三种情况可以变为一个泛型函数
// void f(X& val){
//     g(val);
// }

// void f(X const& val){
//     g(val);
// }

// void f(X&& val){
//     //val为非常量左值
//     g(std::move(val));
// }

template <typename T>
void f(T&& val){
    g(std::forward<T>(val));    //调用合适的g()
}

int main(){
    X x;
    const X cx;

    f(x);      //调用f(X& val)
    f(cx);     //调用f(X const& val)
    f(X{});    //调用f(X&& val)
    f(std::move(x));
}