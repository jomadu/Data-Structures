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
    _ll.insertHead(d);
}
int Stack::pop(){
    int d = _ll.getData(0);
    _ll.removeHead();
    return d;
}
int Stack::peek(){
    return _ll.getData(0);
}
bool Stack::isEmpty(){
    return _ll.isEmpty();
}
int Stack::getSize(){
    return _ll.getSize();
}


