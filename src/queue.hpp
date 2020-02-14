/**
 * @file queue.hpp
 * @author Max Dunn (maxdunn123@gmail.com)
 * @copyright Copyright Max Dunn (c) 2020. All rights reserved.
 * 
 * @brief Queue declaration
 * - ll_ : LinkedList
 */
#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <stdio.h>
#include "linked_list.hpp"

class Queue
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

#endif // QUEUE_HPP
