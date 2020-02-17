/**
 * @file vertex.hpp
 * @author Max Dunn (maxdunn123@gmail.com)
 * @copyright Copyright Max Dunn (c) 2020. All rights reserved.
 * 
 * @brief Vertex declaration
 * - key_ : int
 * - val_ : int
 * - nbrs_ : std::unordered_map<int, std::shared_ptr<Vertex>>
 */

#ifndef VERTEX_HPP
#define VERTEX_HPP

#include <stdio.h>
#include <unordered_map>
#include <memory>

class Vertex
{

public:
    Vertex(){};
    Vertex(const int key);
    Vertex(const int key, const int val);

    int key() const;
    int val() const;
    std::unordered_map<int, std::shared_ptr<Vertex>> nbrs() const;
    void val(const int val);
    void addNeighbor(const int key, std::shared_ptr<Vertex> nbr);
    void removeNeighbor(const int key);
    std::shared_ptr<Vertex> findNeighbor(const int key) const;

private:
    int key_;
    int val_;
    std::unordered_map<int, std::shared_ptr<Vertex>> nbrs_;
};

#endif // VERTEX_HPP
