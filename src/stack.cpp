/**
 * @file stack.cpp
 * @author Max Dunn (maxdunn123@gmail.com)
 * @copyright Copyright Max Dunn (c) 2020. All rights reserved.
 * 
 * @brief Stack implementation
 */
#include "stack.hpp"

/**
 * @brief Push \p data on top
 * 
 * @param data 
 */
void Stack::push(const int data)
{
    ll_.insert(0, data);
}

/**
 * @brief Remove and return data off top of stack
 * 
 * @return int data on top of stack
 */
int Stack::pop()
{
    auto d = ll_.data(0);
    ll_.removeHead();
    return d;
}

/**
 * @brief Remove all data in stack
 */
void Stack::clear()
{
    while (!isEmpty())
    {
        pop();
    }
}

/**
 * @brief Return, but not remove, data on top of stack
 * 
 * @return int data on top of stack
 */
int Stack::peek() const
{
    return ll_.data(0);
}

/**
 * @brief Evaluates if the stack contains any data
 * 
 * @return true stack is empty
 * @return false stack is not empty
 */
bool Stack::isEmpty() const
{
    return ll_.isEmpty();
}

/**
 * @brief Get size_
 * 
 * @return int number of datum in stack
 */
int Stack::size() const
{
    return ll_.size();
}
