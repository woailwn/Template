#include <array>
#include <string>
//编译期计算
template <typename T1,typename T2>
constexpr auto max(T1 a,T2 b){
    return b<a?a:b;
}
//或者C++20的consteval 

std::array<std::string,::max(sizeof(char),1000u)> arr;