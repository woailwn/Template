#include <unordered_set>
#include <string>
class Customer{
    private:
        std::string name;
    public:
        Customer(std::string const& n):name(n){}
        std::string getName() const {return name;}
};

struct CustomerEq{
    bool operator() (Customer const& c1, Customer const& c2){
        return c1.getName() == c2.getName();
    }
};

struct CustomerHash{
    std::size_t operator() (Customer const& c) const{
        return std::hash<std::string>()(c.getName());
    }
};

//组合operator
template <typename... Bases>
struct Overloader : Bases...{
    using Bases::operator() ...;
};

int main(){
    //在一个类组合Customer的比较和哈希运算
    using CustomerOP = Overloader<CustomerHash,CustomerEq>;

    std::unordered_set<Customer,CustomerHash,CustomerEq> col1;
    std::unordered_set<Customer,CustomerOP,CustomerOP> col2;
}