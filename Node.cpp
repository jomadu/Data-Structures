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
    next = NULL;
}
Node::Node(int d){
    next = NULL;
    data = d;
}

// Destructor
Node::~Node(){

}

// Gets
int Node::getData(){
    return data;
}

Node * Node::getNext(){
    return next;
}

Node * Node::getPrev(){
    return prev;
}

// Sets
void Node::setData(int d){
    data = d;
}

void Node::setNext(Node * n){
    next = n;
}

void Node::setPrev(Node * n){
    prev = n;
}

// Helpers



