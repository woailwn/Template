//可以调用任何可调用对象,完美转发所有参数
#include <utility>
#include <functional>
#include <type_traits>

template<typename Callable,typename... Args>
decltype(auto) call(Callable&& op,Args&&... args){
    return std::invoke(std::forward<Callable>(op),std::forward<Args>(args)...);
}

/*
为什么用decltype(auto) 而不是 auto?
auto 会丢失原有属性如,int&->int 变成拷贝
decltype(auto) 保留原有属性

但是返回值类型是void，不可以用decltype(auto)，所以我们加个编译期判断
*/

template<typename Callable,typename... Args>
decltype(auto) call(Callable&& op,Args&&... args){
    if constexpr(std::is_same_v<std::invoke_result_t<Callable,Args...>,void>){
        std::invoke(std::forward<Callable>(op),std::forward<Args>(args)...);
        return;
    }else{
        decltype(auto) ret{std::invoke(std::forward<Callable>(op),std::forward<Args>(args)...)};
        return ret;
    }
}

//这段代码就是你给他一个函数（可调用对象）和参数，它原封不动地帮你调用，返回值也原封不动的还给你
