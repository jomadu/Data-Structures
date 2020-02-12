#include "tree_node.hpp"

// Constructors
TreeNode::TreeNode() : parent_(nullptr), left_(nullptr), right_(nullptr)
{
}
TreeNode::TreeNode(std::shared_ptr<TreeNode> p, int d) : TreeNode()
{
    parent_ = p;
    data_ = d;
}

// Destructor
TreeNode::~TreeNode()
{
}

// Gets
int TreeNode::data()
{
    return data_;
}
std::shared_ptr<TreeNode> TreeNode::left()
{
    return left_;
}
std::shared_ptr<TreeNode> TreeNode::right()
{
    return right_;
}
std::shared_ptr<TreeNode> TreeNode::parent()
{
    return parent_;
}

// Sets
void TreeNode::data(int d)
{
    data_ = d;
}
void TreeNode::left(std::shared_ptr<TreeNode> l)
{
    left_ = l;
}
void TreeNode::right(std::shared_ptr<TreeNode> r)
{
    right_ = r;
}
void TreeNode::parent(std::shared_ptr<TreeNode> p)
{
    parent_ = p;
}

// Helpers
bool TreeNode::isLeaf()
{
    return (right_ == nullptr) && (left_ == nullptr);
}
bool TreeNode::isLeftChild()
{
    return (parent_->left().get() == this);
}
bool TreeNode::isRightChild()
{
    return (parent_->right().get() == this);
}
bool TreeNode::hasLeftChild()
{
    return (left_ != nullptr);
}
bool TreeNode::hasRightChild()
{
    return (right_ != nullptr);
}
bool TreeNode::hasParent()
{
    return (parent_ != nullptr);
}
