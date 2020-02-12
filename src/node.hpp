#ifndef NODE_HPP
#define NODE_HPP

#include <stdio.h>
#include <memory>

class Node
{
private:
    int data_;
    std::shared_ptr<Node> next_;
    std::shared_ptr<Node> prev_;
public:
    // Constructors
    Node();
    Node(int data);
    
    // Destructor
    ~Node();
    
    // Gets
    int data();
    std::shared_ptr<Node> next();
    std::shared_ptr<Node> prev();

    // Sets
    void data(int data);
    void next(std::shared_ptr<Node> next);
    void prev(std::shared_ptr<Node> prev);
    
    // Helpers
};

#endif // NODE_HPP
