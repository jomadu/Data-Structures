
/****************************

LinkedList.cpp
-----------------------------
Author: Max Dunn 
Copyright © 2017 Max Dunn.
All rights reserved.

****************************/

#ifndef LinkedList_hpp
#define LinkedList_hpp

#include "LinkedList.hpp"

LinkedList::LinkedList(){
    size = 0;
    head = NULL;
    tail = NULL;
}

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

void LinkedList::append(int d){
    Node * newNode = new Node();
    newNode->setData(d);

    if (head == NULL){
        head = newNode;
        tail = newNode;
    }
    else{
        tail->setNext(newNode);
        tail = newNode;
    }           

    size++;
}

void LinkedList::prepend(int d){
    Node * newNode = new Node();
    newNode->setData(d);

    if (head == NULL){
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
        newNode->setNext(curr);
        size++;
    }

}

void LinkedList::removeHead(){
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
        head = next;
    }

    size --;
}

void LinkedList::removeTail(){
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

#endif
