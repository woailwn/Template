#include <array>
#include <cassert>

template<typename T = int,std::size_t Maxsize = 20>
class Stack{
    private:
        std::array<T,Maxsize> elems;
        std::size_t numElems;

    public:
        Stack();
        void push(T const& elem);
        void pop();
        T const& top() const;
        bool empty() const{
            return numElems==0;
        }
        std::size_t size() const{
            return numElems;
        }
};

template<typename T,std::size_t Maxsize>
Stack<T,Maxsize>::Stack():numElems(0){

}
//...

