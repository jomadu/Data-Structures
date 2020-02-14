/**
 * @file queue.cpp
 * @author Max Dunn (maxdunn123@gmail.com)
 * @copyright Copyright Max Dunn (c) 2020. All rights reserved.
 * 
 * @brief Queue implementation
 */

#include "queue.hpp"

/**
 * @brief Push \p data onto back of Queue
 * 
 * @param data
 */
void Queue::push(const int data){
    ll_.append(data);
}

/**
 * @brief Remove and return data at front of Queue
 * 
 * @return int data at front of Queue
 */
int Queue::pop(){
    int d = ll_.data(0);
    ll_.removeHead();
    return d;
}

/**
 * @brief Clears Queue of all data
 */
void Queue::clear()
{
    while(!isEmpty())
    {
        pop();
    }
}
/**
 * @brief Returns data at front of Queue without removal
 * 
 * @return int data at front of Queue
 */
int Queue::peek() const{
    return ll_.data(0);
}

/**
 * @brief Evaluates if the Queue is empty
 * 
 * @return true queue is empty 
 * @return false queue is not empty
 */
bool Queue::isEmpty() const{
    return ll_.isEmpty();
}

/**
 * @brief Get size_
 * 
 * @return int number of datum in queue
 */
int Queue::size() const{
    return ll_.size();
}
