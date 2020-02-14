/**
 * @file linked_list.cpp
 * @author Max Dunn (maxdunn123@gmail.com)
 * @copyright Copyright Max Dunn (c) 2020. All rights reserved.
 * 
 * @brief LinkedList implementation
 */
#include "linked_list.hpp"
#include <stdexcept>
#include <sstream>
#include <iostream>

/**
 * @brief Construct a new LinkedList::LinkedList
 */
LinkedList::LinkedList() : size_(0), head_(nullptr), tail_(nullptr)
{
}

/**
 * @brief Get size_
 * 
 * @return int size_
 */
int LinkedList::size() const
{
    return size_;
}

/**
 * @brief Get head_
 * 
 * @return std::shared_ptr<LinkedListNode> head_
 */
std::shared_ptr<LinkedListNode> LinkedList::head() const
{
    return head_;
}

/**
 * @brief Get tail_
 * 
 * @return std::shared_ptr<LinkedListNode> tail_
 */
std::shared_ptr<LinkedListNode> LinkedList::tail() const
{
    return tail_;
}

/**
 * @brief Get LinkedListNode::data_ from LinkedListNode at \p idx
 * 
 * @param idx index in list. [0, (LinkedList::size_ - 1)]
 * @return int LinkedListNode::data_ from LinkedListNode at \p idx
 */
int LinkedList::data(const int idx) const
{
    auto curr = head_;

    if (idx < 0 || idx >= size_)
    {
        throw std::out_of_range("Data retrieval idx out of range.");
    }

    for (auto i = 0; i < idx; i++)
    {
        curr = curr->next();
    }
    return curr->data();
}

/**
 * @brief Set LinkedListNode::data_ for LinkedListNode at \p idx
 * 
 * @param idx index in list. [0, (LinkedList::size_ - 1)]
 * @param data LinkedListNode::data_
 */
void LinkedList::data(const int idx, const int data)
{
    auto curr = head_;

    if (idx < 0 || idx >= size_)
    {
        throw std::out_of_range("Data retrieval idx out of range.");
    }

    for (auto i = 0; i < idx; i++)
    {
        curr = curr->next();
    }

    curr->data(data);
}

/**
 * @brief Appends list with a LinkedListNode with data_ = \p data
 * 
 * @param data LinkedListNode::data_
 */
void LinkedList::append(const int data)
{
    auto new_node = std::make_shared<LinkedListNode>(data);

    if (this->isEmpty())
    {
        head_ = new_node;
        tail_ = new_node;
    }
    else
    {
        tail_->next(new_node);
        tail_ = new_node;
    }

    size_++;
}
/**
 * @brief Prepends list with a LinkedListNode with data_ = \p data
 * 
 * @param data LinkedListNode::data_
 */
void LinkedList::prepend(const int data)
{
    auto new_node = std::make_shared<LinkedListNode>(data);

    if (this->isEmpty())
    {
        head_ = new_node;
        tail_ = new_node;
    }
    else
    {
        new_node->next(head_);
        head_ = new_node;
    }

    size_++;
}
/**
 * @brief Inserts a LinkedListNode with data_ = \p data at index \p idx
 * 
 * @param idx index in list. [0, (LinkedList::size_ - 1)]
 * @param data LinkedListNode::data_
 */
void LinkedList::insert(const int idx, const int data)
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
        // Insert into middle
        auto new_node = std::make_shared<LinkedListNode>(data);
        auto curr = head_;
        auto prev = head_;
        for (auto i = 0; i < idx; i++)
        {
            prev = curr;
            curr = curr->next();
        }
        prev->next(new_node);
        new_node->next(curr);
        size_++;
    }
}

/**
 * @brief Removes the first LinkedListNode from list
 */
void LinkedList::removeHead()
{
    if (this->isEmpty())
    {
        return;
    }
    else if (head_ == tail_)
    {
        // Single node in list
        head_.reset();
        head_ = nullptr;
        tail_ = nullptr;
    }
    else
    {
        // Multiple nodes in list
        auto second = head_->next();
        head_.reset();
        head_ = second;
    }

    size_--;
}

/**
 * @brief Removes the last LinkedListNode from list
 */
void LinkedList::removeTail()
{
    if (this->isEmpty())
    {
        return;
    }
    else if (head_ == tail_)
    {
        // Single node in list
        tail_.reset();
        head_ = nullptr;
        tail_ = nullptr;
    }
    else
    {
        // Multiple nodes in list
        auto curr = head_;
        auto prev = head_;
        while (curr->next() != nullptr)
        {
            prev = curr;
            curr = curr->next();
        }
        curr.reset();
        prev->next(nullptr);
        tail_ = prev;
    }

    size_--;
}

/**
 * @brief Removes the LinkedListNode at index \p idx in the list
 * 
 * @param idx index in list. [0, (LinkedList::size_ - 1)]
 */
void LinkedList::remove(const int idx)
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
        auto prev = head_;
        for (auto i = 0; i < idx; i++)
        {
            prev = curr;
            curr = curr->next();
        }
        prev->next(curr->next());
        curr.reset();
        size_--;
    }
}

/**
 * @brief Removes all LinkedListNodes from list
 */
void LinkedList::clear()
{
    while (!isEmpty())
    {
        removeHead();
    }
}

/**
 * @brief Searches list for LinkedListNodes with data_ matching \p data
 * 
 * @param data search parameter
 * @return std::vector<std::shared_ptr<LinkedListNode>> vector of matching nodes
 */
std::vector<std::shared_ptr<LinkedListNode>> LinkedList::search(const int data) const
{
    std::vector<std::shared_ptr<LinkedListNode>> results;
    auto curr = head_;
    for (auto i = 0; i < size(); i++)
    {
        if (curr->data() == data)
        {
            results.push_back(curr);
        }
        curr = curr->next();
    }
    return results;
}

/**
 * @brief Evaluates if the list is empty
 * 
 * @return true if empty
 * @return false if not empty
 */
bool LinkedList::isEmpty() const
{
    return ((head_ == nullptr) && (tail_ == nullptr));
}

/**
 * @brief Prints formatted list to std::cout
 */
void LinkedList::display() const
{
    std::stringstream ss;
    ss << "{ ";
    auto curr = head_;
    for (auto i = 0; i < size(); i++)
    {
        ss << "[" + std::to_string(curr->data()) + "] ";
        curr = curr->next();
    }
    std::cout << ss.str() << "}" << std::endl;
}