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
    _size = 0;
    _head = NULL;
    _tail = NULL;
}

// Destructor
DoubleLinkedList::~DoubleLinkedList(){
    Node * curr = _head;
    Node * next = _head;
    while (curr != NULL){
        next = curr->getNext();
        delete curr;
        curr = next;
    }
    _head = NULL;
    _tail = NULL;
}

// Gets
int DoubleLinkedList::getSize(){
    return _size;
}

// Sets

// Helpers
int DoubleLinkedList::getData(int idx){
    Node * curr;
    
    if (idx < 0 || idx >= _size)
        throw out_of_range("Data retrieval idx out of range.");
    
    if (idx < _size/2){
        curr = _head;
        for (int i = 0; i < idx; i++){
            curr = curr->getNext();
        }
    }
    else{
        curr = _tail;
        for (int i = _size; i >= idx; i--){
            curr = curr->getPrev();
        }
    }
    return curr->getData();
}

void DoubleLinkedList::setData(int idx, int data){
    Node * curr = _head;
    
    if (idx < 0 || idx >= _size)
        throw out_of_range("Data retrieval idx out of range.");
    
    for (int i = 0; i < idx; i++){
        curr = curr->getNext();
    }
    
    curr->setData(data);
}
void DoubleLinkedList::append(int data){
    Node * newNode = new Node(data);

    if (this->isEmpty()){
        _head = newNode;
        _tail = newNode;
    }
    else{
        _tail->setNext(newNode);
        newNode->setPrev(_tail);
        _tail = newNode;
    }

    _size++;
}
void DoubleLinkedList::prepend(int data){
    Node * newNode = new Node(data);

    if (_head == NULL){
        _head = newNode;
        _tail = newNode;
    }
    else{
        newNode->setNext(_head);
        _head->setPrev(newNode);
        _head = newNode;
    }

    _size++;
}
void DoubleLinkedList::insert(int idx, int data){
    // Input Cleansing
    if (idx < 0 || idx > _size)
        throw out_of_range("Insertion idx out of range.");

    // Insert as a insertHead
    if (idx == 0){
        prepend(data);
    }
    // Insert as an insertTail
    else if (idx == _size){
        append(data);
    }
    // Insert in the middle
    else{
        Node * newNode = new Node(data);
        Node * curr;
        Node * prev;
        
        if (idx < _size/2){
            curr = _head;
            for (int i = 0; i < idx; i++){
                curr = curr->getNext();
            }
            prev = curr->getPrev();
        }
        else{
            curr = _tail;
            for (int i = _size; i >= idx; i--){
                curr = curr->getPrev();
            }
            prev = curr->getPrev();
        }
        prev->setNext(newNode);
        newNode->setPrev(prev);
        curr->setPrev(newNode);
        newNode->setNext(curr);
        _size++;
    }
}
void DoubleLinkedList::removeHead(){
    // Empty List
    if (this->isEmpty()){
        return;
    }
    // Single Node in List
    else if (_head == _tail){
        delete _head;
        _head = NULL;
        _tail = NULL;
    }
    // Multiple Nodes in list 
    else{
        Node * next = _head->getNext();
        delete _head;
        next->setPrev(NULL);
        _head = next;
    }

    _size --;
}
void DoubleLinkedList::removeTail(){
    // Empty List
    if (this->isEmpty()){
        return;
    }
    // Single Node in List
    else if (_head == _tail){
        delete _tail;
        _head = NULL;
        _tail = NULL;
    }
    // Multiple Nodes in List
    else{
        Node * prev = _tail->getPrev();
        delete _tail;
        prev->setNext(NULL);
        _tail = prev;
    }

    _size --;
}
void DoubleLinkedList::remove(int idx){
    // Input Cleansing
    if (idx < 0 || idx >= _size)
        throw out_of_range("Removal idx out of range.");

    // Remove from head
    if (idx == 0){
        removeHead();
    }
    // Remove from tail
    else if (idx == (_size-1)){
        removeTail();
    }
    // Remove from middle
    // i.e. idx element of [1, size-2]
    else{
        Node * curr = _head;
        Node * prev;
        Node * next;
        for (int i = 0; i < idx; i++){
            curr = curr->getNext();
        }
        prev = curr->getPrev();
        next = curr->getNext();
        prev->setNext(next);
        next->setPrev(prev);
        delete curr;
        _size --;
    }
}
void DoubleLinkedList::display(){
    stringstream ss;
    Node * curr = _head;
    while (curr != NULL){
        ss << "[" + to_string(curr->getData()) + "] -> ";
        curr = curr->getNext();
    }
    cout << ss.str() + "EOL\n";
}

Node * DoubleLinkedList::search(int data){
    Node * curr = _head;
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
    return ((_head == NULL) && (_tail == NULL));
}
#endif
