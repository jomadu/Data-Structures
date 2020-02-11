//
//  DoubleLinkedList.cpp
//  DataStructures
//
//  Created by Max Dunn on 7/26/17.
//  Copyright © 2017 Max Dunn. All rights reserved.
//


#ifndef DoubleLinkedList_hpp
#define DoubleLinkedList_hpp

#include "DoubleLinkedList.hpp"

// Constructors
DoubleLinkedList::DoubleLinkedList(){
    size_ = 0;
    head_ = NULL;
    tail_ = NULL;
}

// Destructor
DoubleLinkedList::~DoubleLinkedList(){
    Node * curr = head_;
    Node * next = head_;
    while (curr != NULL){
        next = curr->getNext();
        delete curr;
        curr = next;
    }
    head_ = NULL;
    tail_ = NULL;
}

// Gets
int DoubleLinkedList::getSize(){
    return size_;
}

// Sets

// Helpers
int DoubleLinkedList::getData(int idx){
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

void DoubleLinkedList::setData(int idx, int data){
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
void DoubleLinkedList::append(int data){
    Node * newNode = new Node(data);

    if (this->isEmpty()){
        head_ = newNode;
        tail_ = newNode;
    }
    else{
        tail_->setNext(newNode);
        newNode->setPrev(tail_);
        tail_ = newNode;
    }

    size_++;
}
void DoubleLinkedList::prepend(int data){
    Node * newNode = new Node(data);

    if (head_ == NULL){
        head_ = newNode;
        tail_ = newNode;
    }
    else{
        newNode->setNext(head_);
        head_->setPrev(newNode);
        head_ = newNode;
    }

    size_++;
}
void DoubleLinkedList::insert(int idx, int data){
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
void DoubleLinkedList::removeHead(){
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
        Node * next = head_->getNext();
        delete head_;
        next->setPrev(NULL);
        head_ = next;
    }

    size_ --;
}
void DoubleLinkedList::removeTail(){
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
        prev->setNext(NULL);
        tail_ = prev;
    }

    size_ --;
}
void DoubleLinkedList::remove(int idx){
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
    // i.e. idx element of [1, size-2]
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
void DoubleLinkedList::display(){
    stringstream ss;
    Node * curr = head_;
    while (curr != NULL){
        ss << "[" + to_string(curr->getData()) + "] -> ";
        curr = curr->getNext();
    }
    cout << ss.str() + "EOL\n";
}

Node * DoubleLinkedList::search(int data){
    Node * curr = head_;
    while (curr != NULL){
        if (curr->getData() == data){
            return curr;
        }
        else{
            curr = curr->getNext();
        }
    }
    return NULL;
}
bool DoubleLinkedList::isEmpty(){
    return ((head_ == NULL) && (tail_ == NULL));
}
#endif
