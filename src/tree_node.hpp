/**
 * @file tree_node.hpp
 * @author Max Dunn (maxdunn123@gmail.com)
 * @copyright Copyright Max Dunn (c) 2020. All rights reserved.
 * 
 * @brief TreeNode declaration
 * inherits Node
 * - parent_ : std::shared_ptr<TreeNode>
 * - left_ : std::shared_ptr<TreeNode>
 * - right_ : std::shared_ptr<TreeNode>
 */
#ifndef TREE_NODE_HPP
#define TREE_NODE_HPP

#include <stdio.h>
#include "node.hpp"
#include <memory>

class TreeNode : public Node
{
public:
    TreeNode();
    TreeNode(std::shared_ptr<TreeNode> parent, const int data);

    std::shared_ptr<TreeNode> left();
    std::shared_ptr<TreeNode> right();
    std::shared_ptr<TreeNode> parent();

    void left(std::shared_ptr<TreeNode> left);
    void right(std::shared_ptr<TreeNode> right);
    void parent(std::shared_ptr<TreeNode> parent);

    bool isLeaf();
    bool isLeftChild();
    bool isRightChild();
    bool hasLeftChild();
    bool hasRightChild();
    bool hasParent();

private:
    std::shared_ptr<TreeNode> parent_;
    std::shared_ptr<TreeNode> left_;
    std::shared_ptr<TreeNode> right_;
};

#endif // TREE_NODE_HPP
