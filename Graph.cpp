//
//  Graph.cpp
//  DataStructures
//
//  Created by Max Dunn on 7/28/17.
//  Copyright © 2017 Max Dunn. All rights reserved.
//

#include "Graph.hpp"

// Constructors
Graph::Graph(){

}

// Constructor
Graph::~Graph(){

}

// Gets

// Sets

// Helpers
void Graph::addVertex(int id, int data){
    Vertex * newVertex = new Vertex(id, data);
    vertices.emplace(make_pair(id, newVertex));
}
void Graph::removeVertex(int id){
    vertices.erase(id);
    for(unordered_map<int, Vertex *>::iterator it = vertices.begin(); it != vertices.end(); it++){
        it->second->removeNbr(<#Vertex *v#>)
    
    }
}
void Graph::addEdge(int o, int d){
    if (vertices.count(o) && vertices.count(d)){
        Vertex * origin = vertices.find(o)->second;
        Vertex * dest = vertices.find(d)->second;
        
        origin->addNbr(dest);
        dest->addNbr(origin);
    }
}
void Graph::removeEdge(int o, int d){
    
    if (vertices.count(o) && vertices.count(d)){
        Vertex * origin = vertices.find(o)->second;
        Vertex * dest = vertices.find(d)->second;
        
        dest->removeNbr(origin);
        origin->removeNbr(dest);
    }
    
}
Vertex * Graph::findVertex(int id){
    if (vertices.count(id)){
        return vertices.find(id)->second;
    }
    else{
        return NULL;
    }
}
