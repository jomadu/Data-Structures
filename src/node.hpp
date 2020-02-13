/**
 * @file node.hpp
 * @author Max Dunn (maxdunn123@gmail.com)
 * @copyright Copyright Max Dunn (c) 2020. All rights reserved.
 * 
 * @brief Node declaration
 * - data_ : int
 * - next_ : std::shared_ptr<Node>
 * - prev_ : std::shared_ptr<Node>
 */
#ifndef NODE_HPP
#define NODE_HPP

#include <stdio.h>
#include <memory>

class Node
{
public:
    Node();
    Node(const int data);

    int data() const;
    std::shared_ptr<Node> next() const;
    std::shared_ptr<Node> prev() const;

    void data(const int data);
    void next(std::shared_ptr<Node> next);
    void prev(std::shared_ptr<Node> prev);

private:
    int data_;
    std::shared_ptr<Node> next_;
    std::shared_ptr<Node> prev_;
};

#endif // NODE_HPP
