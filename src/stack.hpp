/**
 * @file stack.hpp
 * @author Max Dunn (maxdunn123@gmail.com)
 * @copyright Copyright Max Dunn (c) 2020. All rights reserved.
 * 
 * @brief Stack declaration
 * - ll_ : LinkedList
 */

#ifndef STACK_HPP
#define STACK_HPP

#include <stdio.h>
#include "linked_list.hpp"

class Stack
{
public:
    void push(const int data);
    int pop();
    void clear();
    int peek() const;
    bool isEmpty() const;
    int size() const;

private:
    LinkedList ll_;
};

#endif // STACK_HPP
