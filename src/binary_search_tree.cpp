/**
 * @file binary_search_tree.cpp
 * @author Max Dunn (maxdunn123@gmail.com)
 * @copyright Copyright Max Dunn (c) 2020. All rights reserved.
 * 
 * @brief BinarySearchTree implementation
 */
#include "binary_search_tree.hpp"
#include <queue>
#include <map>
#include <iostream>
#include <sstream>

/**
 * @brief Get root_
 * 
 * @return std::shared_ptr<TreeNode> root_ 
 */
std::shared_ptr<TreeNode> BinarySearchTree::root() const
{
    return root_;
}

/**
 * @brief Insert \p data into the tree
 * 
 * @param data 
 */
void BinarySearchTree::insert(const int data)
{
    if (root_ == nullptr)
    {
        root_ = std::make_shared<TreeNode>(nullptr, data);
    }
    else
    {
        insert_rec(root_, data);
    }
}

/**
 * @brief Remove first found instance of \p data in tree using a depth first search
 * 
 * @param data 
 */
void BinarySearchTree::remove(const int data)
{
    if (root_)
    {
        remove_rec(root_, data);
    }
}

/**
 * @brief Removes all nodes from Tree
 */
void BinarySearchTree::clear()
{
    if (root_)
    {
        root_.reset();
    }
}

/**
 * @brief Evaluate depth of \p node
 * 
 * @param node to get depth of
 * @return int depth of \p node
 */
int BinarySearchTree::getDepth(std::shared_ptr<TreeNode> node) const
{
    auto depth = 0;
    auto curr = node;

    while (curr->hasParent())
    {
        curr = curr->parent();
        depth++;
    }

    return depth;
}

/**
 * @brief Evaluate height of \p node
 * 
 * @param node to get height of
 * @return int height of \p node
 */
int BinarySearchTree::getHeight(std::shared_ptr<TreeNode> node) const
{
    //Base Case
    if (node == nullptr)
    {
        return 0;
    }
    else
    {
        auto leftHeight = getHeight(node->left());
        auto rightHeight = getHeight(node->right());

        if (leftHeight > rightHeight)
        {
            return (leftHeight + 1);
        }
        else
        {
            return (rightHeight + 1);
        }
    }
}

/**
 * @brief Returns node with maximum value in tree with root \p rt
 * 
 * @param rt root node of search
 * @return std::shared_ptr<TreeNode>
 */
std::shared_ptr<TreeNode> BinarySearchTree::findMax(std::shared_ptr<TreeNode> rt) const
{
    // traverse as far right as you can go, then return that node
    auto curr = rt;
    while (curr->hasRightChild())
    {
        curr = curr->right();
    }
    return curr;
}

/**
 * @brief Returns node with minimum value in tree with root \p rt
 * 
 * @param rt root node of search
 * @return std::shared_ptr<TreeNode> 
 */
std::shared_ptr<TreeNode> BinarySearchTree::findMin(std::shared_ptr<TreeNode> rt) const
{
    // traverse as far left as you can go, then return that node
    auto curr = rt;
    while (curr->hasLeftChild())
    {
        curr = curr->left();
    }
    return curr;
}

/**
 * @brief Returns first node with data matching \p data
 * 
 * @param rt root node of search
 * @param data to compare
 * @return std::shared_ptr<TreeNode> 
 */
std::shared_ptr<TreeNode> BinarySearchTree::search(std::shared_ptr<TreeNode> rt, const int data) const
{
    std::shared_ptr<TreeNode> ret;

    // Base Case (Not Found)
    if (rt == nullptr)
    {
        ret = nullptr;
    }
    // Base Case (Found)
    else if (rt->data() == data)
    {
        ret = rt;
    }
    // Recurse Left
    else if (rt->data() >= data)
    {
        ret = search(rt->left(), data);
    }
    // Recurse Right
    else if (rt->data() < data)
    {
        ret = search(rt->right(), data);
    }
    else
    {
        // Something has gone horribly wrong
        ret = nullptr;
    }

    return ret;
}

/**
 * @brief Displays the tree over cout from root node \p rt
 * 
 * @param rt node to display from
 */
void BinarySearchTree::display(std::shared_ptr<TreeNode> rt) const
{
    std::stringstream ss;
    std::queue<std::shared_ptr<TreeNode>> q;
    int level;
    std::vector<std::vector<std::shared_ptr<TreeNode>>> levels;
    std::vector<std::shared_ptr<TreeNode>> currSet;
    std::shared_ptr<TreeNode> curr;

    curr = rt;
    q.push(curr);

    while (!q.empty())
    {
        curr = q.front();

        level = getDepth(curr);
        if (level >= levels.size())
        {
            levels.emplace_back();
        }
        levels.at(level).push_back(curr);
        if (curr->hasLeftChild())
        {
            q.push(curr->left());
        }
        if (curr->hasRightChild())
        {
            q.push(curr->right());
        }

        q.pop();
    }

    for (auto level : levels)
    {
        for (auto node : level)
        {
            std::cout << "[" << node->data() << "] ";
        }
        std::cout << std::endl;
    }
}

/**
 * @brief Performs depth first search of tree starting at \p rt ,
 * then returns a vector of node data in DFS order
 * 
 * @param rt 
 * @return std::vector<int> node data in DFS order
 */
std::vector<int> BinarySearchTree::getDataDF(std::shared_ptr<TreeNode> rt) const
{
    std::vector<int> ret;
    if (rt == nullptr)
    {
        return ret;
    }
    else
    {
        ret.push_back(rt->data());
        if (rt->hasLeftChild())
        {
            auto left_data = getDataDF(rt->left());
            ret.insert(ret.end(), left_data.begin(), left_data.end());
        }
        if (rt->hasRightChild())
        {
            auto right_data = getDataDF(rt->right());
            ret.insert(ret.end(), right_data.begin(), right_data.end());
        }
        return ret;
    }
}

