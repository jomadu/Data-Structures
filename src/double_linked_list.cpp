
#include "double_linked_list.hpp"
#include <stdexcept>
#include <sstream>
#include <iostream>

int DoubleLinkedList::data(const int idx) const
{
    std::shared_ptr<LinkedListNode> curr;

    if (idx < 0 || idx >= size_)
        throw std::out_of_range("Data retrieval idx out of range.");

    if (idx < size_ / 2)
    {
        curr = head_;
        for (auto i = 0; i < idx; i++)
        {
            curr = curr->next();
        }
    }
    else
    {
        curr = tail_;
        for (auto i = size_ - 1 ; i > idx; i--)
        {
            curr = curr->prev();
        }
    }
    return curr->data();
}

void DoubleLinkedList::data(const int idx, const int data)
{
    std::shared_ptr<LinkedListNode> curr;

    if (idx < 0 || idx >= size_)
        throw std::out_of_range("Data retrieval idx out of range.");

    if (idx < size_ / 2)
    {
        curr = head_;
        for (auto i = 0; i < idx; i++)
        {
            curr = curr->next();
        }
    }
    else
    {
        curr = tail_;
        for (auto i = size_ - 1; i > idx; i--)
        {
            curr = curr->prev();
        }
    }
    return curr->data(data);
}
void DoubleLinkedList::append(const int data)
{
    auto newNode = std::make_shared<LinkedListNode>(data);

    if (this->isEmpty())
    {
        head_ = newNode;
        tail_ = newNode;
    }
    else
    {
        tail_->next(newNode);
        newNode->prev(tail_);
        tail_ = newNode;
    }

    size_++;
}
void DoubleLinkedList::prepend(const int data)
{
    auto newNode = std::make_shared<LinkedListNode>(data);

    if (head_ == nullptr)
    {
        head_ = newNode;
        tail_ = newNode;
    }
    else
    {
        newNode->next(head_);
        head_->prev(newNode);
        head_ = newNode;
    }

    size_++;
}
void DoubleLinkedList::insert(const int idx, const int data)
{
    // Insert as a insertHead
    if (idx <= 0)
    {
        prepend(data);
    }
    // Insert as an insertTail
    else if (idx >= size_)
    {
        append(data);
    }
    // Insert in the middle
    else
    {
        auto newNode = std::make_shared<LinkedListNode>(data);
        std::shared_ptr<LinkedListNode> curr;
        std::shared_ptr<LinkedListNode> prev;

        if (idx < size_ / 2)
        {
            curr = head_;
            for (auto i = 0; i < idx; i++)
            {
                curr = curr->next();
            }
        }
        else
        {
            curr = tail_;
            for (auto i = size_ - 1; i > idx; i--)
            {
                curr = curr->prev();
            }
        }
        prev = curr->prev();

        prev->next(newNode);
        newNode->prev(prev);
        curr->prev(newNode);
        newNode->next(curr);
        size_++;
    }
}
void DoubleLinkedList::removeHead()
{
    // Empty List
    if (this->isEmpty())
    {
        return;
    }
    // Single LinkedListNode in List
    else if (head_ == tail_)
    {
        head_.reset();
        head_ = nullptr;
        tail_ = nullptr;
    }
    // Multiple Nodes in list
    else
    {
        auto next = head_->next();
        head_.reset();
        next->prev(nullptr);
        head_ = next;
    }

    size_--;
}
void DoubleLinkedList::removeTail()
{
    // Empty List
    if (this->isEmpty())
    {
        return;
    }
    // Single LinkedListNode in List
    else if (head_ == tail_)
    {
        tail_.reset();
        head_ = nullptr;
        tail_ = nullptr;
    }
    // Multiple Nodes in List
    else
    {
        auto prev = tail_->prev();
        tail_.reset();
        prev->next(nullptr);
        tail_ = prev;
    }

    size_--;
}
void DoubleLinkedList::remove(const int idx)
{
    // Remove from head
    if (idx <= 0)
    {
        removeHead();
    }
    // Remove from tail
    else if (idx >= (size_ - 1))
    {
        removeTail();
    }
    // Remove from middle
    // i.e. idx element of [1, size-2]
    else
    {
        auto curr = head_;
        std::shared_ptr<LinkedListNode> prev;
        std::shared_ptr<LinkedListNode> next;
        if (idx < size_ / 2)
        {
            curr = head_;
            for (auto i = 0; i < idx; i++)
            {
                curr = curr->next();
            }
        }
        else
        {
            curr = tail_;
            for (auto i = size_ - 1; i > idx; i--)
            {
                curr = curr->prev();
            }
        }
        prev = curr->prev();
        next = curr->next();
        prev->next(next);
        next->prev(prev);
        curr.reset();
        size_--;
    }
}
