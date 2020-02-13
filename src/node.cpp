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
Node::Node() : next_(nullptr), prev_(nullptr)
{
}

/**
 * @brief Construct a new Node::Node
 * 
 * @param data initial data_
 */
Node::Node(const int data) : Node()
{
    data_ = data;
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
 * @brief Get next_
 * 
 * @return std::shared_ptr<Node> next_
 */
std::shared_ptr<Node> Node::next() const
{
    return next_;
}

/**
 * @brief Get prev_
 * 
 * @return std::shared_ptr<Node> prev_
 */
std::shared_ptr<Node> Node::prev() const
{
    return prev_;
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

/**
 * @brief Set next_
 * 
 * @param next 
 */
void Node::next(std::shared_ptr<Node> next)
{
    next_ = next;
}

/**
 * @brief Set prev_
 * 
 * @param prev 
 */
void Node::prev(std::shared_ptr<Node> prev)
{
    prev_ = prev;
}