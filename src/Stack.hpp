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
#include <sstream>

class Stack{
private:
    LinkedList ll_;
public:
    // Constructors
    Stack();
    
    // Destructor
    ~Stack();
    
    // Helpers
    void push(int d);
    int pop();
    int peek();
    bool isEmpty();
    int getSize();
};

#endif /* Stack_hpp */
