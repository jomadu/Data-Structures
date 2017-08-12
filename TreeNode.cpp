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
    parent = NULL;
    left = NULL;
    right = NULL;
}
TreeNode::TreeNode(TreeNode * p, int d){
    parent = p;
    left = NULL;
    right = NULL;
    data = d;
}

// Destructor
TreeNode::~TreeNode(){
    delete right;
    delete left;
}

// Gets
int TreeNode::getData(){
    return data;
}
TreeNode * TreeNode::getLeft(){
    return left;
}
TreeNode * TreeNode::getRight(){
    return right;
}
TreeNode * TreeNode::getParent(){
    return parent;
}

// Sets
void TreeNode::setData(int d){
    data = d;
}
void TreeNode::setLeft(TreeNode * n){
    left = n;
}
void TreeNode::setRight(TreeNode * n){
    right = n;
}
void TreeNode::setParent(TreeNode * n){
    parent = n;
}

// Helpers
bool TreeNode::isLeaf(){
    return (right == NULL)&&(left == NULL);
}
bool TreeNode::isLeftChild(){
    return (parent->getLeft() == this);
}
bool TreeNode::isRightChild(){
    return (parent->getRight() == this);
}
bool TreeNode::hasLeftChild(){
    return (left != NULL);
}
bool TreeNode::hasRightChild(){
    return (right != NULL);
}
bool TreeNode::hasParent(){
    return (parent != NULL);
}

