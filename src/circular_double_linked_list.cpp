#include "circular_double_linked_list.hpp"
#include <stdexcept>
#include <sstream>
#include <iostream>

int CircularDoubleLinkedList::data(int idx)
{
    std::shared_ptr<Node> curr;

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
    return curr->data();
}
void CircularDoubleLinkedList::data(int idx, int data)
{
    std::shared_ptr<Node> curr;

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
void CircularDoubleLinkedList::append(int data)
{
    auto new_node = std::make_shared<Node>(data);

    if (this->isEmpty())
    {
        new_node->prev(new_node);
        new_node->next(new_node);
        head_ = new_node;
        tail_ = new_node;
    }
    else
    {
        new_node->prev(tail_);
        new_node->next(head_);
        tail_->next(new_node);
        head_->prev(new_node);
        tail_ = new_node;
    }

    size_++;
}
void CircularDoubleLinkedList::prepend(int data)
{
    auto new_node = std::make_shared<Node>(data);

    if (this->isEmpty())
    {
        new_node->prev(new_node);
        new_node->next(new_node);
        head_ = new_node;
        tail_ = new_node;
    }
    else
    {
        new_node->next(head_);
        new_node->prev(tail_);
        tail_->next(new_node);
        head_->prev(new_node);
        head_ = new_node;
    }

    size_++;
}
void CircularDoubleLinkedList::insert(int idx, int data)
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
        auto new_node = std::make_shared<Node>(data);
        std::shared_ptr<Node> curr;
        std::shared_ptr<Node> prev;

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

        prev->next(new_node);
        new_node->prev(prev);
        curr->prev(new_node);
        new_node->next(curr);
        size_++;
    }
}
void CircularDoubleLinkedList::removeHead()
{
    // Empty List
    if (this->isEmpty())
    {
        return;
    }
    // Single Node in List
    else if (head_ == tail_)
    {
        head_.reset();
        head_ = nullptr;
        tail_ = nullptr;
    }
    // Multiple Nodes in list
    else
    {
        auto second = head_->next();
        head_.reset();
        second->prev(tail_);
        tail_->next(second);
        head_ = second;
    }

    size_--;
}
void CircularDoubleLinkedList::removeTail()
{
    // Empty List
    if (this->isEmpty())
    {
        return;
    }
    // Single Node in List
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
        prev->next(head_);
        head_->prev(prev);
        tail_ = prev;
    }

    size_--;
}

void CircularDoubleLinkedList::remove(int idx)
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
    else
    {
        auto curr = head_;
        std::shared_ptr<Node> prev;
        std::shared_ptr<Node> next;
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
