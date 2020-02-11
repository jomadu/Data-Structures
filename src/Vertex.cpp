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
Vertex::Vertex(int k){
    key_ = k;
}
Vertex::Vertex(int k, int v){
    key_ = k;
    val_ = v;
}

// Destructor
Vertex::~Vertex(){
    for (unordered_map<int, Vertex *>::iterator it = nbrs.begin(); it != nbrs.end(); ++it)
        delete it->second;
}

// Gets
int Vertex::getKey(){
    return key_;
}
int Vertex::getVal(){
    return val_;
}
unordered_map<int, Vertex *> Vertex::getNbrs(){
    return nbrs;
}

// Sets
void Vertex::setVal(int d){
    val_ = d;
}

// Helpers
void Vertex::addNbr(int k, Vertex * vtx){
    nbrs.emplace(make_pair(k, vtx));
}
void Vertex::removeNbr(int k){
    nbrs.erase(k);
}
Vertex * Vertex::findNbr(int k){
    unordered_map<int, Vertex *>::iterator it = nbrs.find(k);
    if (it == nbrs.end()){
        return NULL;
    }
    else{
        return it->second;
    }
}

