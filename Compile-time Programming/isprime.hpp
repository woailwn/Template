template<unsigned p,unsigned d>
struct DoIsPrime{
    static constexpr bool value = (p%d != 0) && DoIsPrime<p,d-1>::value;
};

template<unsigned p>
struct DoIsPrime<p,2>{
    static constexpr bool value = (p%2 != 0);
};

//constexpr
constexpr bool doIsPrime(unsigned p,unsigned d){
    return d!=2 ? (p%d !=0) && doIsPrime(p,d-1)
                : (p%2 !=0);
}

constexpr bool isPrime (unsigned p){
    return p<4 ? !(p<2) : doIsPrime(p,p/2);
}

template<unsigned p>
struct IsPrime{
    static constexpr bool value = DoIsPrime<p,p/2>::value;
};

template<>
struct IsPrime<0> {static constexpr bool value = false;};
template<>
struct IsPrime<1> {static constexpr bool value = false;};
template<>
struct IsPrime<2> {static constexpr bool value = true;};
template<>
struct IsPrime<3> {static constexpr bool value = true;};


//»ÁIsPrime<9>::value

