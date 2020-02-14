/**
 * @file binary_search_tree.hpp
 * @author Max Dunn (maxdunn123@gmail.com)
 * @copyright Copyright Max Dunn (c) 2020. All rights reserved.
 * 
 * @brief BinarySearchTree declaration
 * - root_ : TreeNode
 */
#ifndef BINARY_SEARCH_TREE_HPP
#define BINARY_SEARCH_TREE_HPP

#include <stdio.h>
#include <memory>
#include <vector>
#include "tree_node.hpp"

class BinarySearchTree
{
public:
    std::shared_ptr<TreeNode> root() const;
    void insert(const int data);
    void remove(const int data);
    void clear();
    int getHeight(std::shared_ptr<TreeNode> node) const;
    int getDepth(std::shared_ptr<TreeNode> node) const;
    void display(std::shared_ptr<TreeNode> rt) const;
    std::vector<int> getDataDF(std::shared_ptr<TreeNode> rt) const;
    std::vector<int> getDataBF(std::shared_ptr<TreeNode> rt) const;
    std::shared_ptr<TreeNode> findMax(std::shared_ptr<TreeNode> rt) const;
    std::shared_ptr<TreeNode> findMin(std::shared_ptr<TreeNode> rt) const;
    std::shared_ptr<TreeNode> search(std::shared_ptr<TreeNode> rt, const int data) const;

private:
    void insert_rec(std::shared_ptr<TreeNode> n, const int data);
    void remove_rec(std::shared_ptr<TreeNode> n, const int data);

    std::shared_ptr<TreeNode> root_;
};

#endif // BINARY_SEARCH_TREE_HPP
