#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <stdio.h>
#include "linked_list.hpp"

class Queue{
public:
    void push(int d);
    int pop();
    void clear();
    int peek();
    bool isEmpty();
    int size();
private:
    LinkedList ll_;
};


#endif // QUEUE_HPP
