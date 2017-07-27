/****************************

DoubleLinkedList.cpp
-----------------------------
Author: Max Dunn 
Copyright © 2017 Max Dunn.
All rights reserved.

****************************/

#ifndef DoubleLinkedList_hpp
#define DoubleLinkedList_hpp

#include "DoubleLinkedList.hpp"

DoubleLinkedList::DoubleLinkedList(){
    size = 0;
    head = NULL;
    tail = NULL;
}

DoubleLinkedList::~DoubleLinkedList(){
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

void DoubleLinkedList::append(int d){
    Node * newNode = new Node();
    newNode->setData(d);

    if (head == NULL){
        head = newNode;
        tail = newNode;
    }
    else{
        tail->setNext(newNode);
        newNode->setPrev(tail);
        tail = newNode;
    }

    size++;
}

void DoubleLinkedList::prepend(int d){
    Node * newNode = new Node();
    newNode->setData(d);

    if (head == NULL){
        head = newNode;
        tail = newNode;
    }
    else{
        newNode->setNext(head);
        head->setPrev(newNode);
        head = newNode;
    }

    size++;
}

void DoubleLinkedList::insert(int idx, int d){
    // Input Cleansing
    if (idx < 0 || idx > size)
        throw out_of_range("Insertion idx out of range.");

    // Insert as a prepend
    if (idx == 0){
        prepend(d);
    }
    // Insert as an append
    else if (idx == size){
        append(d);
    }
    // Insert in the middle
    else{
        Node * newNode = new Node();
        newNode->setData(d);
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

void DoubleLinkedList::removeHead(){
    // Empty List
    if (head == NULL){
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
        Node * next = head->getNext();
        delete head;
        next->setPrev(NULL);
        head = next;
    }

    size --;
}

void DoubleLinkedList::removeTail(){
    // Empty List
    if (head == NULL){
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
        prev->setNext(NULL);
        tail = prev;
    }

    size --;
}

void DoubleLinkedList::remove(int idx){
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

void DoubleLinkedList::display(){
    stringstream ss;
    Node * curr = head;
    while (curr != NULL){
        ss << "[" + to_string(curr->getData()) + "] -> ";
        curr = curr->getNext();
    }
    cout << ss.str() + "EOL\n";
}

Node * DoubleLinkedList::search(int d){
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

#endif
