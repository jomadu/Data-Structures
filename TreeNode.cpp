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
    _parent = NULL;
    _left = NULL;
    _right = NULL;
}
TreeNode::TreeNode(TreeNode * p, int d){
    _parent = p;
    _left = NULL;
    _right = NULL;
    _data = d;
}

// Destructor
TreeNode::~TreeNode(){
    delete _right;
    delete _left;
}

// Gets
int TreeNode::getData(){
    return _data;
}
TreeNode * TreeNode::getLeft(){
    return _left;
}
TreeNode * TreeNode::getRight(){
    return _right;
}
TreeNode * TreeNode::getParent(){
    return _parent;
}

// Sets
void TreeNode::setData(int d){
    _data = d;
}
void TreeNode::setLeft(TreeNode * l){
    _left = l;
}
void TreeNode::setRight(TreeNode * r){
    _right = r;
}
void TreeNode::setParent(TreeNode * p){
    _parent = p;
}

// Helpers
bool TreeNode::isLeaf(){
    return (_right == NULL)&&(_left == NULL);
}
bool TreeNode::isLeftChild(){
    return (_parent->getLeft() == this);
}
bool TreeNode::isRightChild(){
    return (_parent->getRight() == this);
}
bool TreeNode::hasLeftChild(){
    return (_left != NULL);
}
bool TreeNode::hasRightChild(){
    return (_right != NULL);
}
bool TreeNode::hasParent(){
    return (_parent != NULL);
}

