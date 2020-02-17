/**
 * @file graph.hpp
 * @author Max Dunn (maxdunn123@gmail.com)
 * @copyright Copyright Max Dunn (c) 2020. All rights reserved.
 * 
 * @brief Graph declaration
 * - verticies_ : std::unordered_map<int, std::shared_ptr<Vertex>>
 */

#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <stdio.h>
#include <memory>
#include "vertex.hpp"

class Graph
{
public:
    void addVertex(const int key, int val);
    void removeVertex(const int key);
    void addEdge(const int key_1, const int key_2);
    void removeEdge(const int key_1, const int key_2);
    std::shared_ptr<Vertex> findVertex(const int key) const;
    bool hasEdge(const int key_1, const int key_2) const;
    int count() const;

private:
    std::unordered_map<int, std::shared_ptr<Vertex>> verticies_;
};

#endif // GRAPH_HPP
