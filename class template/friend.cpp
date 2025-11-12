#include <iostream>

template<typename T>
class Stack;
template<typename T>
std::ostream& operator<<(std::ostream&,Stack<T> const&);

template<typename T>
class Stack{
    void printOn(std::ostream& strm) const{

    }
    friend std::ostream& operator<<(std::ostream& os,Stack<T> const& s){
        s.printOn(os);
        return os;
    }
};

