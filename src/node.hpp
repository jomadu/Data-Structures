/**
 * @file node.hpp
 * @author Max Dunn (maxdunn123@gmail.com)
 * @copyright Copyright Max Dunn (c) 2020. All rights reserved.
 * 
 * @brief Node declaration
 * # data_ : int
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
    void data(const int data);

protected:
    int data_;
};

#endif // NODE_HPP
