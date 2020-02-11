//
//  Stack.cpp
//  DataStructures
//
//  Created by Max Dunn on 7/26/17.
//  Copyright © 2017 Max Dunn. All rights reserved.
//

#include "Stack.hpp"

// Constructors
Stack::Stack(){

}

// Destructor
Stack::~Stack(){

}

// Gets

// Sets

// Helpers
void Stack::push(int d){
    ll_.insert(0, d);
}
int Stack::pop(){
    int d = ll_.getData(0);
    ll_.removeHead();
    return d;
}
int Stack::peek(){
    return ll_.getData(0);
}
bool Stack::isEmpty(){
    return ll_.isEmpty();
}
int Stack::getSize(){
    return ll_.getSize();
}


