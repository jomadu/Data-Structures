//
//  TreeNode.hpp
//  DataStructures
//
//  Created by Max Dunn on 8/4/17.
//  Copyright © 2017 Max Dunn. All rights reserved.
//

#ifndef TreeNode_hpp
#define TreeNode_hpp

#include <stdio.h>

class TreeNode
{
private:
    int data;
    TreeNode * parent;
    TreeNode * left;
    TreeNode * right;
public:
    // Constructors
    TreeNode();
    TreeNode(TreeNode * p, int d);
    
    // Destructor
    ~TreeNode();
    
    // Gets
    int getData();
    TreeNode * getLeft();
    TreeNode * getRight();
    TreeNode * getParent();
    
    // Sets
    void setData(int d);
    void setLeft(TreeNode * n);
    void setRight(TreeNode * n);
    void setParent(TreeNode * n);
    
    // Helpers
    bool isLeaf();
    bool isLeftChild();
    bool isRightChild();
    bool hasLeftChild();
    bool hasRightChild();
    bool hasParent();
};

#endif /* TreeNode_hpp */
