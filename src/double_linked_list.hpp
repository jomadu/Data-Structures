#ifndef DOUBLE_LINKED_LIST_HPP
#define DOUBLE_LINKED_LIST_HPP

#include <stdio.h>
#include <memory>
#include "linked_list.hpp"

class DoubleLinkedList : public LinkedList
{
public:
    int data(const int idx) const override;
    void data(const int idx, const int data) override;
    void append(const int data) override;
    void prepend(const int data) override;
    void insert(const int idx, const int data) override;
    void removeHead() override;
    void removeTail() override;
    void remove(const int idx) override;
};
#endif // DOUBLE_LINKED_LIST_HPP