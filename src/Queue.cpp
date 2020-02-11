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
    ll_.insert(0,d);
}
int Queue::pop(){
    int d = ll_.getData(ll_.getSize());
    ll_.removeHead();
    return d;
}
int Queue::peek(){
    return ll_.getData(0);
}
bool Queue::isEmpty(){
    return ll_.isEmpty();
}
int Queue::getSize(){
    return ll_.getSize();
}
