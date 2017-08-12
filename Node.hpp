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
    int data;
    Node * next;
    Node * prev;
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
    void setData(int d);
    void setNext(Node * n);
    void setPrev(Node * n);
    
    // Helpers
};

#endif
