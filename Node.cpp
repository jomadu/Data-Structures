/****************************
 
 Node.cpp
 -----------------------------
 Author: Max Dunn
 Copyright © 2017 Max Dunn.
 All rights reserved.
 
 ****************************/

#include "Node.hpp"

Node::Node(){
    next = NULL;
}

Node::~Node(){

}

int Node::getData(){
    return data;
}

Node * Node::getNext(){
    return next;
}

Node * Node::getPrev(){
    return prev;
}

void Node::setData(int d){
    data = d;
}

void Node::setNext(Node * np){
    next = np;
}

void Node::setPrev(Node * np){
    prev = np;
}



