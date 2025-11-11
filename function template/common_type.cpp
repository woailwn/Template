#include <type_traits>
#include <iostream>

template<typename T1,typename T2>
std::common_type_t<T1,T2> max(T1 a,T2 b){
    return b<a?a:b;
}

//common_type_t:它会推导出 T1 和 T2 两个类型的公共类型，即两个类型都可以隐式转换到的类型

int main(){
    auto ans=max(short(5),long(10));
    std::cout<<typeid(ans).name()<<std::endl;

    //编译时检测
    static_assert(std::is_same_v<decltype(max(5,3.14)),double>,"应该是 double");
}