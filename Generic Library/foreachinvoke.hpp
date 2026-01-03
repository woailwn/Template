#include <utility>
#include <functional>

template<typename Iter,typename Callable,typename... Args>
void foreach(Iter begin,Iter end,Callable op,Args const&... args){
    while(begin!=end){
        std::invoke(op,args...,*begin);
        ++begin;
    }
}
