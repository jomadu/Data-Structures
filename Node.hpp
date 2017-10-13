//
//  Node.hpp
//  DataStructures
//
//  Created by Max Dunn on 8/4/17.
//  Copyright © 2017 Max Dunn. All rights reserved.
//

#ifndef Node_hpp
#define Node_hpp

#include <stdio.h>

class Node
{
private:
    int _data;
    Node * _next;
    Node * _prev;
public:
    // Constructors
    Node();
    Node(int d);
    
    // Destructor
    ~Node();
    
    // Gets
    int getData();
    Node * getNext();
    Node * getPrev();

    // Sets
    void setData(int data);
    void setNext(Node * next);
    void setPrev(Node * prev);
    
    // Helpers
};

#endif
