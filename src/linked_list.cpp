#include "linked_list.hpp"
#include <stdexcept>
#include <sstream>
#include <iostream>

// Constructors
LinkedList::LinkedList() : size_(0), head_(nullptr), tail_(nullptr){
}

// Destructor
LinkedList::~LinkedList(){
    auto curr = head_;
    auto next = head_;
    while (curr != nullptr){
        next = curr->next();
        curr.reset();
        curr = next;
    }
    head_ = nullptr;
    tail_ = nullptr;
}

// Gets
int LinkedList::size(){
    return size_;
}

// Sets

// Helpers
int LinkedList::data(int idx){
    auto curr = head_;
    
    if (idx < 0 || idx >= size_)
        throw std::out_of_range("Data retrieval idx out of range.");
    
    for (auto i = 0; i < idx; i++){
        curr = curr->next();
    }
    return curr->data();
}
void LinkedList::data(int idx, int data){
    auto curr = head_;
    
    if (idx < 0 || idx >= size_)
        throw std::out_of_range("Data retrieval idx out of range.");
    
    for (auto i = 0; i < idx; i++){
        curr = curr->next();
    }
    
    curr->data(data);
}
void LinkedList::append(int data){
    auto newNode = std::make_shared<Node>(data);

    if (this->isEmpty()){
        head_ = newNode;
        tail_ = newNode;
    }
    else{
        tail_->next(newNode);
        tail_ = newNode;
    }           

    size_++;
}
void LinkedList::prepend(int data){
    auto newNode = std::make_shared<Node>(data);

    if (this->isEmpty()){
        head_ = newNode;
        tail_ = newNode;
    }
    else{
        newNode->next(head_);
        head_ = newNode;
    }

    size_++;
}
void LinkedList::insert(int idx, int data){
    // Input Cleansing
    if (idx < 0 || idx > size_)
        throw std::out_of_range("Insertion idx out of range.");

    // Insert as a insertHead
    if (idx == 0){
        prepend(data);
    }
    
    // Insert as an insertTail (really append)
    else if (idx == size_){
        append(data);
    }
    
    // Insert in the middle
    // i.e. idx element of [1, size-1]
    else{
        auto newNode = std::make_shared<Node>(data);
        auto curr = head_;
        auto prev = head_;
        for (auto i = 0; i < idx; i++){
            prev = curr;
            curr = curr->next();
        }
        prev->next(newNode);
        newNode->next(curr);
        size_++;
    }

}
void LinkedList::removeHead(){
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
        head_ = second;
    }

    size_ --;
}
void LinkedList::removeTail(){
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
        auto curr = head_;
        auto prev = head_;
        while (curr->next() != nullptr){
            prev = curr;
            curr = curr->next();        
        }
        curr.reset();
        prev->next(nullptr);
        tail_ = prev;
    }

    size_ --;
}
void LinkedList::remove(int idx){
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
    // i.e. idx element of [1, size-2]
    else{
        auto curr = head_;
        auto prev = head_;
        for (auto i = 0; i < idx; i++){
            prev = curr;
            curr = curr->next();        
        }
        prev->next(curr->next());
        curr.reset();
        size_ --;
    }
}
void LinkedList::display(){
    std::stringstream ss;
    auto curr = head_;
    while (curr != nullptr){
        ss << "[" + std::to_string(curr->data()) + "] -> ";
        curr = curr->next();
    }
    std::cout << ss.str() + "EOL\n";
}
std::shared_ptr<Node> LinkedList::search(int data){

    auto curr = head_;
    while (curr != nullptr){
        if (curr->data() == data){
            return curr;
        }
        else{
            curr = curr->next();
        }
    }
    return nullptr;
}

bool LinkedList::isEmpty(){
    return ((head_ == nullptr) && (tail_ == nullptr));
}
