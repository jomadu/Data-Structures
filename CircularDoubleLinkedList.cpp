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
    _size = 0;
    _head = NULL;
    _tail = NULL;
}

// Destructor
CircularDoubleLinkedList::~CircularDoubleLinkedList(){
    Node * curr = _head;
    Node * next = _head;
    for (int i = 0; i < _size; i++){
        next = curr->getNext();
        delete curr;
        curr = next;
    }
    _head = NULL;
    _tail = NULL;
}

// Gets
int CircularDoubleLinkedList::getSize(){
    return _size;
}

// Sets

// Helpers
int CircularDoubleLinkedList::getData(int idx){
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
void CircularDoubleLinkedList::setData(int idx, int d){
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
    return curr->setData(data);
}
void CircularDoubleLinkedList::append(int data){
    Node * newNode = new Node(data);

    if (this->isEmpty()){
        _head = newNode;
        _tail = newNode;
    }
    else{
        newNode->setPrev(_tail);
        newNode->setNext(_head);
        _tail->setNext(newNode);
        _head->setPrev(newNode);
        _tail = newNode;
    }

    _size++;
}
void CircularDoubleLinkedList::prepend(int data){
    Node * newNode = new Node(data);
    
    if (this->isEmpty()){
        _head = newNode;
        _tail = newNode;
        newNode->setNext(_head);
        newNode->setPrev(_head);
    }
    else{
        newNode->setNext(_head);
        newNode->setPrev(_tail);
        _tail->setNext(newNode);
        _head->setPrev(newNode);
        _head = newNode;
    }

    _size++;
}
void CircularDoubleLinkedList::insert(int idx, int data){
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
        }
        else{
            curr = _tail;
            for (int i = _size; i >= idx; i--){
                curr = curr->getPrev();
            }
        }
        prev = curr->getPrev();
        
        prev->setNext(newNode);
        newNode->setPrev(prev);
        curr->setPrev(newNode);
        newNode->setNext(curr);
        _size++;
    }
}
void CircularDoubleLinkedList::removeHead(){
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
        Node * second = _head->getNext();
        delete _head;
        second->setPrev(_tail);
        _tail->setNext(second);
        _head = second;
    }

    _size --;
}
void CircularDoubleLinkedList::removeTail(){
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
        prev->setNext(_head);
        _head->setNext(prev);
        _tail = prev;
    }

    _size --;
}

void CircularDoubleLinkedList::remove(int idx){
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
    else{
        Node * curr = _head;
        Node * prev;
        Node * next;
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
        prev = curr->getPrev();
        next = curr->getNext();
        
        prev->setNext(next);
        next->setPrev(prev);
        delete curr;
        _size --;
    }
}
void CircularDoubleLinkedList::display(){
    stringstream ss;
    Node * curr = _head;
    for (int i = 0; i < _size; i++){
        ss << "[" + to_string(curr->getData()) + "] -> ";
        curr = curr->getNext();
    }
    cout << ss.str() + "EOL\n";
}
Node * CircularDoubleLinkedList::search(int d){
    Node * curr = _head;
    for (int i = 0; i < (_size - 1); i++){
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
    return ((_head == NULL) && (_tail == NULL));
}

#endif
