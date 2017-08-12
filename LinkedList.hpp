//
//  LinkedList.hpp
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

class LinkedList
{
private:
    int size;
    Node * head;
    Node * tail;
public:
    // Constructors
    LinkedList();
    
    // Destructor
    ~LinkedList();
    
    // Gets
    int getSize();
    
    // Sets
    
    // Helpers
    int getData(int idx);
    void setData(int idx, int d);
    void insertTail(int d);
    void insertHead(int d);
    void insert(int idx, int d);
    void removeHead();
    void removeTail();
    void remove(int idx);
    void display();
    Node * search(int d);
    bool isEmpty();
};
