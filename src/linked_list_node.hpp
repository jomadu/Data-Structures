/**
 * @file linked_list_node.hpp
 * @author Max Dunn (maxdunn123@gmail.com)
 * @copyright Copyright Max Dunn (c) 2020. All rights reserved.
 * 
 * @brief LinkedListNode declaration
 * Inherits: Node
 * - next_ : std::shared_ptr<LinkedListNode>
 * - prev_ : std::shared_ptr<LinkedListNode>
 */
#ifndef LINKED_LIST_NODE_HPP
#define LINKED_LIST_NODE_HPP

#include <stdio.h>
#include "node.hpp"
#include <memory>

class LinkedListNode : public Node
{
public:
    LinkedListNode();
    LinkedListNode(const int data);

    std::shared_ptr<LinkedListNode> next() const;
    std::shared_ptr<LinkedListNode> prev() const;
    void next(std::shared_ptr<LinkedListNode> next);
    void prev(std::shared_ptr<LinkedListNode> prev);

private:
    std::shared_ptr<LinkedListNode> next_;
    std::shared_ptr<LinkedListNode> prev_;
};

#endif // LINKED_LIST_NODE_HPP
