#include "node.hpp"
// Constructors
Node::Node() : next_(nullptr), prev_(nullptr)
{
}
Node::Node(int data) : Node()
{
    data_ = data;
}

// Destructor
Node::~Node()
{
}

// Gets
int Node::data()
{
    return data_;
}

std::shared_ptr<Node> Node::next()
{
    return next_;
}

std::shared_ptr<Node> Node::prev()
{
    return prev_;
}

// Sets
void Node::data(int data)
{
    data_ = data;
}

void Node::next(std::shared_ptr<Node> next)
{
    next_ = next;
}

void Node::prev(std::shared_ptr<Node> prev)
{
    prev_ = prev;
}

// Helpers
