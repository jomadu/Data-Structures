#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <stdio.h>
#include <memory>
#include <vector>
#include "linked_list_node.hpp"

class LinkedList
{
public:
    LinkedList();
    ~LinkedList();
    
    int size();
    std::shared_ptr<LinkedListNode> head();
    std::shared_ptr<LinkedListNode> tail();
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
    std::vector<std::shared_ptr<LinkedListNode>> search(int data);
    bool isEmpty();

protected:
    int size_;
    std::shared_ptr<LinkedListNode> head_;
    std::shared_ptr<LinkedListNode> tail_;
};

#endif // LINKED_LIST_HPP
