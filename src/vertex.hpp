#ifndef VERTEX_HPP
#define VERTEX_HPP

#include <stdio.h>
#include <unordered_map>
#include <memory>

class Vertex{
private:
    int key_;
    int val_;
    std::unordered_map<int, std::shared_ptr<Vertex>> nbrs_;
public:
    // Constructors
    Vertex();
    Vertex(int k);
    Vertex(int k, int v);
    
    // Destructor
    ~Vertex();
    
    // Gets
    int key();
    int val();
    std::unordered_map<int, std::shared_ptr<Vertex>> nbrs();

    // Sets
    void setVal(int v);
    
    // Helpers
    void addNbr(int k, std::shared_ptr<Vertex> vtx);
    void removeNbr(int k);
    std::shared_ptr<Vertex> findNbr(int k);
};

#endif // VERTEX_HPP
