#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <stdio.h>
#include <memory>
#include "vertex.hpp"

class Graph{
private:
    std::unordered_map<int, std::shared_ptr<Vertex>> verticies_;
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
    std::shared_ptr<Vertex> findVertex(int k);
    bool hasEdge(int o, int d);
};


#endif // GRAPH_HPP
