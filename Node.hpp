/****************************
 
 Node.hpp
 -----------------------------
 Author: Max Dunn
 Copyright © 2017 Max Dunn.
 All rights reserved.
 
 ****************************/

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
    Node();
    ~Node(); 
    int getData();
    Node * getNext();
    Node * getPrev();
    void setData(int d);
    void setNext(Node * np);
    void setPrev(Node * np);
};

#endif
