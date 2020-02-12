#ifndef DOUBLE_LINKED_LIST_HPP
#define DOUBLE_LINKED_LIST_HPP

#include <stdio.h>
#include <memory>
#include "node.hpp"
#include "linked_list.hpp"

class DoubleLinkedList : public LinkedList
{
public:
    int data(int idx) override;
    void data(int idx, int data) override;
    void append(int data) override;
    void prepend(int data) override;
    void insert(int idx, int data) override;
    void removeHead() override;
    void removeTail() override;
    void remove(int idx) override;
};
#endif // DOUBLE_LINKED_LIST_HPP