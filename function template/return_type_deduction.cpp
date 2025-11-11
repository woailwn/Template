#include <iostream>
#include <type_traits>
//a,b可能带引用?
// template<typename T1,typename T2>
// auto max(T1 a,T2 b)->decltype(true?a:b){

// }

//应该返回的是T退化后的
//decay_t可以确保不能返回引用类型
template<typename T1,typename T2>
auto max(T1 a,T2 b)->typename std::decay<decltype(true?a:b)>::type{
    std::cout<<"a type:"<<typeid(T1).name<<" b type:"<<typeid(T2).name<<std::endl;
    return b<a?a:b
}

int main(){
    int i=42;
    int const &ir=i;
    auto a=ir;          //退化后的类型,a类型为int型的新对象
}

