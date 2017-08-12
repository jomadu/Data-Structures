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
    ll.insertHead(d);
}
int Queue::pop(){
    int data = ll.getData(ll.getSize());
    ll.removeHead();
    return data;
}
int Queue::peek(){
    return ll.getData(0);
}
bool Queue::isEmpty(){
    return ll.isEmpty();
}
int Queue::getSize(){
    return ll.getSize();
}
