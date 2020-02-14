/**
 * @file double_linked_list.cpp
 * @author Max Dunn (maxdunn123@gmail.com)
 * @copyright Copyright Max Dunn (c) 2020. All rights reserved.
 * 
 * @brief DoubleLinkedList implementation 
 */

#include "double_linked_list.hpp"
#include <stdexcept>

/**
 * @brief Get LinkedListNode::data_ from LinkedListNode at \p idx.
 * Overrides LinkedList::data(const int idx)
 * 
 * @param idx index in list. [0, (LinkedList::size_ - 1)]
 * @return int LinkedListNode::data_ from LinkedListNode at \p idx
 */
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

/**
 * @brief Appends list with a LinkedListNode with data_ = \p data
 * Overrides LinkedList::append(const int data)
 * 
 * @param data LinkedListNode::data_
 */
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

/**
 * @brief Prepends list with a LinkedListNode with data_ = \p data
 * Overrides LinkedList::prepend(const int data)
 * 
 * @param data LinkedListNode::data_
 */
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

/**
 * @brief Inserts a LinkedListNode with data_ = \p data at index \p idx
 * Overrides LinkedList::insert(const int idx, const int data)
 * 
 * @param idx index in list. [0, (LinkedList::size_ - 1)]
 * @param data LinkedListNode::data_
 */
void DoubleLinkedList::insert(const int idx, const int data)
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

/**
 * @brief Removes the first LinkedListNode from list
 * Overrides LinkedList::removeHead()
 */
void DoubleLinkedList::removeHead()
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
        auto next = head_->next();
        head_.reset();
        next->prev(nullptr);
        head_ = next;
    }

    size_--;
}

/**
 * @brief Removes the last LinkedListNode from list
 * Overrides LinkedList::removeTail()
 */
void DoubleLinkedList::removeTail()
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
        // Multiple node in List
        auto prev = tail_->prev();
        tail_.reset();
        prev->next(nullptr);
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
void DoubleLinkedList::remove(const int idx)
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
