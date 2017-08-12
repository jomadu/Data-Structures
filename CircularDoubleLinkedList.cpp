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
    size = 0;
    head = NULL;
    tail = NULL;
}

// Destructor
CircularDoubleLinkedList::~CircularDoubleLinkedList(){
    Node * curr = head;
    Node * next = head;
    for (int i = 0; i < size; i++){
        next = curr->getNext();
        delete curr;
        curr = next;
    }
    head = NULL;
    tail = NULL;
}

// Gets
int CircularDoubleLinkedList::getSize(){
    return size;
}

// Sets

// Helpers
int CircularDoubleLinkedList::getData(int idx){
    Node * curr = head;
    
    if (idx < 0 || idx >= size)
        throw out_of_range("Data retrieval idx out of range.");
    
    for (int i = 0; i < idx; i++){
        curr = curr->getNext();
    }
    
    return curr->getData();
}
void CircularDoubleLinkedList::setData(int idx, int d){
    Node * curr = head;
    
    if (idx < 0 || idx >= size)
        throw out_of_range("Data retrieval idx out of range.");
    
    for (int i = 0; i < idx; i++){
        curr = curr->getNext();
    }
    
    curr->setData(d);
}
void CircularDoubleLinkedList::insertTail(int d){
    Node * newNode = new Node(d);

    if (this->isEmpty()){
        head = newNode;
        tail = newNode;
    }
    else{
        newNode->setPrev(tail);
        newNode->setNext(head);
        tail->setNext(newNode);
        head->setPrev(newNode);
        tail = newNode;
    }

    size++;
}
void CircularDoubleLinkedList::insertHead(int d){
    Node * newNode = new Node(d);
    
    if (this->isEmpty()){
        head = newNode;
        tail = newNode;
        newNode->setNext(head);
        newNode->setPrev(head);
    }
    else{
        newNode->setNext(head);
        newNode->setPrev(tail);
        tail->setNext(newNode);
        head->setPrev(newNode);
        head = newNode;
    }

    size++;
}
void CircularDoubleLinkedList::insert(int idx, int d){
    // Input Cleansing
    if (idx < 0 || idx > size)
        throw out_of_range("Insertion idx out of range.");

    // Insert as a insertHead
    if (idx == 0){
        insertHead(d);
    }
    // Insert as an insertTail
    else if (idx == size){
        insertTail(d);
    }
    // Insert in the middle
    else{
        Node * newNode = new Node(d);
        Node * curr = head;
        Node * prev = head;
        for (int i = 0; i < idx; i++){
            prev = curr;
            curr = curr->getNext();
        }
        prev->setNext(newNode);
        newNode->setPrev(prev);
        curr->setPrev(newNode);
        newNode->setNext(curr);
        size++;
    }
}
void CircularDoubleLinkedList::removeHead(){
    // Empty List
    if (this->isEmpty()){
        return;
    }
    // Single Node in List
    else if (head == tail){
        delete head;
        head = NULL;
        tail = NULL;
    }
    // Multiple Nodes in list 
    else{
        Node * second = head->getNext();
        delete head;
        second->setPrev(tail);
        head = second;
    }

    size --;
}
void CircularDoubleLinkedList::removeTail(){
    // Empty List
    if (this->isEmpty()){
        return;
    }
    // Single Node in List
    else if (head == tail){
        delete tail;
        head = NULL;
        tail = NULL;
    }
    // Multiple Nodes in List
    else{
        Node * prev = tail->getPrev();
        delete tail;
        prev->setNext(head);
        tail = prev;
    }

    size --;
}

void CircularDoubleLinkedList::remove(int idx){
    // Input Cleansing
    if (idx < 0 || idx >= size)
        throw out_of_range("Removal idx out of range.");

    // Remove from head
    if (idx == 0){
        removeHead();
    }
    // Remove from tail
    else if (idx == (size-1)){
        removeTail();
    }
    // Remove from middle
    else{
        Node * curr = head;
        Node * prev = head;
        Node * next = head;
        for (int i = 0; i < idx; i++){
            prev = curr;
            curr = curr->getNext();        
        }
        next = curr->getNext();
        prev->setNext(next);
        next->setPrev(prev);
        delete curr;
        size --;
    }
}
void CircularDoubleLinkedList::display(){
    stringstream ss;
    Node * curr = head;
    for (int i = 0; i < size; i++){
        ss << "[" + to_string(curr->getData()) + "] -> ";
        curr = curr->getNext();
    }
    cout << ss.str() + "EOL\n";
}
Node * CircularDoubleLinkedList::search(int d){
    Node * curr = head;
    for (int i = 0; i < (size - 1); i++){
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
    return ((head == NULL) && (tail == NULL));
}

#endif
