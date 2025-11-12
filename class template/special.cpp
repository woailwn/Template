//类模板特化

#include <deque>
#include <string>
#include <cassert>
#include <vector>

//主模版
template<typename T>
class Stack {
private:
    std::deque<T> elems;

public:
    void push(const T& elem) {
        elems.push_back(elem);
    }

    void pop() {
        assert(!elems.empty());
        elems.pop_back();
    }

    T& top() {
        assert(!elems.empty());
        return elems.back();
    }

    bool empty() const {
        return elems.empty();
    }
};

//特化可能会提供不同的接口
//特化一定要先声明主模板

//类模板的特化
template<>
class Stack<std::string>{
    private:
        std::deque<std::string> elems;
    public:
        void push(std::string const&);
        void pop();
        std::string const& top() const;
        bool empty() const{
            return elems.empty();
        }
};

void Stack<std::string>::push(std::string const& elem){
    elems.push_back(elem);
}

void Stack<std::string>::pop(){
    assert(!elems.empty());
    elems.pop_back();
}

std::string const& Stack<std::string>::top() const{
    assert(!elems.empty());
    return elems.back();
}


//偏特化，定义一个类模板仍用T，但是用其他类型来特化
template<typename T>
class Stack<T*>{
    private:
        std::vector<T*> elems;
    public:
        void push(T*);
        T* pop();
        T* top() const;
        bool empty() const{
            return elems.empty();
        }
};

template<typename T>
void Stack<T*>::push(T* elem){
    elems.push_back(elem);
}

template<typename T>
T* Stack<T*>::pop(){
    assert(!elems.empty());
    T* p=elems.back();
    elems.pop_back();
    return T;
}

template<typename T>
T* Stack<T*>::top() const{
    assert(!elems.empty());
    return elems.back();
}

//如下偏特化可行
template<typename T1,typename T2>
class MyClass{

};

//偏特化
//1.两个模板参数都有相同类型
template<typename T>
class MyClass<T,T>{

};

//2.第二个参数为指定类型
template<typename T>
class MyClass<T,int>{

};

//3.两个都是其他类型
template<typename T1,typename T2>
class MyClass<T1*,T2*>{

};


//会造成歧义
//MyClass<int,int>  (1，2)
//MyClass<int*,int*> (1,3)

//消除歧义
template <typename T>
class MyClass<T*,T*>{

};