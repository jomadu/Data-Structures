//
//  BTree.cpp
//  DataStructures
//
//  Created by Max Dunn on 8/4/17.
//  Copyright © 2017 Max Dunn. All rights reserved.
//

#include "BTree.hpp"

// Constructors
BTree::BTree(){

}

// Destructor
BTree::~BTree(){
    delete root_;
}

// Gets
TreeNode * BTree::getRoot(){
    return root_;
}

// Sets

// Helpers
void BTree::insert(int v){
    if (root_ == NULL){
        root_ = new TreeNode(NULL,v);
    }
    else{
        insert_rec(root_, v);
    }
    
}
void BTree::insert_rec(TreeNode * n, int v){
    // Base Case
    if (n == NULL){
        n = new TreeNode(n->getParent(),v);
    }
    // Look Left
    else if (n->getData() >= v){
        //Insert to empty child?
        if (!n->hasLeftChild()){
            TreeNode * c = new TreeNode(n, v);
            n->setLeft(c);
        }
        //Recurse
        else{
            insert_rec(n->getLeft(), v);
        }
    }
    // Look Right
    else{
        //Insert to empty child?
        if (!n->hasRightChild()){
            TreeNode * c = new TreeNode(n, v);
            n->setRight(c);
        }
        //Recurse
        else{
            insert_rec(n->getRight(), v);
        }
    }
}
void BTree::remove(int v){
    if (root_ != NULL){
        remove_rec(root_, v);
    }
}
void BTree::remove_rec(TreeNode * n, int v){
    //Cleaning input
    if (n == NULL){
        return;
    }
    //Check if n is the node we are searching for
    else if (n->getData() == v){
        //Case of has no children
        if (n->isLeaf()){
            //n is root_
            if (n == root_){
                delete n;
                root_ = NULL;
            }
            //n is not root_
            else{
                if (n->isLeftChild()){
                    n->getParent()->setLeft(NULL);
                }
                else{
                    n->getParent()->setRight(NULL);
                }
                delete n;
            }
        }
        //Case of has only one child
        else if (n->hasLeftChild() != n->hasRightChild()){
            TreeNode * c;
            if (n->hasLeftChild()){
                c = n->getLeft();
            }
            else{
                c = n->getRight();
            }
            
            //n is root_
            if (n == root_){
                c->setParent(NULL);
                delete n;
                root_ = c;
            }
            
            //n is not root_
            else{
                if (n->isLeftChild()){
                    n->getParent()->setLeft(c);
                }
                else{
                    n->getParent()->setRight(c);
                }
                c->setParent(n->getParent());
                delete n;
            }
        }
        //Case of has two children
        else{
            TreeNode * leftSubtreeMax;
            TreeNode * rightSubtreeMin;
            TreeNode * newSubTreeRoot;
            int leftSubtreeMaxHeight = 0;
            int rightSubtreeMinHeight = 0;
            
            //Find inner-left leaf
            leftSubtreeMax = findMax(n->getLeft());
            leftSubtreeMaxHeight = getHeight(leftSubtreeMax);
            
            //Find inner-right leaf
            rightSubtreeMin = findMin(n->getRight());
            rightSubtreeMinHeight = getHeight(leftSubtreeMax);
            
            
            //Decide which inner leaf to use
            if (leftSubtreeMaxHeight <= rightSubtreeMinHeight){
                newSubTreeRoot = leftSubtreeMax;
            }
            else{
                newSubTreeRoot = rightSubtreeMin;
            }
            
            //Adjust the root_ node of the subtree
            //chop off the leaf
            if (newSubTreeRoot->isLeftChild()){
                newSubTreeRoot->getParent()->setLeft(NULL);
            }
            else{
                newSubTreeRoot->getParent()->setRight(NULL);
            }
            //attach the leaf
            newSubTreeRoot->setLeft(n->getLeft());
            newSubTreeRoot->setRight(n->getRight());
            
            //address if the subtree is full tree
            if (n == root_){
                newSubTreeRoot->setParent(NULL);
                root_ = newSubTreeRoot;
            }
            else{
                newSubTreeRoot->setParent(n->getParent());
            }
            delete n;
        }
    }
    // Look Left
    else if (n->getData() >= v){
        // Recurse
        remove_rec(n->getLeft(), v);
    }
    // Look Right
    else if (n->getData() < v){
        // Recurse
        remove_rec(n->getRight(), v);
    }
}
int BTree::getDepth(TreeNode * n){
    int depth = 0;
    TreeNode * curr = n;
    
    while (curr->hasParent()){
        curr = curr->getParent();
        depth ++;
    }
    
    return depth;
}
int BTree::getHeight(TreeNode * n){
    //Base Case
    if (n == NULL){
        return 0;
    }
    else{
        int leftHeight = getHeight(n->getLeft());
        int rightHeight = getHeight(n->getRight());
        
        if (leftHeight > rightHeight){
            return (leftHeight + 1);
        }
        else {
            return (rightHeight + 1);
        }
    }
}
TreeNode * BTree::findMax(TreeNode * rt){
    // traverse as far right as you can go, then return that node
    TreeNode * curr = rt;
    while(curr->hasRightChild()){
        curr = curr->getRight();
    }
    return curr;
}
TreeNode * BTree::findMin(TreeNode * rt){
    // traverse as far left as you can go, then return that node
    TreeNode * curr = rt;
    while(curr->hasLeftChild()){
        curr = curr->getLeft();
    }
    return curr;
}
TreeNode * BTree::search(TreeNode * rt, int v){
    TreeNode * ret = NULL;
    
    // Base Case (Not Found)
    if (rt == NULL){
        ret = NULL;
    }
    // Base Case (Found)
    else if (rt->getData() == v){
        ret = rt;
    }
    // Recurse Left
    else if (rt->getData() >= v){
        ret = search(rt->getLeft(), v);
    }
    // Recurse Right
    else if (rt->getData() < v){
        ret = search(rt->getRight(), v);
    }
    else{
        // Something has gone horribly wrong
        ret = NULL;
    }
    
    return ret;
}
void BTree::display(TreeNode * rt){
    stringstream ss;
    queue<TreeNode *> q;
    // list of sets - each list is a level
    int level;
    map<int, set<TreeNode *>> levelSets;
    set<TreeNode *> currSet;
    TreeNode * curr;
    
    curr = rt;
    q.push(curr);
    
    while(!q.empty()){
        curr = q.front();

        level = getDepth(curr);
        levelSets[level].emplace(curr);
        
        if (curr->hasLeftChild())
            q.push(curr->getLeft());
        if (curr->hasRightChild())
            q.push(curr->getRight());
        
        q.pop();
    }
    
    for (map<int,set<TreeNode *>>::iterator it1 = levelSets.begin(); it1 != levelSets.end(); it1++){
        for(set<TreeNode *>::reverse_iterator it2 = it1->second.rbegin(); it2 != it1->second.rend(); it2++){
            curr = *it2;
            cout << curr->getData() << " ";
        }
        cout << "\n";
    }
}