/**
 * @brief Performs breadth first search of tree starting at \p rt ,
 * then returns a vector of node data in BFS order
 * 
 * @param rt 
 * @return std::vector<int> node data in BFS order
 */
std::vector<int> BinarySearchTree::getDataBF(std::shared_ptr<TreeNode> rt) const
{
    std::queue<std::shared_ptr<TreeNode>> q;
    // list of sets - each list is a level
    int level;
    std::vector<std::vector<std::shared_ptr<TreeNode>>> levels;
    std::vector<std::shared_ptr<TreeNode>> currSet;
    std::shared_ptr<TreeNode> curr;

    curr = rt;
    q.push(curr);

    while (!q.empty())
    {
        curr = q.front();

        level = getDepth(curr);
        if (level >= levels.size())
        {
            levels.emplace_back();
        }
        levels.at(level).push_back(curr);

        if (curr->hasLeftChild())
        {
            q.push(curr->left());
        }
        if (curr->hasRightChild())
        {
            q.push(curr->right());
        }

        q.pop();
    }

    std::vector<std::shared_ptr<TreeNode>> ret;

    for (auto level : levels)
    {
        for (auto node : level)
        {
            ret.push_back(node);
        }
    }
}

/**
 * @brief Insert recursive helper
 * 
 * @param node root
 * @param data to insert
 */
void BinarySearchTree::insert_rec(std::shared_ptr<TreeNode> node, const int data)
{
    // Base Case
    if (node == nullptr)
    {
        node = std::make_shared<TreeNode>(node->parent(), data);
    }
    // Look Left
    else if (node->data() >= data)
    {
        //Insert to empty child?
        if (!node->hasLeftChild())
        {
            auto c = std::make_shared<TreeNode>(node, data);
            node->left(c);
        }
        //Recurse
        else
        {
            insert_rec(node->left(), data);
        }
    }
    // Look Right
    else
    {
        //Insert to empty child?
        if (!node->hasRightChild())
        {
            auto c = std::make_shared<TreeNode>(node, data);
            node->right(c);
        }
        //Recurse
        else
        {
            insert_rec(node->right(), data);
        }
    }
}

/**
 * @brief Remove recursive helper
 * 
 * @param node root
 * @param data to remove
 */
void BinarySearchTree::remove_rec(std::shared_ptr<TreeNode> node, const int data)
{
    //Cleaning input
    if (node == nullptr)
    {
        return;
    }
    //Check if node is the node we are searching for
    else if (node->data() == data)
    {
        //Case of has no children
        if (node->isLeaf())
        {
            //node is root_
            if (node == root_)
            {
                root_.reset();
            }
            //node is not root_
            else
            {
                if (node->isLeftChild())
                {
                    node->parent()->left(nullptr);
                }
                else
                {
                    node->parent()->right(nullptr);
                }
                node.reset();
            }
        }
        //Case of has only one child
        else if (node->hasLeftChild() != node->hasRightChild())
        {
            std::shared_ptr<TreeNode> c;
            if (node->hasLeftChild())
            {
                c = node->left();
            }
            else
            {
                c = node->right();
            }

            //node is root_
            if (node == root_)
            {
                c->parent(nullptr);
                node.reset();
                root_ = c;
            }

            //node is not root_
            else
            {
                if (node->isLeftChild())
                {
                    node->parent()->left(c);
                }
                else
                {
                    node->parent()->right(c);
                }
                c->parent(node->parent());
                node.reset();
            }
        }
        //Case of has two children
        else
        {
            std::shared_ptr<TreeNode> left_sub_bin_tree_max;
            std::shared_ptr<TreeNode> right_sub_bin_tree_max;
            std::shared_ptr<TreeNode> new_sub_bin_tree_root;
            auto left_sub_bin_tree_max_height = 0;
            auto right_sub_bin_tree_max_height = 0;

            //Find inner-left leaf
            left_sub_bin_tree_max = findMax(node->left());
            left_sub_bin_tree_max_height = getHeight(left_sub_bin_tree_max);

            //Find inner-right leaf
            right_sub_bin_tree_max = findMin(node->right());
            right_sub_bin_tree_max_height = getHeight(left_sub_bin_tree_max);

            //Decide which inner leaf to use
            if (left_sub_bin_tree_max_height <= right_sub_bin_tree_max_height)
            {
                new_sub_bin_tree_root = left_sub_bin_tree_max;
            }
            else
            {
                new_sub_bin_tree_root = right_sub_bin_tree_max;
            }

            //Adjust the root_ node of the SubBinarySearchTree
            //chop off the leaf
            if (new_sub_bin_tree_root->isLeftChild())
            {
                new_sub_bin_tree_root->parent()->left(nullptr);
            }
            else
            {
                new_sub_bin_tree_root->parent()->right(nullptr);
            }
            //attach the leaf
            new_sub_bin_tree_root->left(node->left());
            new_sub_bin_tree_root->right(node->right());

            //address if the SubBinarySearchTree is full tree
            if (node == root_)
            {
                new_sub_bin_tree_root->parent(nullptr);
                root_ = new_sub_bin_tree_root;
            }
            else
            {
                new_sub_bin_tree_root->parent(node->parent());
            }
            node.reset();
        }
    }
    // Look Left
    else if (node->data() >= data)
    {
        // Recurse
        remove_rec(node->left(), data);
    }
    // Look Right
    else if (node->data() < data)
    {
        // Recurse
        remove_rec(node->right(), data);
    }
}