#include "stack.hpp"

// Constructors
Stack::Stack(){

}

// Destructor
Stack::~Stack(){

}

// Gets

// Sets

// Helpers
void Stack::push(int d){
    ll_.insert(0, d);
}
int Stack::pop(){
    auto d = ll_.data(0);
    ll_.removeHead();
    return d;
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


