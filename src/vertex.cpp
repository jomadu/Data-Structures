/**
 * @file vertex.cpp
 * @author Max Dunn (maxdunn123@gmail.com)
 * @copyright Copyright Max Dunn (c) 2020. All rights reserved.
 * 
 * @brief Vertex implementation
 */

#include "vertex.hpp"
#include <algorithm>

/**
 * @brief Construct a new Vertex::Vertex
 * 
 * @param key initial key_
 */
Vertex::Vertex(const int key) : key_(key)
{
}

/**
 * @brief Construct a new Vertex::Vertex
 * 
 * @param key initial key_ 
 * @param val initial val_
 */
Vertex::Vertex(const int key, const int val) : key_(key), val_(val)
{
}

/**
 * @brief Get key_
 * 
 * @return int key_
 */
int Vertex::key() const
{
    return key_;
}

/**
 * @brief Get val_
 * 
 * @return int val_
 */
int Vertex::val() const
{
    return val_;
}

/**
 * @brief Get nbrs_
 * 
 * @return std::unordered_map<int, std::shared_ptr<Vertex>> nbrs_
 */
std::unordered_map<int, std::shared_ptr<Vertex>> Vertex::nbrs() const
{
    return nbrs_;
}

/**
 * @brief Set val_
 * 
 * @param val val_
 */
void Vertex::val(int val)
{
    val_ = val;
}

/**
 * @brief Adds to \p nbr to nbrs_ with key \p key
 * 
 * @param key for neighbor
 * @param nbr neighbor
 */
void Vertex::addNeighbor(const int key, std::shared_ptr<Vertex> nbr)
{
    nbrs_.emplace(std::make_pair(key, nbr));
}

/**
 * @brief Removes neighbor matching \p key from nbrs_
 * 
 * @param key to search for
 */
void Vertex::removeNeighbor(const int key)
{
    nbrs_.erase(key);
}

/**
 * @brief Finds a neighbor in nbrs_ matching \p key
 * 
 * @param key to search for
 * @return std::shared_ptr<Vertex> neighbor if found. nullptr if not found.
 */
std::shared_ptr<Vertex> Vertex::findNeighbor(const int key) const
{
    auto it = nbrs_.find(key);
    if (it == nbrs_.end())
    {
        return nullptr;
    }
    else
    {
        return it->second;
    }
}
