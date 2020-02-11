//
//  Node.cpp
//  DataStructures
//
//  Created by Max Dunn on 8/4/17.
//  Copyright © 2017 Max Dunn. All rights reserved.
//

#include "Node.hpp"
// Constructors
Node::Node(){
    next_ = NULL;
    prev_ = NULL;
}
Node::Node(int data){
    next_ = NULL;
    prev_ = NULL;
    data_ = data;
}

// Destructor
Node::~Node(){

}

// Gets
int Node::getData(){
    return data_;
}

Node * Node::getNext(){
    return next_;
}

Node * Node::getPrev(){
    return prev_;
}

// Sets
void Node::setData(int data){
    data_ = data;
}

void Node::setNext(Node * next){
    next_ = next;
}

void Node::setPrev(Node * prev){
    prev_ = prev;
}

// Helpers



