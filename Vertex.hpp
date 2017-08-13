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
    int _key;
    int _val;
    unordered_map<int, Vertex *> nbrs;
public:
    // Constructors
    Vertex();
    Vertex(int key);
    Vertex(int key, int val);
    
    // Destructor
    ~Vertex();
    
    // Gets
    int getKey();
    int getVal();
    unordered_map<int, Vertex *> getNbrs();

    // Sets
    void setVal(int val);
    
    // Helpers
    void addNbr(int key, Vertex * vtx);
    void removeNbr(int key);
    Vertex * findNbr(int key);
};

#endif /* Vertex_hpp */
