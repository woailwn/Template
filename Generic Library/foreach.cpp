#include <iostream>
#include <vector>
#include "foreach.hpp"

void func(int i){
    std::cout<<"func() called for: "<<i<<std::endl;
}

class FuncObj{
    public:
        void operator() (int i) const{
            std::cout<<"FuncObj::op() called for: "<<i<<std::endl;
        }
};

int main(){
    std::vector<int> primes = {2,3,4,5};
    foreach(primes.begin(),primes.end(),func);
    foreach(primes.begin(),primes.end(),FuncObj());
    foreach(primes.begin(),primes.end(),[](int i){
        std::cout<<"Lambda called for: "<<i<<std::endl;
    });
    foreach(primes.begin(),primes.end(),&func);
}