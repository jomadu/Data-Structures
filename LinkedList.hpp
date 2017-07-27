/****************************

LinkedList.hpp
-----------------------------
Author: Max Dunn 
Copyright © 2017 Max Dunn.
All rights reserved.

****************************/

#include <stdio.h>
#include "Node.hpp"
#include <stdexcept>
#include <sstream>


class LinkedList
{
private:
    int size;
    Node * head;
    Node * tail;
public:
    LinkedList();
    ~LinkedList();
    void append(int d);
    void prepend(int d);
    void insert(int idx, int d);
    void removeHead();
    void removeTail();
    void remove(int idx);
    void display();
    Node * search(int d); 
};
