/**
 * @file linked_list_code_sample.cpp
 * @author Max Dunn (maxdunn123@gmail.com)
 * @copyright Copyright Max Dunn (c) 2020. All rights reserved.
 * 
 * @brief LinkedList Code Sample
 * 
 * This sample code demonstrates my ability to:
 * - write classes
 * - employ inheritance
 * - employ polymorphism
 * - combine classes to create useful data structures
 * 
 * Instructions:
 * 1) If not already done, change the file extension from .txt to .cpp
 *     $ mv linked_list_sample_code.txt linked_list_sample_code.cpp
 * 2) Compile:
 *     $ g++ -std=c++11 linked_list_sample_code.cpp -o linked_list_sample_code
 * 3) Run:
 *     $ ./linked_list_sample_code
 * 
 * Sample Output:
 * $ ./linked_list_sample_code
 * 
 * -----------------------
 * Linked List Sample Code
 * -----------------------
 * Author: Max Dunn (maxdunn123@gmail.com)
 * GitHub: git@github.com/jomadu
 * LinkedIn: www.linkedin.com/in/maxdunn123
 * -----------------------
 * Adding to LinkedList using LinkedList::append()
 * { [0] }
 * { [0] [1] }
 * { [0] [1] [2] }
 * { [0] [1] [2] [3] }
 * { [0] [1] [2] [3] [4] }
 * Done adding.
 * { [0] [1] [2] [3] [4] }
 * Clearing LinkedList by calling LinkedList::removeHead()
 * { [1] [2] [3] [4] }
 * { [2] [3] [4] }
 * { [3] [4] }
 * { [4] }
 * { }
 * Adding to LinkedList using LinkedList::prepend()
 * { [0] }
 * { [1] [0] }
 * { [2] [1] [0] }
 * { [3] [2] [1] [0] }
 * { [4] [3] [2] [1] [0] }
 * Clearing LinkedList by calling LinkedList::removeTail()
 * { [4] [3] [2] [1] }
 * { [4] [3] [2] }
 * { [4] [3] }
 * { [4] }
 * { }
 * 
 */

#include <memory>
#include <vector>
#include <stdexcept>
#include <sstream>
#include <iostream>

class Node
{
public:
    Node();
    Node(const int data);

    int data() const;
    void data(const int data);

protected:
    int data_;
};

class LinkedListNode : public Node
{
public:
    LinkedListNode();
    LinkedListNode(const int data);

    std::shared_ptr<LinkedListNode> next() const;
    std::shared_ptr<LinkedListNode> prev() const;
    void next(std::shared_ptr<LinkedListNode> next);
    void prev(std::shared_ptr<LinkedListNode> prev);

private:
    std::shared_ptr<LinkedListNode> next_;
    std::shared_ptr<LinkedListNode> prev_;
};

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

/**
 * @brief Construct a new Node::Node
 */
Node::Node() : data_(0)
{
}

/**
 * @brief Construct a new Node::Node
 * 
 * @param data initial data_
 */
Node::Node(const int data) : data_(data)
{
}

/**
 * @brief Get data_
 * 
 * @return int data_
 */
int Node::data() const
{
    return data_;
}
/**
 * @brief Set data_
 * 
 * @param data
 */
void Node::data(const int data)
{
    data_ = data;
}

/**
 * @brief Construct a new LinkedListNode::LinkedListNode
 */
LinkedListNode::LinkedListNode() : next_(nullptr), prev_(nullptr)
{
}

/**
 * @brief Construct a new LinkedListNode::LinkedListNode
 * 
 * @param data initial data_
 */
LinkedListNode::LinkedListNode(const int data) : next_(nullptr), prev_(nullptr)
{
    data_ = data;
}

/**
 * @brief Get next_
 * 
 * @return std::shared_ptr<LinkedListNode> next_
 */
std::shared_ptr<LinkedListNode> LinkedListNode::next() const
{
    return next_;
}

/**
 * @brief Get prev_
 * 
 * @return std::shared_ptr<LinkedListNode> prev_
 */
std::shared_ptr<LinkedListNode> LinkedListNode::prev() const
{
    return prev_;
}

/**
 * @brief Set next_
 * 
 * @param next 
 */
void LinkedListNode::next(std::shared_ptr<LinkedListNode> next)
{
    next_ = next;
}

/**
 * @brief Set prev_
 * 
 * @param prev 
 */
void LinkedListNode::prev(std::shared_ptr<LinkedListNode> prev)
{
    prev_ = prev;
}

/**
 * @brief Construct a new LinkedList::Linked List
 */
LinkedList::LinkedList() : size_(0), head_(nullptr), tail_(nullptr)
{
}

/**
 * @brief Gets size_
 * 
 * @return int size_
 */
int LinkedList::size() const
{
    return size_;
}

/**
 * @brief Gets head_
 * 
 * @return std::shared_ptr<LinkedListNode> head_
 */
std::shared_ptr<LinkedListNode> LinkedList::head() const
{
    return head_;
}

/**
 * @brief Gets tail_
 * 
 * @return std::shared_ptr<LinkedListNode> tail_
 */
std::shared_ptr<LinkedListNode> LinkedList::tail() const
{
    return tail_;
}

/**
 * @brief Gets LinkedListNode::data_ from LinkedListNode at \p idx
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
 * @brief Sets LinkedListNode::data_ from LinkedListNode at \p idx
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

/**
 * @brief Linked List Sample Code
 * 
 * @return int 
 */
int main()
{
    std::cout << "-----------------------" << std::endl;
    std::cout << "Linked List Sample Code" << std::endl;
    std::cout << "-----------------------" << std::endl;
    std::cout << "Author: Max Dunn (maxdunn123@gmail.com)" << std::endl;
    std::cout << "GitHub: git@github.com/jomadu" << std::endl;
    std::cout << "LinkedIn: www.linkedin.com/in/maxdunn123" << std::endl;
    std::cout << "-----------------------" << std::endl;

    LinkedList ll;
    std::cout << "Adding to LinkedList using LinkedList::append()" << std::endl;
    for (int i = 0; i < 5; i++)
    {
        ll.append(i);
        ll.display();
    }
    std::cout << "Done adding." << std::endl;
    ll.display();
    std::cout << "Clearing LinkedList by calling LinkedList::removeHead()" << std::endl;
    while (!ll.isEmpty())
    {
        ll.removeHead();
        ll.display();
    }
    std::cout << "Adding to LinkedList using LinkedList::prepend()" << std::endl;
    for (int i = 0; i < 5; i++)
    {
        ll.prepend(i);
        ll.display();
    }
    std::cout << "Clearing LinkedList by calling LinkedList::removeTail()" << std::endl;
    while (!ll.isEmpty())
    {
        ll.removeTail();
        ll.display();
    }
}