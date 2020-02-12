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
    int data(int idx);
    void data(int idx, int data);
    void append(int data);
    void prepend(int data);
    void insert(int idx, int data);
    void removeHead();
    void removeTail();
    void remove(int idx);
    void clear();
    void display();
    std::vector<std::shared_ptr<Node>> search(int data);
    bool isEmpty();

private:
    int size_;
    std::shared_ptr<Node> head_;
    std::shared_ptr<Node> tail_;
};

#endif // LINKED_LIST_HPP
