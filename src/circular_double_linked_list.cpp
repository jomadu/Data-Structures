/**
 * @file circular_double_linked_list.cpp
 * @author Max Dunn (maxdunn123@gmail.com)
 * @copyright Copyright Max Dunn (c) 2020. All rights reserved.
 * 
 * @brief CircularDoubleLinkedList implementation
 */

#include "circular_double_linked_list.hpp"
#include <stdexcept>

/**
 * @brief Get LinkedListNode::data_ from LinkedListNode at \p idx.
 * Overrides LinkedList::data(const int idx)
 * 
 * @param idx index in list. [0, (LinkedList::size_ - 1)]
 * @return int LinkedListNode::data_ from LinkedListNode at \p idx
 */
int CircularDoubleLinkedList::data(const int idx) const
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
    return curr->data();
}

/**
 * @brief Set LinkedListNode::data_ for LinkedListNode at \p idx
 * Overrides LinkedList::data(const int idx, const int data)
 * 
 * @param idx index in list. [0, (LinkedList::size_ - 1)]
 * @param data LinkedListNode::data_
 */
void CircularDoubleLinkedList::data(const int idx, const int data)
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

/**
 * @brief Appends list with a LinkedListNode with data_ = \p data
 * Overrides LinkedList::append(const int data)
 * 
 * @param data LinkedListNode::data_
 */
void CircularDoubleLinkedList::append(const int data)
{
    auto new_node = std::make_shared<LinkedListNode>(data);

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

/**
 * @brief Prepends list with a LinkedListNode with data_ = \p data
 * Overrides LinkedList::prepend(const int data)
 * 
 * @param data LinkedListNode::data_
 */
void CircularDoubleLinkedList::prepend(const int data)
{
    auto new_node = std::make_shared<LinkedListNode>(data);

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

/**
 * @brief Inserts a LinkedListNode with data_ = \p data at index \p idx
 * Overrides LinkedList::insert(const int idx, const int data)
 * 
 * @param idx index in list. [0, (LinkedList::size_ - 1)]
 * @param data LinkedListNode::data_
 */
void CircularDoubleLinkedList::insert(const int idx, const int data)
{
    if (idx <= 0)
    {
        prepend(data);
    }
    else if (idx >= size_)
    {
        append(data);
    }
    else
    {
        // Insert in the middle
        auto new_node = std::make_shared<LinkedListNode>(data);
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

        prev->next(new_node);
        new_node->prev(prev);
        curr->prev(new_node);
        new_node->next(curr);
        size_++;
    }
}

/**
 * @brief Removes the first LinkedListNode from list
 * Overrides LinkedList::removeHead()
 */
void CircularDoubleLinkedList::removeHead()
{
    if (this->isEmpty())
    {
        return;
    }
    else if (head_ == tail_)
    {
        // Single node in List
        head_.reset();
        head_ = nullptr;
        tail_ = nullptr;
    }
    else
    {
        // Multiple nodes in list
        auto second = head_->next();
        head_.reset();
        second->prev(tail_);
        tail_->next(second);
        head_ = second;
    }

    size_--;
}

/**
 * @brief Removes the last LinkedListNode from list
 * Overrides LinkedList::removeTail()
 */
void CircularDoubleLinkedList::removeTail()
{
    if (this->isEmpty())
    {
        return;
    }
    else if (head_ == tail_)
    {
        // Single node in List
        tail_.reset();
        head_ = nullptr;
        tail_ = nullptr;
    }
    else
    {
        // Multiple nodes in List
        auto prev = tail_->prev();
        tail_.reset();
        prev->next(head_);
        head_->prev(prev);
        tail_ = prev;
    }

    size_--;
}

/**
 * @brief Removes the LinkedListNode at index \p idx in the list
 * Overrides LinkedList::remove(const int idx)
 * 
 * @param idx index in list. [0, (LinkedList::size_ - 1)]
 */
void CircularDoubleLinkedList::remove(const int idx)
{
    if (idx <= 0)
    {
        removeHead();
    }
    else if (idx >= (size_ - 1))
    {
        removeTail();
    }
    else
    {
        // Remove from middle
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
