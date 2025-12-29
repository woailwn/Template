#include <utility>
#include <string>
#include <iostream>
#include <type_traits>
#include <concepts>

template<typename T>
using EnableIfString = std::enable_if_t<std::is_convertible_v<T, std::string>>;

//¸ÅÄî
template<typename T>
concept ConvertibleToString = std::is_convertible_v<T, std::string>;

class Person{
    private:
        std::string name;

    public:
        // template<typename STR,typename = EnableIfString<STR>>
        // explicit Person(STR&& str):name(std::forward<STR>(str)){
        //     std::cout<<"template constructor called"<<std::endl;
        // }

        template<typename STR>
        requires ConvertibleToString<STR>
        Person(STR&& str):name(std::forward<STR>(str)){
            std::cout<<"template constructor called"<<std::endl;
        }
        
        Person(Person const& p) :name(p.name){
            std::cout<<"copy constructor called"<<std::endl;
        }

        Person(Person&& p):name(std::move(p.name)){
            std::cout<<"move constructor called"<<std::endl;
        }
};

