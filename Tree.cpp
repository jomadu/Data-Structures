//
//  Tree.cpp
//  DataStructures
//
//  Created by Max Dunn on 8/4/17.
//  Copyright © 2017 Max Dunn. All rights reserved.
//

#include "Tree.hpp"

// Constructors
Tree::Tree(){

}

// Destructor
Tree::~Tree(){
    delete root;
}

// Gets
TreeNode * Tree::getRoot(){
    return root;
}

// Sets

// Helpers
void Tree::insert(int val){
    if (root == NULL){
        root = new TreeNode(NULL,val);
    }
    else{
        insert_rec(root, val);
    }
    
}
void Tree::insert_rec(TreeNode * n, int val){
    // Base Case
    if (n == NULL){
        n = new TreeNode(n->getParent(),val);
    }
    // Look Left
    else if (n->getData() >= val){
        //Insert to empty child?
        if (!n->hasLeftChild()){
            TreeNode * c = new TreeNode(n, val);
            n->setLeft(c);
        }
        //Recurse
        else{
            insert_rec(n->getLeft(), val);
        }
    }
    // Look Right
    else{
        //Insert to empty child?
        if (!n->hasRightChild()){
            TreeNode * c = new TreeNode(n, val);
            n->setRight(c);
        }
        //Recurse
        else{
            insert_rec(n->getRight(), val);
        }
    }
}
void Tree::remove(int val){
    if (root != NULL){
        remove_rec(root, val);
    }
}
void Tree::remove_rec(TreeNode * n, int val){
    //Cleaning input
    if (n == NULL){
        return;
    }
    //Check if n is the node we are searching for
    else if (n->getData() == val){
        //Case of has no children
        if (n->isLeaf()){
            //n is root
            if (n == root){
                delete n;
                root = NULL;
            }
            //n is not root
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
            
            //n is root
            if (n == root){
                c->setParent(NULL);
                delete n;
                root = c;
            }
            
            //n is not root
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
            
            //Adjust the root node of the subtree
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
            if (n == root){
                newSubTreeRoot->setParent(NULL);
                root = newSubTreeRoot;
            }
            else{
                newSubTreeRoot->setParent(n->getParent());
            }
            delete n;
        }
    }
    // Look Left
    else if (n->getData() >= val){
        // Recurse
        remove_rec(n->getLeft(), val);
    }
    // Look Right
    else if (n->getData() < val){
        // Recurse
        remove_rec(n->getRight(), val);
    }
}
int Tree::getDepth(TreeNode * nd){
    int depth = 0;
    TreeNode * curr = nd;
    
    while (curr->hasParent()){
        curr = curr->getParent();
        depth ++;
    }
    
    return depth;
}
int Tree::getHeight(TreeNode * rt){
    //Base Case
    if (rt == NULL){
        return 0;
    }
    else{
        int leftHeight = getHeight(rt->getLeft());
        int rightHeight = getHeight(rt->getRight());
        
        if (leftHeight > rightHeight){
            return (leftHeight + 1);
        }
        else {
            return (rightHeight + 1);
        }
    }
}
TreeNode * Tree::findMax(TreeNode * rt){
    // traverse as far right as you can go, then return that node
    TreeNode * curr = rt;
    while(curr->hasRightChild()){
        curr = curr->getRight();
    }
    return curr;
}
TreeNode * Tree::findMin(TreeNode * rt){
    // traverse as far left as you can go, then return that node
    TreeNode * curr = rt;
    while(curr->hasLeftChild()){
        curr = curr->getLeft();
    }
    return curr;
}
TreeNode * Tree::search(TreeNode * rt, int val){
    TreeNode * ret = NULL;
    
    // Base Case (Not Found)
    if (rt == NULL){
        ret = NULL;
    }
    // Base Case (Found)
    else if (rt->getData() == val){
        ret = rt;
    }
    // Recurse Left
    else if (rt->getData() >= val){
        ret = search(rt->getLeft(), val);
    }
    // Recurse Right
    else if (rt->getData() < val){
        ret = search(rt->getRight(), val);
    }
    else{
        // Something has gone horribly wrong
        ret = NULL;
    }
    
    return ret;
}
void Tree::display(TreeNode * rt){
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
