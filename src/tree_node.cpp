#include "tree_node.hpp"

/**
 * @brief Construct a new TreeNode::TreeNode
 */
TreeNode::TreeNode() : parent_(nullptr), left_(nullptr), right_(nullptr)
{
}

/**
 * @brief Construct a new TreeNode::TreeNode
 * 
 * @param parent initial parent_
 * @param data initial data_
 */
TreeNode::TreeNode(std::shared_ptr<TreeNode> parent, const int data) : TreeNode()
{
    parent_ = parent;
    data_ = data;
}

/**
 * @brief Gets left_
 * 
 * @return std::shared_ptr<TreeNode> left_
 */
std::shared_ptr<TreeNode> TreeNode::left()
{
    return left_;
}

/**
 * @brief Gets right_
 * 
 * @return std::shared_ptr<TreeNode> right_
 */
std::shared_ptr<TreeNode> TreeNode::right()
{
    return right_;
}

/**
 * @brief Gets parent_
 * 
 * @return std::shared_ptr<TreeNode> parent_
 */
std::shared_ptr<TreeNode> TreeNode::parent()
{
    return parent_;
}

/**
 * @brief Sets left_
 * 
 * @param left left_
 */
void TreeNode::left(std::shared_ptr<TreeNode> left)
{
    left_ = left;
}

/**
 * @brief Sets right_
 * 
 * @param right right_
 */
void TreeNode::right(std::shared_ptr<TreeNode> right)
{
    right_ = right;
}

/**
 * @brief Sets parent_
 * 
 * @param parent parent_
 */
void TreeNode::parent(std::shared_ptr<TreeNode> parent)
{
    parent_ = parent;
}

/**
 * @brief Evaluates if TreeNode is a leaf
 * 
 * @return true is leaf node
 * @return false is not a leaf node
 */
bool TreeNode::isLeaf()
{
    return (right_ == nullptr) && (left_ == nullptr);
}

/**
 * @brief Evaluates if TreeNode is a left child
 * 
 * @return true is a left child
 * @return false is not a left child
 */
bool TreeNode::isLeftChild()
{
    return (parent_->left().get() == this);
}

/**
 * @brief Evaluates if TreeNode is a right child
 * 
 * @return true is a right child
 * @return false is not a right child
 */
bool TreeNode::isRightChild()
{
    return (parent_->right().get() == this);
}

/**
 * @brief Evaluates if TreeNode has a left child
 * 
 * @return true has a left child
 * @return false does not have a left child
 */
bool TreeNode::hasLeftChild()
{
    return (left_ != nullptr);
}

/**
 * @brief Evaluates if TreeNode has a right child
 * 
 * @return true has a right child
 * @return false does not have a right child
 */
bool TreeNode::hasRightChild()
{
    return (right_ != nullptr);
}

/**
 * @brief Evaluates if TreeNode has a parent
 * 
 * @return true has a parent
 * @return false does not have a parent
 */
bool TreeNode::hasParent()
{
    return (parent_ != nullptr);
}
