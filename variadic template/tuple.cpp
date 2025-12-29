#include <iostream>
#include <utility>
/*
    需求:tuple
    1.只能存在同一类型(原始array)
    2.实现Array<int,double,string>
*/

template<typename... Types>
class Array;

template<>
class Array<>{
public:
    static constexpr size_t size() {return 0;}
};

//通用Array模板
template<typename T, typename... Rest>
class Array<T,Rest...>{
private:
    T value;    //第一个元素
    Array<Rest...> rest;    //递归处理剩余元素

public:
    //默认构造
    Array(): value(),rest() {}

    //参数构造函数
    // explicit Array(T const& v,Rest const&... r)
    // :value(v), rest(r...){}

    //移动构造
    // explicit Array(T&& v,Rest&&... r)
    // :value(std::move(v)),rest(std::move(r)...){}

    //完美转发
    template<typename U,typename... Args>
    explicit Array(U&& v,Args&&... r)
    :value(std::forward<U>(v)),rest(std::forward<Args>(r)...){}

    //获取元素 (编译期索引)  可以修改元素
    template<size_t I>
    auto& get(){
        if constexpr (I==0){
            return value;
        }else{
            return rest.template get<I-1>();    // ***
        }
    }

    //const版获取   只读版本
    template<size_t I>
    const auto& get() const{
        if constexpr (I==0){
            return value;
        }else{
            return rest.template get<I-1>();    
            /*
                为什么需要template?
                    rest.get<I-1>()编译器看到后会想< 是什么 小于号还是模板参数
                    此时编译器还不知道rest(模板参数)是一个具体什么类型,是不是有get函数
                    我们需要显式告诉编译器get是一个模板成员函数
            */
        }
    }

    //打印函数
    void print() const{
        std::cout<<value;
        if constexpr (sizeof...(Rest) > 0){
            std::cout<<", ";
            rest.print();
        }
    }

    //forEach
    template <typename Func>
    void forEach(Func f){
        f(value);
        if constexpr (sizeof...(Rest) > 0){
            rest.forEach(f);
        }
    }

    //const版forEach
    template <typename Func>
    void forEach(Func f) const{
        f(value);
        if constexpr (sizeof...(Rest) > 0){
            rest.forEach(f);
        }
    }

    //获取大小
    static constexpr size_t size(){
        return 1 + sizeof...(Rest);
    }
};

//make_array
template <typename... Types>
auto make_array(Types&&... args){
    return Array<Types...>(std::forward<Types>(args)...);
}

int main(){
    // Array<int,double,std::string> arr(42,3.14,"hello");
    auto arr= make_array(42,3.14,"hello");
    std::cout<<"Array 大小: "<<arr.size()<<std::endl;

    std::cout<<"arr.get<0>() = "<<arr.get<0>()<<std::endl;
    std::cout<<"arr.get<1>() = "<<arr.get<1>()<<std::endl;
    std::cout<<"arr.get<2>() = "<<arr.get<2>()<<std::endl;

    std::cout<<"arr: ";
    arr.print();
    std::cout<<std::endl;

    std::cout<<"forEach 应用函数: "<<std::endl;
    arr.forEach([](const auto& x){
        std::cout<<"元素: "<<x<<std::endl;        
    });
    

    return 0;
}


/*
总结...的三种用法:

1.声明这是一个参数包
template<typename... Rest>
Rest是包含任意数量的类型


2.把参数包展开成逗号分割的列表
Array<Rest...>(r...)
       ⬆       ⬆
    展开类型    展开参数

std::forward<Args>(r)...
   ⬆                  ⬆
对每个r应用forward()  展开


3.获取参数包大小
sizeof...(Rest)
            ⬆
        参数包有多少个元素


*/