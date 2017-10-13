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
    _next = NULL;
    _prev = NULL;
}
Node::Node(int data){
    _next = NULL;
    _prev = NULL;
    _data = data;
}

// Destructor
Node::~Node(){

}

// Gets
int Node::getData(){
    return _data;
}

Node * Node::getNext(){
    return _next;
}

Node * Node::getPrev(){
    return _prev;
}

// Sets
void Node::setData(int data){
    _data = data;
}

void Node::setNext(Node * next){
    _next = next;
}

void Node::setPrev(Node * prev){
    _prev = prev;
}

// Helpers



