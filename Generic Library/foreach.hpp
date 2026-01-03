template<typename Iter,typename Callable>
void foreach(Iter begin,Iter end,Callable op){
    while(begin!=end){
        op(*begin); //op(*begin) -> op.operator()(*begin) 当传入的是仿函数时
        ++begin;
    }
}