#include "graph.hpp"
#include <stdexcept>
#include <sstream>
#include <algorithm>

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
    auto new_vertex = std::make_shared<Vertex>(k, v);
    verticies_.emplace(std::make_pair(k, new_vertex));
}
void Graph::removeVertex(int k){
    verticies_.erase(k);
    for(auto it = verticies_.begin(); it != verticies_.end(); it++){
        it->second->removeNbr(k);
    }
}
void Graph::addEdge(int o, int d){
    if (verticies_.count(o) && verticies_.count(d)){
        auto origin = verticies_.find(o)->second;
        auto dest = verticies_.find(d)->second;

        auto origin_key = origin->key();
        auto dest_key = dest->key();
        
        origin->addNbr(dest_key, dest);
        dest->addNbr(origin_key, origin);
    }
}
void Graph::removeEdge(int o, int d){
    
    if (verticies_.count(o) && verticies_.count(d)){
        auto origin = verticies_.find(o)->second;
        auto dest = verticies_.find(d)->second;
    
        auto origin_key = verticies_.find(o)->second->key();
        auto dest_key = verticies_.find(d)->second->key();
    
        if (origin->findNbr(dest_key) && dest->findNbr(origin_key)){
            dest->removeNbr(origin_key);
            origin->removeNbr(dest_key);
        }
    }
    
}
std::shared_ptr<Vertex> Graph::findVertex(int k){
    if (verticies_.count(k)){
        return verticies_.find(k)->second;
    }
    else{
        return nullptr;
    }
}
bool Graph::hasEdge(int o, int d){
    auto origin = verticies_.find(o)->second;
    auto dest = verticies_.find(d)->second;
    
    int origin_key = verticies_.find(o)->second->key();
    int dest_key = verticies_.find(d)->second->key();
    
    if (origin->findNbr(dest_key) && dest->findNbr(origin_key))
        return true;
    else
        return false;
}

