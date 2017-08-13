//
//  Graph.hpp
//  DataStructures
//
//  Created by Max Dunn on 7/28/17.
//  Copyright © 2017 Max Dunn. All rights reserved.
//

#ifndef Graph_hpp
#define Graph_hpp

#include <stdio.h>
#include "Vertex.hpp"
#include <stdexcept>
#include <sstream>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Graph{
private:
    unordered_map<int, Vertex *> _vertices;
public:
    // Constructors
    Graph();
    
    // Destructor
    ~Graph();
    
    // Gets
    
    // Sets
    
    // Helpers
    void addVertex(int k, int v);
    void removeVertex(int k);
    void addEdge(int o, int d);
    void removeEdge(int o, int d);
    Vertex * findVertex(int k);
    bool hasEdge(int o, int d);
};


#endif /* Graph_hpp */
