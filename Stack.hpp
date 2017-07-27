//
//  Stack.hpp
//  DataStructures
//
//  Created by Max Dunn on 7/26/17.
//  Copyright © 2017 Max Dunn. All rights reserved.
//

#ifndef Stack_hpp
#define Stack_hpp

#include <stdio.h>
#include "LinkedList.hpp"
#include <stdexcept>

class Stack{
private:
    LinkedList stack;
public:
    Stack();
    ~Stack();
    void push(int d);
    int pop();
    int peek();
    bool isEmpty();
    bool isFull();
};

#endif /* Stack_hpp */
