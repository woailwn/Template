// 推导指引
#include <iostream>
#include <string>

namespace Base
{
    template <typename T>
    class Container
    {
    private:
        T data;

    public:
        Container(T d) : data(d)
        {
            std::cout << typeid(T).name() << std::endl;
        }
        T get() const { return data; }
    };

    // 将 const char* 推导为 std::string
    Container(const char *) -> Container<std::string>;
};

namespace STLexample
{
    // C++17之前
    std::pair<int, double> p1(1, 2.5);

    // C++17之后
    std::pair p2(1, 2.5);     // 推导为 pair<int, double>
    std::pair p3(1, "hello"); // 推导为 pair<int, const char*>

    // std::pair 的推导指引（标准库定义）：
    // template<typename T1, typename T2>
    // pair(T1, T2) -> pair<T1, T2>;

    // std::cout << p2.first << ", " << p2.second << std::endl;
};

// 聚合类型推导指引
namespace Union
{

    template <typename T>
    struct Point
    {
        T x;
        T y;
    };

    // 聚合类型的推导指引
    template <typename T>
    Point(T, T) -> Point<T>;

    // Point(char const*,char const*)->Point<std::string>
};

int main()
{
    Base::Container c1(42);      // 推导为 Container<int>
    Base::Container c2("hello"); // 使用推导指引，推导为 Container<std::string>

    std::cout << c1.get() << std::endl;
    std::cout << c2.get() << std::endl; // 可以正常输出字符串

    Union::Point p1{1, 2};     // 推导为 Point<int> 
    Union::Point p2{1.5, 2.5}; // 推导为 Point<double>
    Union::Point p3{"hello","www"};

    std::cout << "p1: (" << p1.x << ", " << p1.y << ")" << std::endl;
    std::cout << "p2: (" << p2.x << ", " << p2.y << ")" << std::endl;

    return 0;
}