#ifndef TREE_NODE_HPP
#define TREE_NODE_HPP

#include <stdio.h>
#include <memory>

class TreeNode
{
private:
    int data_;
    std::shared_ptr<TreeNode> parent_;
    std::shared_ptr<TreeNode> left_;
    std::shared_ptr<TreeNode> right_;
public:
    // Constructors
    TreeNode();
    TreeNode(std::shared_ptr<TreeNode> p, int d);
    
    // Destructor
    ~TreeNode();
    
    // Gets
    int data();
    std::shared_ptr<TreeNode> left();
    std::shared_ptr<TreeNode> right();
    std::shared_ptr<TreeNode> parent();
    
    // Sets
    void data(int d);
    void left(std::shared_ptr<TreeNode> l);
    void right(std::shared_ptr<TreeNode> r);
    void parent(std::shared_ptr<TreeNode> p);
    
    // Helpers
    bool isLeaf();
    bool isLeftChild();
    bool isRightChild();
    bool hasLeftChild();
    bool hasRightChild();
    bool hasParent();
};

#endif // TREE_NODE_HPP
