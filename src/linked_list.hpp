#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <stdio.h>
#include <memory>
#include <vector>
#include "node.hpp"

class LinkedList
{
public:
    LinkedList();
    ~LinkedList();
    
    int size();
    virtual int data(int idx);
    virtual void data(int idx, int data);
    virtual void append(int data);
    virtual void prepend(int data);
    virtual void insert(int idx, int data);
    virtual void removeHead();
    virtual void removeTail();
    virtual void remove(int idx);
    void clear();
    void display();
    std::vector<std::shared_ptr<Node>> search(int data);
    bool isEmpty();

protected:
    int size_;
    std::shared_ptr<Node> head_;
    std::shared_ptr<Node> tail_;
};

#endif // LINKED_LIST_HPP
