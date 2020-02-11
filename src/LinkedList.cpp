
//
//  LinkedList.cpp
//  DataStructures
//
//  Created by Max Dunn on 7/26/17.
//  Copyright © 2017 Max Dunn. All rights reserved.
//


#ifndef LinkedList_hpp
#define LinkedList_hpp

#include "LinkedList.hpp"

// Constructors
LinkedList::LinkedList(){
    size_ = 0;
    head_ = NULL;
    tail_ = NULL;
}

// Destructor
LinkedList::~LinkedList(){
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
int LinkedList::getSize(){
    return size_;
}

// Sets

// Helpers
int LinkedList::getData(int idx){
    Node * curr = head_;
    
    if (idx < 0 || idx >= size_)
        throw out_of_range("Data retrieval idx out of range.");
    
    for (int i = 0; i < idx; i++){
        curr = curr->getNext();
    }
    return curr->getData();
}
void LinkedList::setData(int idx, int data){
    Node * curr = head_;
    
    if (idx < 0 || idx >= size_)
        throw out_of_range("Data retrieval idx out of range.");
    
    for (int i = 0; i < idx; i++){
        curr = curr->getNext();
    }
    
    curr->setData(data);
}
void LinkedList::append(int data){
    Node * newNode = new Node(data);

    if (this->isEmpty()){
        head_ = newNode;
        tail_ = newNode;
    }
    else{
        tail_->setNext(newNode);
        tail_ = newNode;
    }           

    size_++;
}
void LinkedList::prepend(int data){
    Node * newNode = new Node(data);

    if (this->isEmpty()){
        head_ = newNode;
        tail_ = newNode;
    }
    else{
        newNode->setNext(head_);
        head_ = newNode;
    }

    size_++;
}
void LinkedList::insert(int idx, int data){
    // Input Cleansing
    if (idx < 0 || idx > size_)
        throw out_of_range("Insertion idx out of range.");

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
        Node * newNode = new Node(data);
        Node * curr = head_;
        Node * prev = head_;
        for (int i = 0; i < idx; i++){
            prev = curr;
            curr = curr->getNext();
        }
        prev->setNext(newNode);
        newNode->setNext(curr);
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
        delete head_;
        head_ = NULL;
        tail_ = NULL;
    }
    // Multiple Nodes in list 
    else{
        Node * second = head_->getNext();
        delete head_;
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
        delete tail_;
        head_ = NULL;
        tail_ = NULL;
    }
    // Multiple Nodes in List
    else{
        Node * curr = head_;
        Node * prev = head_;
        while (curr->getNext() != NULL){
            prev = curr;
            curr = curr->getNext();        
        }
        delete curr;
        prev->setNext(NULL);
        tail_ = prev;
    }

    size_ --;
}
void LinkedList::remove(int idx){
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
        Node * prev = head_;
        for (int i = 0; i < idx; i++){
            prev = curr;
            curr = curr->getNext();        
        }
        prev->setNext(curr->getNext());
        delete curr;
        size_ --;
    }
}
void LinkedList::display(){
    stringstream ss;
    Node * curr = head_;
    while (curr != NULL){
        ss << "[" + to_string(curr->getData()) + "] -> ";
        curr = curr->getNext();
    }
    cout << ss.str() + "EOL\n";
}
Node * LinkedList::search(int data){

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

bool LinkedList::isEmpty(){
    return ((head_ == NULL) && (tail_ == NULL));
}

#endif
