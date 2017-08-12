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
    ll.insertHead(d);
}
int Stack::pop(){
    int data = ll.getData(0);
    ll.removeHead();
    return data;
}
int Stack::peek(){
    return ll.getData(0);
}
bool Stack::isEmpty(){
    return ll.isEmpty();
}
int Stack::getSize(){
    return ll.getSize();
}


