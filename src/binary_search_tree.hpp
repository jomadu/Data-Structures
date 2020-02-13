#ifndef BINARY_SEARCH_TREE_HPP
#define BINARY_SEARCH_TREE_HPP

#include <stdio.h>
#include <memory>
#include <vector>
#include "tree_node.hpp"

class BinarySearchTree{

public:
    std::shared_ptr<TreeNode> root();
    void insert(int v);
    void remove(int v);
    void clear();
    int getHeight(std::shared_ptr<TreeNode> n);
    int getDepth(std::shared_ptr<TreeNode> n);
    void display(std::shared_ptr<TreeNode> rt);
    std::vector<int> getDataDF(std::shared_ptr<TreeNode> rt);
    std::vector<int> getDataBF(std::shared_ptr<TreeNode> rt);
    std::shared_ptr<TreeNode> findMax(std::shared_ptr<TreeNode> rt);
    std::shared_ptr<TreeNode> findMin(std::shared_ptr<TreeNode> rt);
    std::shared_ptr<TreeNode> search(std::shared_ptr<TreeNode> rt, int v);
private:
    void insert_rec(std::shared_ptr<TreeNode> n, int v);
    void remove_rec(std::shared_ptr<TreeNode> n, int v);
    
    std::shared_ptr<TreeNode> root_;
};

#endif // BINARY_SEARCH_TREE_HPP
