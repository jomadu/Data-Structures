#include "vertex.hpp"
#include <algorithm>

// Constructors
Vertex::Vertex()
{
}
Vertex::Vertex(int k) : key_(k)
{
}
Vertex::Vertex(int k, int v) : Vertex(k)
{
    val_ = v;
}

// Destructor
Vertex::~Vertex()
{
}

// Gets
int Vertex::key()
{
    return key_;
}
int Vertex::val()
{
    return val_;
}
std::unordered_map<int, std::shared_ptr<Vertex>> Vertex::nbrs()
{
    return nbrs_;
}

// Sets
void Vertex::setVal(int d)
{
    val_ = d;
}

// Helpers
void Vertex::addNbr(int k, std::shared_ptr<Vertex> vtx)
{
    nbrs_.emplace(std::make_pair(k, vtx));
}
void Vertex::removeNbr(int k)
{
    nbrs_.erase(k);
}
std::shared_ptr<Vertex> Vertex::findNbr(int k)
{
    auto it = nbrs_.find(k);
    if (it == nbrs_.end())
    {
        return nullptr;
    }
    else
    {
        return it->second;
    }
}
