/**
 * @file node.cpp
 * @author Max Dunn (maxdunn123@gmail.com)
 * @copyright Copyright Max Dunn (c) 2020. All rights reserved.
 * 
 * @brief Node implementation
 */
#include "node.hpp"

/**
 * @brief Construct a new Node::Node
 */
Node::Node() : data_(0)
{
}

/**
 * @brief Construct a new Node::Node
 * 
 * @param data initial data_
 */
Node::Node(const int data) : data_(data)
{
}

/**
 * @brief Get data_
 * 
 * @return int data_
 */
int Node::data() const
{
    return data_;
}
/**
 * @brief Set data_
 * 
 * @param data
 */
void Node::data(const int data)
{
    data_ = data;
} 
