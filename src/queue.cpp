#include "queue.hpp"
#include <stdexcept>
#include <sstream>

void Queue::push(int d){
    ll_.append(d);
}
int Queue::pop(){
    int d = ll_.data(0);
    ll_.removeHead();
    return d;
}
void Queue::clear()
{
    while(!isEmpty())
    {
        pop();
    }
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
