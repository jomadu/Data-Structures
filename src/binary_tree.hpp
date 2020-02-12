#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP

#include <stdio.h>
#include <memory>
#include "tree_node.hpp"

class BinaryTree{
private:
    std::shared_ptr<TreeNode> root_;
public:
    // Constructors
    BinaryTree();
    
    // Destructor
    ~BinaryTree();
    
    // Gets
    std::shared_ptr<TreeNode> getRoot();
    
    // Sets
    
    // Helpers
    void insert(int v);
    void insert_rec(std::shared_ptr<TreeNode> n, int v);
    void remove(int v);
    void remove_rec(std::shared_ptr<TreeNode> n, int v);
    int getHeight(std::shared_ptr<TreeNode> n);
    int getDepth(std::shared_ptr<TreeNode> n);
    std::shared_ptr<TreeNode> findMax(std::shared_ptr<TreeNode> rt);
    std::shared_ptr<TreeNode> findMin(std::shared_ptr<TreeNode> rt);
    std::shared_ptr<TreeNode> search(std::shared_ptr<TreeNode> rt, int v);
    void display(std::shared_ptr<TreeNode> rt);
};

#endif // BINARY_TREE_HPP
