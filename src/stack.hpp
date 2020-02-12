#ifndef STACK_HPP
#define STACK_HPP

#include <stdio.h>
#include "linked_list.hpp"

class Stack
{
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

#endif // STACK_HPP
