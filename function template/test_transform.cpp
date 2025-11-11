#include <iostream>

template <typename T>
T max(T a,T b){
    std::cout<<typeid(T).name<<std::endl;
    return a>b?a:b;
}

int main(){
    int const c = 42;
    // max(4,7.2);  错误：T可能推到为int或double
    // std::string s;
    // max("hello",s) 错误:T可能推导为const[6]或std::string

    //解决做法
    max(static_cast<double>(4),7.2);        //强制转换实参使二者都匹配
    max<double>(4,7.2);         //显式指定T的类型，阻止了编译器进行类型推导
}