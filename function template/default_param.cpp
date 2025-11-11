#include <iostream>


//没有默认实参(模板参数)版本
// template<typename T>
// void f(T=""){

// }

template <typename T=std::string>
void f(T=""){

}

int main(){
    f(1);
    f();        //没有使用默认参数会报错
}