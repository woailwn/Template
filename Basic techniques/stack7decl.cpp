#include <iostream>
#include <deque>
#include <vector>
template <typename T, typename Cont = std::deque<T>>
class Stack
{
private:
    Cont elems;

public:
    void push(T const &elem)
    {
        elems.push_back(elem);
    }

    void pop()
    {
        if (!elems.empty())
        {
            elems.pop_back();
        }
    }

    T const &top() const
    {
        return elems.back();
    }

    bool empty() const
    {
        return elems.empty();
    }

    // 赋值T2类型元素的栈
    template <typename T2, typename Cont2>
    Stack &operator=(Stack<T2, Cont2> const &);
    // 访问任何元素类型为T2的栈Stack<T2>的私有成员
    template <typename, typename>
    friend class Stack;
};

template <typename T, typename Cont>
template <typename T2, typename Cont2>
Stack<T, Cont> &Stack<T, Cont>::operator=(Stack<T2, Cont2> const &op2)
{
    elems.clear();
    elems.insert(elems.begin(),
                 op2.elems.begin(),
                 op2.elems.end());
    return *this;
}

int main()
{
    std::cout<<"测试相同类型赋值"<<std::endl;
    Stack<int> s1;
    s1.push(1);
    s1.push(2);

    Stack<int> s2;
    s2.push(10);
    s2.push(20);

    s1=s2;
    std::cout<<"s1 top: "<<s1.top()<<std::endl;

    std::cout << "不同类型赋值(double ->int)" << std::endl;
    Stack<double> s3;
    s3.push(1.1);
    s3.push(2.2);
    s3.push(3.3);
    
    Stack<int> s4;
    s4 = s3;  // double 转换为 int
    std::cout << "s4 top: " << s4.top() << std::endl;  // 3
    s4.pop();
    std::cout << "s4 top after pop: " << s4.top() << std::endl;  // 2

    std::cout<<"不同容器类型"<<std::endl;
    Stack<int, std::vector<int>> s5;
    s5.push(7);
    s5.push(8);

    Stack<int, std::deque<int>> s6;
    s6 = s5;  // vector -> deque
    std::cout << "s6 top: " << s6.top() << std::endl;  // 8
}