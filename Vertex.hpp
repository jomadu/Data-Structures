//
//  Vertex.hpp
//  DataStructures
//
//  Created by Max Dunn on 7/28/17.
//  Copyright © 2017 Max Dunn. All rights reserved.
//

#ifndef Vertex_hpp
#define Vertex_hpp

#include <stdio.h>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Vertex{
private:
    int id;
    int data;
    unordered_map<int, Vertex *> nbrs;
public:
    // Constructors
    Vertex();
    Vertex(int key);
    Vertex(int key, int d);
    
    // Destructor
    ~Vertex();
    
    // Gets
    int getId();
    int getData();
    unordered_map<int, Vertex *> getNbrs();

    // Sets
    void setData(int d);
    
    // Helpers
    void addNbr(int key);
    void removeNbr(int key);
    Vertex * findNbr(int key);
};

#endif /* Vertex_hpp */
