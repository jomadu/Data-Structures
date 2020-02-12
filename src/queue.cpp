#include "queue.hpp"
#include <stdexcept>
#include <sstream>

// Constructors
Queue::Queue(){
    
}

// Desctructors
Queue::~Queue(){
    
}

// Gets

// Sets

// Helpers
void Queue::push(int d){
    ll_.insert(0,d);
}
int Queue::pop(){
    int d = ll_.data(ll_.size());
    ll_.removeHead();
    return d;
}
int Queue::peek(){
    return ll_.data(0);
}
bool Queue::isEmpty(){
    return ll_.isEmpty();
}
int Queue::size(){
    return ll_.size();
}
