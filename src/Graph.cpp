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
void Graph::addVertex(int k, int v){
    Vertex * newVertex = new Vertex(k, v);
    verticies_.emplace(make_pair(k, newVertex));
}
void Graph::removeVertex(int k){
    verticies_.erase(k);
    for(unordered_map<int, Vertex *>::iterator it = verticies_.begin(); it != verticies_.end(); it++){
        it->second->removeNbr(k);
    }
}
void Graph::addEdge(int o, int d){
    if (verticies_.count(o) && verticies_.count(d)){
        Vertex * origin = verticies_.find(o)->second;
        Vertex * dest = verticies_.find(d)->second;
        int originKey = origin->getKey();
        int destKey = dest->getKey();
        
        origin->addNbr(destKey, dest);
        dest->addNbr(originKey, origin);
    }
}
void Graph::removeEdge(int o, int d){
    
    if (verticies_.count(o) && verticies_.count(d)){
        Vertex * origin = verticies_.find(o)->second;
        Vertex * dest = verticies_.find(d)->second;
    
        int originKey = verticies_.find(o)->second->getKey();
        int destKey = verticies_.find(d)->second->getKey();
    
        if (origin->findNbr(destKey) && dest->findNbr(originKey)){
            dest->removeNbr(originKey);
            origin->removeNbr(destKey);
        }
    }
    
}
Vertex * Graph::findVertex(int k){
    if (verticies_.count(k)){
        return verticies_.find(k)->second;
    }
    else{
        return NULL;
    }
}
bool Graph::hasEdge(int o, int d){
    Vertex * origin = verticies_.find(o)->second;
    Vertex * dest = verticies_.find(d)->second;
    
    int originKey = verticies_.find(o)->second->getKey();
    int destKey = verticies_.find(d)->second->getKey();
    
    if (origin->findNbr(destKey) && dest->findNbr(originKey))
        return true;
    else
        return false;
}

