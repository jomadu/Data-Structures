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
void Graph::addVertex(int key, int val){
    Vertex * newVertex = new Vertex(key, val);
    _vertices.emplace(make_pair(key, newVertex));
}
void Graph::removeVertex(int key){
    _vertices.erase(key);
    for(unordered_map<int, Vertex *>::iterator it = _vertices.begin(); it != _vertices.end(); it++){
        it->second->removeNbr(key);
    }
}
void Graph::addEdge(int o, int d){
    if (_vertices.count(o) && _vertices.count(d)){
        Vertex * origin = _vertices.find(o)->second;
        Vertex * dest = _vertices.find(d)->second;
        int originKey = origin->getKey();
        int destKey = dest->getKey();
        
        origin->addNbr(destKey, dest);
        dest->addNbr(originKey, origin);
    }
}
void Graph::removeEdge(int o, int d){
    
    if (_vertices.count(o) && _vertices.count(d)){
        Vertex * origin = _vertices.find(o)->second;
        Vertex * dest = _vertices.find(d)->second;
    
        int originKey = _vertices.find(o)->second->getKey();
        int destKey = _vertices.find(d)->second->getKey();
    
        if (origin->findNbr(destKey) && dest->findNbr(originKey)){
            dest->removeNbr(originKey);
            origin->removeNbr(destKey);
        }
    }
    
}
Vertex * Graph::findVertex(int key){
    if (_vertices.count(key)){
        return _vertices.find(key)->second;
    }
    else{
        return NULL;
    }
}


bool Graph::hasEdge(int o, int d){
    Vertex * origin = _vertices.find(o)->second;
    Vertex * dest = _vertices.find(d)->second;
    
    int originKey = _vertices.find(o)->second->getKey();
    int destKey = _vertices.find(d)->second->getKey();
    
    if (origin->findNbr(destKey) && dest->findNbr(originKey))
        return true;
    else
        return false;
}

