//
//  TreeNode.cpp
//  DataStructures
//
//  Created by Max Dunn on 8/4/17.
//  Copyright © 2017 Max Dunn. All rights reserved.
//

#include "TreeNode.hpp"

// Constructors
TreeNode::TreeNode(){
    parent_ = NULL;
    left_ = NULL;
    right_ = NULL;
}
TreeNode::TreeNode(TreeNode * p, int d){
    parent_ = p;
    left_ = NULL;
    right_ = NULL;
    data_ = d;
}

// Destructor
TreeNode::~TreeNode(){
    delete right_;
    delete left_;
}

// Gets
int TreeNode::getData(){
    return data_;
}
TreeNode * TreeNode::getLeft(){
    return left_;
}
TreeNode * TreeNode::getRight(){
    return right_;
}
TreeNode * TreeNode::getParent(){
    return parent_;
}

// Sets
void TreeNode::setData(int d){
    data_ = d;
}
void TreeNode::setLeft(TreeNode * l){
    left_ = l;
}
void TreeNode::setRight(TreeNode * r){
    right_ = r;
}
void TreeNode::setParent(TreeNode * p){
    parent_ = p;
}

// Helpers
bool TreeNode::isLeaf(){
    return (right_ == NULL)&&(left_ == NULL);
}
bool TreeNode::isLeftChild(){
    return (parent_->getLeft() == this);
}
bool TreeNode::isRightChild(){
    return (parent_->getRight() == this);
}
bool TreeNode::hasLeftChild(){
    return (left_ != NULL);
}
bool TreeNode::hasRightChild(){
    return (right_ != NULL);
}
bool TreeNode::hasParent(){
    return (parent_ != NULL);
}

