#include "binary_tree.hpp"
#include <queue>
#include <map>
#include <set>
#include <iostream>
#include <sstream>

// Constructors
BinaryTree::BinaryTree(){

}

// Destructor
BinaryTree::~BinaryTree(){

}

// Gets
std::shared_ptr<TreeNode> BinaryTree::getRoot(){
    return root_;
}

// Sets

// Helpers
void BinaryTree::insert(int v){
    if (root_ == nullptr){
        root_ = std::make_shared<TreeNode>(nullptr,v);
    }
    else{
        insert_rec(root_, v);
    }
    
}
void BinaryTree::insert_rec(std::shared_ptr<TreeNode> n, int v){
    // Base Case
    if (n == nullptr){
        n = std::make_shared<TreeNode>(n->parent(),v);
    }
    // Look Left
    else if (n->data() >= v){
        //Insert to empty child?
        if (!n->hasLeftChild()){
            auto c = std::make_shared<TreeNode>(n, v);
            n->left(c);
        }
        //Recurse
        else{
            insert_rec(n->left(), v);
        }
    }
    // Look Right
    else{
        //Insert to empty child?
        if (!n->hasRightChild()){
            auto c = std::make_shared<TreeNode>(n, v);
            n->right(c);
        }
        //Recurse
        else{
            insert_rec(n->right(), v);
        }
    }
}
void BinaryTree::remove(int v){
    if (root_ != nullptr){
        remove_rec(root_, v);
    }
}
void BinaryTree::remove_rec(std::shared_ptr<TreeNode> n, int v){
    //Cleaning input
    if (n == nullptr){
        return;
    }
    //Check if n is the node we are searching for
    else if (n->data() == v){
        //Case of has no children
        if (n->isLeaf()){
            //n is root_
            if (n == root_){
                root_.reset();
            }
            //n is not root_
            else{
                if (n->isLeftChild()){
                    n->parent()->left(nullptr);
                }
                else{
                    n->parent()->right(nullptr);
                }
                n.reset();
            }
        }
        //Case of has only one child
        else if (n->hasLeftChild() != n->hasRightChild()){
            std::shared_ptr<TreeNode> c;
            if (n->hasLeftChild()){
                c = n->left();
            }
            else{
                c = n->right();
            }
            
            //n is root_
            if (n == root_){
                c->parent(nullptr);
                n.reset();
                root_ = c;
            }
            
            //n is not root_
            else{
                if (n->isLeftChild()){
                    n->parent()->left(c);
                }
                else{
                    n->parent()->right(c);
                }
                c->parent(n->parent());
                n.reset();
            }
        }
        //Case of has two children
        else{
            std::shared_ptr<TreeNode> left_sub_bin_tree_max;
            std::shared_ptr<TreeNode> right_sub_bin_tree_max;
            std::shared_ptr<TreeNode> new_sub_bin_tree_root;
            auto left_sub_bin_tree_max_height = 0;
            auto right_sub_bin_tree_max_height = 0;
            
            //Find inner-left leaf
            left_sub_bin_tree_max = findMax(n->left());
            left_sub_bin_tree_max_height = getHeight(left_sub_bin_tree_max);
            
            //Find inner-right leaf
            right_sub_bin_tree_max = findMin(n->right());
            right_sub_bin_tree_max_height = getHeight(left_sub_bin_tree_max);
            
            
            //Decide which inner leaf to use
            if (left_sub_bin_tree_max_height <= right_sub_bin_tree_max_height){
                new_sub_bin_tree_root = left_sub_bin_tree_max;
            }
            else{
                new_sub_bin_tree_root = right_sub_bin_tree_max;
            }
            
            //Adjust the root_ node of the SubBinaryTree
            //chop off the leaf
            if (new_sub_bin_tree_root->isLeftChild()){
                new_sub_bin_tree_root->parent()->left(nullptr);
            }
            else{
                new_sub_bin_tree_root->parent()->right(nullptr);
            }
            //attach the leaf
            new_sub_bin_tree_root->left(n->left());
            new_sub_bin_tree_root->right(n->right());
            
            //address if the SubBinaryTree is full tree
            if (n == root_){
                new_sub_bin_tree_root->parent(nullptr);
                root_ = new_sub_bin_tree_root;
            }
            else{
                new_sub_bin_tree_root->parent(n->parent());
            }
            n.reset();
        }
    }
    // Look Left
    else if (n->data() >= v){
        // Recurse
        remove_rec(n->left(), v);
    }
    // Look Right
    else if (n->data() < v){
        // Recurse
        remove_rec(n->right(), v);
    }
}
int BinaryTree::getDepth(std::shared_ptr<TreeNode> n){
    auto depth = 0;
    auto curr = n;
    
    while (curr->hasParent()){
        curr = curr->parent();
        depth ++;
    }
    
    return depth;
}
int BinaryTree::getHeight(std::shared_ptr<TreeNode> n){
    //Base Case
    if (n == nullptr){
        return 0;
    }
    else{
        auto leftHeight = getHeight(n->left());
        auto rightHeight = getHeight(n->right());
        
        if (leftHeight > rightHeight){
            return (leftHeight + 1);
        }
        else {
            return (rightHeight + 1);
        }
    }
}
std::shared_ptr<TreeNode> BinaryTree::findMax(std::shared_ptr<TreeNode> rt){
    // traverse as far right as you can go, then return that node
    auto curr = rt;
    while(curr->hasRightChild()){
        curr = curr->right();
    }
    return curr;
}
std::shared_ptr<TreeNode> BinaryTree::findMin(std::shared_ptr<TreeNode> rt){
    // traverse as far left as you can go, then return that node
    auto curr = rt;
    while(curr->hasLeftChild()){
        curr = curr->left();
    }
    return curr;
}
std::shared_ptr<TreeNode> BinaryTree::search(std::shared_ptr<TreeNode> rt, int v){
    std::shared_ptr<TreeNode> ret;
    
    // Base Case (Not Found)
    if (rt == nullptr){
        ret = nullptr;
    }
    // Base Case (Found)
    else if (rt->data() == v){
        ret = rt;
    }
    // Recurse Left
    else if (rt->data() >= v){
        ret = search(rt->left(), v);
    }
    // Recurse Right
    else if (rt->data() < v){
        ret = search(rt->right(), v);
    }
    else{
        // Something has gone horribly wrong
        ret = nullptr;
    }
    
    return ret;
}
void BinaryTree::display(std::shared_ptr<TreeNode> rt){
    std::stringstream ss;
    std::queue<std::shared_ptr<TreeNode>> q;
    // list of sets - each list is a level
    int level;
    std::map<int, std::set<std::shared_ptr<TreeNode>>> levelSets;
    std::set<std::shared_ptr<TreeNode>> currSet;
    std::shared_ptr<TreeNode> curr;
    
    curr = rt;
    q.push(curr);
    
    while(!q.empty()){
        curr = q.front();

        level = getDepth(curr);
        levelSets[level].emplace(curr);
        
        if (curr->hasLeftChild())
            q.push(curr->left());
        if (curr->hasRightChild())
            q.push(curr->right());
        
        q.pop();
    }
    
    for (auto it1 = levelSets.begin(); it1 != levelSets.end(); it1++){
        for(auto it2 = it1->second.rbegin(); it2 != it1->second.rend(); it2++){
            curr = *it2;
            std::cout << curr->data() << " ";
        }
        std::cout << "\n";
    }
}
