//
//  Vertex.cpp
//  DataStructures
//
//  Created by Max Dunn on 7/28/17.
//  Copyright © 2017 Max Dunn. All rights reserved.
//

#include "Vertex.hpp"

// Constructors
Vertex::Vertex(){
}
Vertex::Vertex(int key){
    _key = key;
}
Vertex::Vertex(int key, int val){
    _key = key;
    _val = val;
}

// Destructor
Vertex::~Vertex(){
    for (unordered_map<int, Vertex *>::iterator it = nbrs.begin(); it != nbrs.end(); ++it)
        delete it->second;
}

// Gets
int Vertex::getKey(){
    return _key;
}
int Vertex::getVal(){
    return _val;
}
unordered_map<int, Vertex *> Vertex::getNbrs(){
    return nbrs;
}

// Sets
void Vertex::setVal(int d){
    _val = d;
}

// Helpers
void Vertex::addNbr(int key, Vertex * vtx){
    nbrs.emplace(make_pair(key, vtx));
}
void Vertex::removeNbr(int key){
    nbrs.erase(key);
}
Vertex * Vertex::findNbr(int key){
    unordered_map<int, Vertex *>::iterator it = nbrs.find(key);
    if (it == nbrs.end()){
        return NULL;
    }
    else{
        return it->second;
    }
}

