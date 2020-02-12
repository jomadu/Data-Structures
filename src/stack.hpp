#ifndef STACK_HPP
#define STACK_HPP

#include <stdio.h>
#include "linked_list.hpp"

class Stack{
private:
    LinkedList ll_;
public:
    // Constructors
    Stack();
    
    // Destructor
    ~Stack();
    
    // Helpers
    void push(int d);
    int pop();
    int peek();
    bool isEmpty();
    int size();
};

#endif // STACK_HPP
