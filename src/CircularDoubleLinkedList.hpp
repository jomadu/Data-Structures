//
//  CircularDoubleLinkedList.hpp
//  DataStructures
//
//  Created by Max Dunn on 7/26/17.
//  Copyright © 2017 Max Dunn. All rights reserved.
//


#include <stdio.h>
#include "Node.hpp"
#include <stdexcept>
#include <sstream>
#include <iostream>

using namespace std;

class CircularDoubleLinkedList
{
private:
    int size_;
    Node * head_;
    Node * tail_;
public:
    // Constructors
    CircularDoubleLinkedList();
    
    // Destructor
    ~CircularDoubleLinkedList();
    
    // Gets
    int getSize();
    
    // Sets
    
    // Helpers
    int getData(int idx);
    void setData(int idx, int data);
    void append(int data);
    void prepend(int data);
    void insert(int idx, int data);
    void removeHead();
    void removeTail();
    void remove(int idx);
    void display();
    Node * search(int data);
    bool isEmpty();
};
