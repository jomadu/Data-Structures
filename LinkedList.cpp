
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
    _size = 0;
    _head = NULL;
    _tail = NULL;
}

// Destructor
LinkedList::~LinkedList(){
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
int LinkedList::getSize(){
    return _size;
}

// Sets

// Helpers
int LinkedList::getData(int idx){
    Node * curr = _head;
    
    if (idx < 0 || idx >= _size)
        throw out_of_range("Data retrieval idx out of range.");
    
    for (int i = 0; i < idx; i++){
        curr = curr->getNext();
    }
    return curr->getData();
}
void LinkedList::setData(int idx, int data){
    Node * curr = _head;
    
    if (idx < 0 || idx >= _size)
        throw out_of_range("Data retrieval idx out of range.");
    
    for (int i = 0; i < idx; i++){
        curr = curr->getNext();
    }
    
    curr->setData(data);
}
void LinkedList::append(int data){
    Node * newNode = new Node(data);

    if (this->isEmpty()){
        _head = newNode;
        _tail = newNode;
    }
    else{
        _tail->setNext(newNode);
        _tail = newNode;
    }           

    _size++;
}
void LinkedList::prepend(int data){
    Node * newNode = new Node(data);

    if (this->isEmpty()){
        _head = newNode;
        _tail = newNode;
    }
    else{
        newNode->setNext(_head);
        _head = newNode;
    }

    _size++;
}
void LinkedList::insert(int idx, int data){
    // Input Cleansing
    if (idx < 0 || idx > _size)
        throw out_of_range("Insertion idx out of range.");

    // Insert as a insertHead
    if (idx == 0){
        prepend(data);
    }
    
    // Insert as an insertTail (really append)
    else if (idx == _size){
        append(data);
    }
    
    // Insert in the middle
    // i.e. idx element of [1, size-1]
    else{
        Node * newNode = new Node(data);
        Node * curr = _head;
        Node * prev = _head;
        for (int i = 0; i < idx; i++){
            prev = curr;
            curr = curr->getNext();
        }
        prev->setNext(newNode);
        newNode->setNext(curr);
        _size++;
    }

}
void LinkedList::removeHead(){
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
        _head = second;
    }

    _size --;
}
void LinkedList::removeTail(){
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
        Node * curr = _head;
        Node * prev = _head;
        while (curr->getNext() != NULL){
            prev = curr;
            curr = curr->getNext();        
        }
        delete curr;
        prev->setNext(NULL);
        _tail = prev;
    }

    _size --;
}
void LinkedList::remove(int idx){
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
        Node * prev = _head;
        for (int i = 0; i < idx; i++){
            prev = curr;
            curr = curr->getNext();        
        }
        prev->setNext(curr->getNext());
        delete curr;
        _size --;
    }
}
void LinkedList::display(){
    stringstream ss;
    Node * curr = _head;
    while (curr != NULL){
        ss << "[" + to_string(curr->getData()) + "] -> ";
        curr = curr->getNext();
    }
    cout << ss.str() + "EOL\n";
}
Node * LinkedList::search(int data){

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

bool LinkedList::isEmpty(){
    return ((_head == NULL) && (_tail == NULL));
}

#endif
