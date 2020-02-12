#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <stdio.h>
#include "linked_list.hpp"

class Queue{
private:
    LinkedList ll_;
public:
    // Constructors
    Queue();
    
    // Destructor
    ~Queue();
    
    // Gets
    
    // Sets
    
    // Helpers
    void push(int d);
    int pop();
    int peek();
    bool isEmpty();
    int size();
};


#endif // QUEUE_HPP
