#include <iostream>
#include <vector>
#include <string>
#include "foreachinvoke.hpp"

class MyClass{
    public:
        void memfunc(int i) const{
            std::cout<<"MyClass::memfunc() called for: "<<i<<std::endl;
        }
};

int main(){
    std::vector<int> primes={2,3,5,7};
    foreach(primes.begin(),primes.end(),[](std::string const&,int i){
        std::cout<<"Lambda called for: "<<i<<std::endl;
    },"- value");

    MyClass obj;
    foreach(primes.begin(),primes.end(),&MyClass::memfunc,obj);
}
