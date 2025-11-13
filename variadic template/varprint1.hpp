#include <iostream>

//为了结束递归，在参数包为空时调用print的非模板函数重载版本
void print(){

}

template<typename T,typename... Types>
void print(T firstArg,Types... args){
    std::cout<<firstArg<<std::endl;
    print(args...);
}

//sizeof...
template<typename T,typename... Types>
void print(T firstArg,Types... args){
    std::cout<<sizeof... (Types) <<std::endl;   //输出剩余类型的数量
    std::cout<<sizeof... (args) <<std::endl;    //输出剩余实参的数量
}

//有了这个是不是可以不需要空的print?(类似下面写法)
namespace Method1{
    template<typename T,typename... Types>
    void print(T firstArg,Types... args){
        std::cout<<firstArg<<std::endl;
        if(sizeof... (args)>0){ //改成 if constexpr
            print(args...);
        }
    }
    //不可以!
    /*
        普通 if 不能阻止编译器检查分支里的代码；最后一次递归会需要一个不存在的 print()，
        因此报错。要么写一个无参基例，要么用 if constexpr，要么用折叠表达式
    */
    
};