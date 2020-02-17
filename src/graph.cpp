/**
 * @file graph.cpp
 * @author Max Dunn (maxdunn123@gmail.com)
 * @copyright Copyright Max Dunn (c) 2020. All rights reserved.
 * 
 * @brief Graph implementation
 */

#include "graph.hpp"
#include <algorithm>
/**
 * @brief Adds vertex to graph
 * 
 * @param key Vertex::key_
 * @param val Vertex::val_
 */
void Graph::addVertex(const int key, int val)
{
    auto new_vertex = std::make_shared<Vertex>(key, val);
    verticies_.emplace(std::make_pair(key, new_vertex));
}

/**
 * @brief Remove vertex matching \p key from verticies_
 * 
 * @param key of vertex to remove
 */
void Graph::removeVertex(const int key)
{
    verticies_.erase(key);
    for (auto key_vertex_pair : verticies_)
    {
        key_vertex_pair.second->removeNeighbor(key);
    }
}

/**
 * @brief Add an edge between two verticies if they exist
 * 
 * @param key_1
 * @param key_2
 */
void Graph::addEdge(const int key_1, const int key_2)
{
    if (verticies_.count(key_1) && verticies_.count(key_2))
    {
        auto origin = verticies_.find(key_1)->second;
        auto dest = verticies_.find(key_2)->second;

        origin->addNeighbor(key_2, dest);
        dest->addNeighbor(key_1, origin);
    }
}

/**
 * @brief Remove an edge between two verticies if it exists
 * 
 * @param key_1
 * @param key_2 
 */
void Graph::removeEdge(const int key_1, const int key_2)
{

    if (verticies_.count(key_1) && verticies_.count(key_2))
    {
        auto origin = verticies_.find(key_1)->second;
        auto dest = verticies_.find(key_2)->second;

        if (origin->findNeighbor(key_2) && dest->findNeighbor(key_1))
        {
            dest->removeNeighbor(key_1);
            origin->removeNeighbor(key_2);
        }
    }
}

/**
 * @brief finds a Vertex matching \p key
 * 
 * @param key to search for
 * @return std::shared_ptr<Vertex> matching vertex, or nullptr
 */
std::shared_ptr<Vertex> Graph::findVertex(const int key) const
{
    if (verticies_.count(key))
    {
        return verticies_.find(key)->second;
    }
    else
    {
        return nullptr;
    }
}

/**
 * @brief Evaluates if an edge exists between two verticies matching \p key_1 and \p key_2
 * 
 * @param key_1 
 * @param key_2 
 * @return true an edge exists between the verticies matching \p key_1 and \p key_2
 * @return false an edge does not exist between the verticies matching \p key_1 and \p key_2
 */
bool Graph::hasEdge(const int key_1, const int key_2) const
{
    auto origin = verticies_.find(key_1)->second;
    auto dest = verticies_.find(key_2)->second;

    if (origin->findNeighbor(key_2) && dest->findNeighbor(key_1))
        return true;
    else
        return false;
}

/**
 * @brief Returns the number of elements in verticies_
 * 
 * @return int verticies_.size()
 */
int Graph::count() const
{
    return verticies_.size();
}
