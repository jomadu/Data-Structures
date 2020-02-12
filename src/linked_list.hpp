#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <stdio.h>
#include <memory>
#include "node.hpp"

class LinkedList
{
private:
    int size_;
    std::shared_ptr<Node> head_;
    std::shared_ptr<Node> tail_;
public:
    // Constructors
    LinkedList();
    
    // Destructor
    ~LinkedList();
    
    // Gets
    int size();
    
    // Sets
    
    // Helpers
    int data(int idx);
    void data(int idx, int data);
    void append(int data);
    void prepend(int data);
    void insert(int idx, int data);
    void removeHead();
    void removeTail();
    void remove(int idx);
    void display();
    std::shared_ptr<Node> search(int data);
    bool isEmpty();
};

#endif // LINKED_LIST_HPP
