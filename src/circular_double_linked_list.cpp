#include "circular_double_linked_list.hpp"
#include <stdexcept>
#include <sstream>
#include <iostream>

//Constructors
CircularDoubleLinkedList::CircularDoubleLinkedList(): size_(0), head_(nullptr), tail_(nullptr) {
}

// Destructor
CircularDoubleLinkedList::~CircularDoubleLinkedList(){
    auto curr = head_;
    auto next = head_;
    for (auto i = 0; i < size_; i++){
        next = curr->next();
        curr.reset();
        curr = next;
    }
    head_ = nullptr;
    tail_ = nullptr;
}

// Gets
int CircularDoubleLinkedList::size(){
    return size_;
}

// Sets

// Helpers
int CircularDoubleLinkedList::data(int idx){
    std::shared_ptr<Node> curr;
    
    if (idx < 0 || idx >= size_)
        throw std::out_of_range("Data retrieval idx out of range.");
    
    if (idx < size_/2){
        curr = head_;
        for (auto i = 0; i < idx; i++){
            curr = curr->next();
        }
    }
    else{
        curr = tail_;
        for (auto i = size_; i >= idx; i--){
            curr = curr->prev();
        }
    }
    return curr->data();
}
void CircularDoubleLinkedList::data(int idx, int data){
    std::shared_ptr<Node> curr;
    
    if (idx < 0 || idx >= size_)
        throw std::out_of_range("Data retrieval idx out of range.");
    
    if (idx < size_/2){
        curr = head_;
        for (auto i = 0; i < idx; i++){
            curr = curr->next();
        }
    }
    else{
        curr = tail_;
        for (auto i = size_; i >= idx; i--){
            curr = curr->prev();
        }
    }
    return curr->data(data);
}
void CircularDoubleLinkedList::append(int data){
    auto newNode = std::make_shared<Node>(data);

    if (this->isEmpty()){
        head_ = newNode;
        tail_ = newNode;
    }
    else{
        newNode->prev(tail_);
        newNode->next(head_);
        tail_->next(newNode);
        head_->prev(newNode);
        tail_ = newNode;
    }

    size_++;
}
void CircularDoubleLinkedList::prepend(int data){
    auto newNode = std::make_shared<Node>(data);
    
    if (this->isEmpty()){
        head_ = newNode;
        tail_ = newNode;
        newNode->next(head_);
        newNode->prev(head_);
    }
    else{
        newNode->next(head_);
        newNode->prev(tail_);
        tail_->next(newNode);
        head_->prev(newNode);
        head_ = newNode;
    }

    size_++;
}
void CircularDoubleLinkedList::insert(int idx, int data){
    // Input Cleansing
    if (idx < 0 || idx > size_)
        throw std::out_of_range("Insertion idx out of range.");

    // Insert as a insertHead
    if (idx == 0){
        prepend(data);
    }
    // Insert as an insertTail
    else if (idx == size_){
        append(data);
    }
    // Insert in the middle
    else{
        auto newNode = std::make_shared<Node>(data);
        std::shared_ptr<Node> curr;
        std::shared_ptr<Node> prev;
        
        if (idx < size_/2){
            curr = head_;
            for (auto i = 0; i < idx; i++){
                curr = curr->next();
            }
        }
        else{
            curr = tail_;
            for (auto i = size_; i >= idx; i--){
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
void CircularDoubleLinkedList::removeHead(){
    // Empty List
    if (this->isEmpty()){
        return;
    }
    // Single Node in List
    else if (head_ == tail_){
        head_.reset();
        head_ = nullptr;
        tail_ = nullptr;
    }
    // Multiple Nodes in list 
    else{
        auto second = head_->next();
        head_.reset();
        second->prev(tail_);
        tail_->next(second);
        head_ = second;
    }

    size_ --;
}
void CircularDoubleLinkedList::removeTail(){
    // Empty List
    if (this->isEmpty()){
        return;
    }
    // Single Node in List
    else if (head_ == tail_){
        tail_.reset();
        head_ = nullptr;
        tail_ = nullptr;
    }
    // Multiple Nodes in List
    else{
        auto prev = tail_->prev();
        tail_.reset();
        prev->next(head_);
        head_->next(prev);
        tail_ = prev;
    }

    size_ --;
}

void CircularDoubleLinkedList::remove(int idx){
    // Input Cleansing
    if (idx < 0 || idx >= size_)
        throw std::out_of_range("Removal idx out of range.");

    // Remove from head
    if (idx == 0){
        removeHead();
    }
    // Remove from tail
    else if (idx == (size_-1)){
        removeTail();
    }
    // Remove from middle
    else{
        auto curr = head_;
        std::shared_ptr<Node> prev;
        std::shared_ptr<Node> next;
        if (idx < size_/2){
            curr = head_;
            for (auto i = 0; i < idx; i++){
                curr = curr->next();
            }
        }
        else{
            curr = tail_;
            for (auto i = size_; i >= idx; i--){
                curr = curr->prev();
            }
        }
        prev = curr->prev();
        next = curr->next();
        
        prev->next(next);
        next->prev(prev);
        curr.reset();
        size_ --;
    }
}
void CircularDoubleLinkedList::display(){
    std::stringstream ss;
    auto curr = head_;
    for (auto i = 0; i < size_; i++){
        ss << "[" + std::to_string(curr->data()) + "] -> ";
        curr = curr->next();
    }
    std::cout << ss.str() + "EOL\n";
}
std::shared_ptr<Node> CircularDoubleLinkedList::search(int d){
    auto curr = head_;
    for (auto i = 0; i < (size_ - 1); i++){
        if (curr->data() == d){
            return curr;
        }
        else{
            curr = curr->next();
        }
    }
    return nullptr;
}
bool CircularDoubleLinkedList::isEmpty(){
    return ((head_ == nullptr) && (tail_ == nullptr));
}

