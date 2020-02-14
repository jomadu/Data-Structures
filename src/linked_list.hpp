/**
 * @file linked_list.hpp
 * @author Max Dunn (maxdunn123@gmail.com)
 * @copyright Copyright Max Dunn (c) 2020. All rights reserved.
 * 
 * @brief LinkedList declaration
 * Inherited by: DoubleLinkedList, CircularDoubleLinkedList
 * # size_ : int
 * # head_ : std::shared_ptr<LinkedListNode>
 * # tail_ : std::shared_ptr<LinkedListNode>
 */
#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include "linked_list_node.hpp"
#include <memory>
#include <vector>

class LinkedList
{
public:
    LinkedList();

    int size() const;
    std::shared_ptr<LinkedListNode> head() const;
    std::shared_ptr<LinkedListNode> tail() const;

    virtual int data(const int idx) const;
    virtual void data(const int idx, const int data);
    virtual void append(const int data);
    virtual void prepend(const int data);
    virtual void insert(const int idx, const int data);
    virtual void removeHead();
    virtual void removeTail();
    virtual void remove(const int idx);
    void clear();
    std::vector<std::shared_ptr<LinkedListNode>> search(const int data) const;
    bool isEmpty() const;
    void display() const;

protected:
    int size_;
    std::shared_ptr<LinkedListNode> head_;
    std::shared_ptr<LinkedListNode> tail_;
};

#endif // LINKED_LIST_HPP
