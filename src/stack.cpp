#include "stack.hpp"

void Stack::push(int d){
    ll_.insert(0, d);
}
int Stack::pop(){
    auto d = ll_.data(0);
    ll_.removeHead();
    return d;
}
void Stack::clear(){
    while (!isEmpty())
    {
        pop();
    }
}
int Stack::peek(){
    return ll_.data(0);
}
bool Stack::isEmpty(){
    return ll_.isEmpty();
}
int Stack::size(){
    return ll_.size();
}


