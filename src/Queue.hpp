//
//  Queue.hpp
//  DataStructures
//
//  Created by Max Dunn on 7/26/17.
//  Copyright © 2017 Max Dunn. All rights reserved.
//

#ifndef Queue_hpp
#define Queue_hpp

#include <stdio.h>
#include "LinkedList.hpp"
#include <stdexcept>
#include <sstream>

class Queue{
private:
    LinkedList ll_;
public:
    // Constructors
    Queue();
    
    // Destructor
    ~Queue();
    
    // Gets
    
    // Sets
    
    // Helpers
    void push(int d);
    int pop();
    int peek();
    bool isEmpty();
    int getSize();
};


#endif /* Queue_hpp */
