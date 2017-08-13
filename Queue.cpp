//
//  Queue.cpp
//  DataStructures
//
//  Created by Max Dunn on 7/26/17.
//  Copyright © 2017 Max Dunn. All rights reserved.
//

#include "Queue.hpp"

// Constructors
Queue::Queue(){
    
}

// Desctructors
Queue::~Queue(){
    
}

// Gets

// Sets

// Helpers
void Queue::push(int d){
    _ll.insertHead(d);
}
int Queue::pop(){
    int d = _ll.getData(_ll.getSize());
    _ll.removeHead();
    return d;
}
int Queue::peek(){
    return _ll.getData(0);
}
bool Queue::isEmpty(){
    return _ll.isEmpty();
}
int Queue::getSize(){
    return _ll.getSize();
}
