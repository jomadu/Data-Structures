/****************************

CircularCircularDoubleLinkedList.cpp
-----------------------------
Author: Max Dunn 
Copyright © 2017 Max Dunn.
All rights reserved.

****************************/

#ifndef CircularDoubleLinkedList_hpp
#define CircularDoubleLinkedList_hpp

#include "CircularDoubleLinkedList.hpp"

CircularDoubleLinkedList::CircularDoubleLinkedList(){
    size = 0;
    head = NULL;
    tail = NULL;
}

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

int CircularDoubleLinkedList::getSize(){
    return size;
}

void CircularDoubleLinkedList::append(int d){
    Node * newNode = new Node();
    newNode->setData(d);

    if (head == NULL){
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

void CircularDoubleLinkedList::prepend(int d){
    Node * newNode = new Node();
    newNode->setData(d);

    if (head == NULL){
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

void CircularDoubleLinkedList::removeHead(){
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
        next->setPrev(tail);
        head = next;
    }

    size --;
}

void CircularDoubleLinkedList::removeTail(){
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

#endif
