//
//  BTree.hpp
//  DataStructures
//
//  Created by Max Dunn on 8/4/17.
//  Copyright © 2017 Max Dunn. All rights reserved.
//

#ifndef BTree_hpp
#define BTree_hpp

#include <stdio.h>
#include "TreeNode.hpp"
#include <queue>
#include <map>
#include <set>
#include <iostream>
#include <sstream>

using namespace std;

class BTree{
private:
    TreeNode * root;
public:
    // Constructors
    BTree();
    
    // Destructor
    ~BTree();
    
    // Gets
    TreeNode * getRoot();
    
    // Sets
    
    // Helpers
    void insert(int val);
    void insert_rec(TreeNode * n, int val);
    void remove(int val);
    void remove_rec(TreeNode * n, int val);
    int getHeight(TreeNode * rt);
    int getDepth(TreeNode * rt);
    TreeNode * findMax(TreeNode * rt);
    TreeNode * findMin(TreeNode * rt);
    TreeNode * search(TreeNode * rt, int val);
    void display(TreeNode * rt);
};

#endif /* BTree_hpp */
