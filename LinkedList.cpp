
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
    size = 0;
    head = NULL;
    tail = NULL;
}

// Destructor
LinkedList::~LinkedList(){
    Node * curr = head;
    Node * next = head;
    while (curr != NULL){
        next = curr->getNext();
        delete curr;
        curr = next;
    }
    head = NULL;
    tail = NULL;
}

// Gets
int LinkedList::getSize(){
    return size;
}

// Sets

// Helpers
int LinkedList::getData(int idx){
    Node * curr = head;
    
    if (idx < 0 || idx >= size)
        throw out_of_range("Data retrieval idx out of range.");
    
    for (int i = 0; i < idx; i++){
        curr = curr->getNext();
    }
    return curr->getData();
}
void LinkedList::setData(int idx, int d){
    Node * curr = head;
    
    if (idx < 0 || idx >= size)
        throw out_of_range("Data retrieval idx out of range.");
    
    for (int i = 0; i < idx; i++){
        curr = curr->getNext();
    }
    
    curr->setData(d);
}
void LinkedList::insertTail(int d){
    Node * newNode = new Node(d);

    if (this->isEmpty()){
        head = newNode;
        tail = newNode;
    }
    else{
        tail->setNext(newNode);
        tail = newNode;
    }           

    size++;
}
void LinkedList::insertHead(int d){
    Node * newNode = new Node(d);

    if (this->isEmpty()){
        head = newNode;
        tail = newNode;
    }
    else{
        newNode->setNext(head);
        head = newNode;
    }

    size++;
}
void LinkedList::insert(int idx, int d){
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
    // i.e. idx element of [1, size-1]
    else{
        Node * newNode = new Node(d);
        Node * curr = head;
        Node * prev = head;
        for (int i = 0; i < idx; i++){
            prev = curr;
            curr = curr->getNext();
        }
        prev->setNext(newNode);
        newNode->setNext(curr);
        size++;
    }

}
void LinkedList::removeHead(){
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
        head = second;
    }

    size --;
}
void LinkedList::removeTail(){
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
        Node * curr = head;
        Node * prev = head;
        while (curr->getNext() != NULL){
            prev = curr;
            curr = curr->getNext();        
        }
        delete curr;
        prev->setNext(NULL);
        tail = prev;
    }

    size --;
}
void LinkedList::remove(int idx){
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
    // i.e. idx element of [1, size-2]
    else{
        Node * curr = head;
        Node * prev = head;
        for (int i = 0; i < idx; i++){
            prev = curr;
            curr = curr->getNext();        
        }
        prev->setNext(curr->getNext());
        delete curr;
        size --;
    }
}
void LinkedList::display(){
    stringstream ss;
    Node * curr = head;
    while (curr != NULL){
        ss << "[" + to_string(curr->getData()) + "] -> ";
        curr = curr->getNext();
    }
    cout << ss.str() + "EOL\n";
}
Node * LinkedList::search(int d){

    Node * curr = head;
    while (curr != NULL){
        if (curr->getData() == d){
            return curr;
        }
        else{
            curr = curr->getNext();
        }
    }
    return NULL;
}

bool LinkedList::isEmpty(){
    return ((head == NULL) && (tail == NULL));
}

#endif
