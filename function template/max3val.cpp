#include <cstring>
#include <string>

//为指针和C-strings重载求最大值

//任意
template<typename T>
T max(T a,T b){
    return b<a?a:b;
}

//求两个指针所指数值的最大值
template<typename T>
T* max(T* a,T* b){
    return *b<*a?a:b;
}

//C-strings
char const* max(char const* a,char const* b){
    return std::strcmp(b,a)<0 ?a:b; //会产生悬空引用
}

