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
    int key_;
    int val_;
    unordered_map<int, Vertex *> nbrs;
public:
    // Constructors
    Vertex();
    Vertex(int k);
    Vertex(int k, int v);
    
    // Destructor
    ~Vertex();
    
    // Gets
    int getKey();
    int getVal();
    unordered_map<int, Vertex *> getNbrs();

    // Sets
    void setVal(int v);
    
    // Helpers
    void addNbr(int k, Vertex * vtx);
    void removeNbr(int k);
    Vertex * findNbr(int k);
};

#endif /* Vertex_hpp */
