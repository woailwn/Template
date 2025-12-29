#include <iostream>

template <typename T>
class Base{
public:
    void bar();
};

template <typename T>
class Derived:public Base<T>{
public: 
    void foo(){
        //错误
        //bar();

        //正确
        Base<T>::bar();
        //或
        // this->bar();
    }
};

//本质还是两阶段查找