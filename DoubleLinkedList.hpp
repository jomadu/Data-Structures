/****************************

DoubleLinkedList.hpp
-----------------------------
Author: Max Dunn 
Copyright © 2017 Max Dunn.
All rights reserved.

****************************/

#include <stdio.h>
#include "Node.hpp"
#include <stdexcept>
#include <sstream>


class DoubleLinkedList
{
private:
    int size;
    Node * head;
    Node * tail;
public:
    DoubleLinkedList();
    ~DoubleLinkedList();
    void append(int d);
    void prepend(int d);
    void insert(int idx, int d);
    void removeHead();
    void removeTail();
    void remove(int idx);
    void display();
    Node * search(int d); 
};
