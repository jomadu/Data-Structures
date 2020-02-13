/**
 * @file linked_list_node.cpp
 * @author Max Dunn (maxdunn123@gmail.com)
 * @copyright Copyright Max Dunn (c) 2020. All rights reserved.
 * 
 * @brief LinkedListNode implementation
 */
#include "linked_list_node.hpp"

/**
 * @brief Construct a new LinkedListNode::LinkedListNode
 */
LinkedListNode::LinkedListNode() : next_(nullptr), prev_(nullptr)
{
}

/**
 * @brief Construct a new LinkedListNode::LinkedListNode
 * 
 * @param data initial data_
 */
LinkedListNode::LinkedListNode(const int data) : next_(nullptr), prev_(nullptr)
{
    data_ = data;
}

/**
 * @brief Get next_
 * 
 * @return std::shared_ptr<LinkedListNode> next_
 */
std::shared_ptr<LinkedListNode> LinkedListNode::next() const
{
    return next_;
}

/**
 * @brief Get prev_
 * 
 * @return std::shared_ptr<LinkedListNode> prev_
 */
std::shared_ptr<LinkedListNode> LinkedListNode::prev() const
{
    return prev_;
}

/**
 * @brief Set next_
 * 
 * @param next 
 */
void LinkedListNode::next(std::shared_ptr<LinkedListNode> next)
{
    next_ = next;
}

/**
 * @brief Set prev_
 * 
 * @param prev 
 */
void LinkedListNode::prev(std::shared_ptr<LinkedListNode> prev)
{
    prev_ = prev;
}