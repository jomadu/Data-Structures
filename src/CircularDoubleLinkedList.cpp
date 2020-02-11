//
//  CircularDoubleLinkedList.cpp
//  DataStructures
//
//  Created by Max Dunn on 7/26/17.
//  Copyright © 2017 Max Dunn. All rights reserved.
//

#ifndef CircularDoubleLinkedList_hpp
#define CircularDoubleLinkedList_hpp

#include "CircularDoubleLinkedList.hpp"

//Constructors
CircularDoubleLinkedList::CircularDoubleLinkedList(){
    size_ = 0;
    head_ = NULL;
    tail_ = NULL;
}

// Destructor
CircularDoubleLinkedList::~CircularDoubleLinkedList(){
    Node * curr = head_;
    Node * next = head_;
    for (int i = 0; i < size_; i++){
        next = curr->getNext();
        delete curr;
        curr = next;
    }
    head_ = NULL;
    tail_ = NULL;
}

// Gets
int CircularDoubleLinkedList::getSize(){
    return size_;
}

// Sets

// Helpers
int CircularDoubleLinkedList::getData(int idx){
    Node * curr;
    
    if (idx < 0 || idx >= size_)
        throw out_of_range("Data retrieval idx out of range.");
    
    if (idx < size_/2){
        curr = head_;
        for (int i = 0; i < idx; i++){
            curr = curr->getNext();
        }
    }
    else{
        curr = tail_;
        for (int i = size_; i >= idx; i--){
            curr = curr->getPrev();
        }
    }
    return curr->getData();
}
void CircularDoubleLinkedList::setData(int idx, int data){
    Node * curr;
    
    if (idx < 0 || idx >= size_)
        throw out_of_range("Data retrieval idx out of range.");
    
    if (idx < size_/2){
        curr = head_;
        for (int i = 0; i < idx; i++){
            curr = curr->getNext();
        }
    }
    else{
        curr = tail_;
        for (int i = size_; i >= idx; i--){
            curr = curr->getPrev();
        }
    }
    return curr->setData(data);
}
void CircularDoubleLinkedList::append(int data){
    Node * newNode = new Node(data);

    if (this->isEmpty()){
        head_ = newNode;
        tail_ = newNode;
    }
    else{
        newNode->setPrev(tail_);
        newNode->setNext(head_);
        tail_->setNext(newNode);
        head_->setPrev(newNode);
        tail_ = newNode;
    }

    size_++;
}
void CircularDoubleLinkedList::prepend(int data){
    Node * newNode = new Node(data);
    
    if (this->isEmpty()){
        head_ = newNode;
        tail_ = newNode;
        newNode->setNext(head_);
        newNode->setPrev(head_);
    }
    else{
        newNode->setNext(head_);
        newNode->setPrev(tail_);
        tail_->setNext(newNode);
        head_->setPrev(newNode);
        head_ = newNode;
    }

    size_++;
}
void CircularDoubleLinkedList::insert(int idx, int data){
    // Input Cleansing
    if (idx < 0 || idx > size_)
        throw out_of_range("Insertion idx out of range.");

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
        Node * newNode = new Node(data);
        Node * curr;
        Node * prev;
        
        if (idx < size_/2){
            curr = head_;
            for (int i = 0; i < idx; i++){
                curr = curr->getNext();
            }
        }
        else{
            curr = tail_;
            for (int i = size_; i >= idx; i--){
                curr = curr->getPrev();
            }
        }
        prev = curr->getPrev();
        
        prev->setNext(newNode);
        newNode->setPrev(prev);
        curr->setPrev(newNode);
        newNode->setNext(curr);
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
        delete head_;
        head_ = NULL;
        tail_ = NULL;
    }
    // Multiple Nodes in list 
    else{
        Node * second = head_->getNext();
        delete head_;
        second->setPrev(tail_);
        tail_->setNext(second);
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
        delete tail_;
        head_ = NULL;
        tail_ = NULL;
    }
    // Multiple Nodes in List
    else{
        Node * prev = tail_->getPrev();
        delete tail_;
        prev->setNext(head_);
        head_->setNext(prev);
        tail_ = prev;
    }

    size_ --;
}

void CircularDoubleLinkedList::remove(int idx){
    // Input Cleansing
    if (idx < 0 || idx >= size_)
        throw out_of_range("Removal idx out of range.");

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
        Node * curr = head_;
        Node * prev;
        Node * next;
        if (idx < size_/2){
            curr = head_;
            for (int i = 0; i < idx; i++){
                curr = curr->getNext();
            }
        }
        else{
            curr = tail_;
            for (int i = size_; i >= idx; i--){
                curr = curr->getPrev();
            }
        }
        prev = curr->getPrev();
        next = curr->getNext();
        
        prev->setNext(next);
        next->setPrev(prev);
        delete curr;
        size_ --;
    }
}
void CircularDoubleLinkedList::display(){
    stringstream ss;
    Node * curr = head_;
    for (int i = 0; i < size_; i++){
        ss << "[" + to_string(curr->getData()) + "] -> ";
        curr = curr->getNext();
    }
    cout << ss.str() + "EOL\n";
}
Node * CircularDoubleLinkedList::search(int d){
    Node * curr = head_;
    for (int i = 0; i < (size_ - 1); i++){
        if (curr->getData() == d){
            return curr;
        }
        else{
            curr = curr->getNext();
        }
    }
    return NULL;
}
bool CircularDoubleLinkedList::isEmpty(){
    return ((head_ == NULL) && (tail_ == NULL));
}

#endif
