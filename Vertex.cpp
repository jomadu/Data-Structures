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
    id = key;
}
Vertex::Vertex(int key, int d){
    id = key;
    data = d;
}

// Destructor
Vertex::~Vertex(){
    for (unordered_map<int, Vertex *>::iterator it = nbrs.begin(); it != nbrs.end(); ++it)
        delete it->second;
}

// Gets
int Vertex::getId(){
    return id;
}
int Vertex::getData(){
    return data;
}
unordered_map<int, Vertex *> Vertex::getNbrs(){
    return nbrs;
}

// Sets
void Vertex::setData(int d){
    data = d;
}

// Helpers
void Vertex::addNbr(int key, ){
    nbrs.emplace(make_pair(v->getId(), v));
}
void Vertex::removeNbr(int id){
    nbrs.erase(id);
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

