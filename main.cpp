//
//  main.cpp
//  Test
//
//  Created by Max Dunn on 7/26/17.
//  Copyright © 2017 Max Dunn. All rights reserved.
//

#include <iostream>
#include "LinkedList.hpp"
#include "DoubleLinkedList.hpp"
#include "CircularDoubleLinkedList.hpp"
#include "Graph.hpp"
#include "BTree.hpp"

using namespace std;

void LLTest(){
    cout << "\nLinked List Test:\n";
    LinkedList list;
    /*
     Functions to test:
     insertTail
     Empty
     1-Node
     2-Nodes
     insertHead
     Empty
     1-Node
     2-Nodes
     insert (insertTail, insertHead, middle)
     Empty
     1-Node
     insertTail
     insertHead
     2-Nodes
     insertTail
     insertMiddle
     insertHead
     removeHead
     Empty
     1-Node
     2-Nodes
     removeTail
     Empty
     1-Node
     2-Nodes
     remove (head, tail, middle)
     Empty
     1-Node
     removeHead
     removeTail
     2-Nodes
     removeMiddle
     removeHead
     removeTail
     */
    cout << "Testing insertTail & removeTail:\n";
    list.insertTail(0);
    list.display();
    list.removeTail();
    
    list.insertTail(0);
    list.insertTail(1);
    list.display();
    list.removeTail();
    list.removeTail();
    
    list.insertTail(0);
    list.insertTail(1);
    list.insertTail(2);
    list.display();
    list.removeTail();
    list.removeTail();
    list.removeTail();
    
    cout << "Testing insertHead & removeHead:\n";
    list.insertHead(0);
    list.display();
    list.removeHead();
    
    list.insertHead(1);
    list.insertHead(0);
    list.display();
    list.removeHead();
    list.removeHead();
    
    list.insertHead(2);
    list.insertHead(1);
    list.insertHead(0);
    list.display();
    list.removeHead();
    list.removeHead();
    list.removeHead();
    
    cout << "Testing insert:\n";
    list.insert(0,0);
    list.display();
    list.removeHead();
    
    list.insertTail(1);
    list.insert(1,2);
    list.insert(0,0);
    list.display();
    list.removeHead();
    list.removeHead();
    list.removeHead();
    
    list.insertTail(1);
    list.insertTail(3);
    list.insert(2,4);
    list.insert(0,0);
    list.insert(2,2);
    list.display();
    list.removeHead();
    list.removeHead();
    list.removeHead();
    list.removeHead();
    list.removeHead();
    
    cout << "Testing remove:\n";
    list.insertTail(0);
    list.display();
    list.remove(0);
    list.display();
    
    list.insertTail(0);
    list.insertTail(1);
    list.insertTail(2);
    list.display();
    list.remove(0);
    list.remove(1);
    list.display();
    list.removeHead();
    
    list.insertTail(0);
    list.insertTail(1);
    list.insertTail(2);
    list.insertTail(3);
    list.insertTail(4);
    list.display();
    list.remove(2);
    list.remove(0);
    list.remove(2);
    list.display();
    list.removeHead();
    list.removeHead();
}
void DLLTest(){
    cout << "\nDouble Linked List Test:\n";
    DoubleLinkedList list;
    /*
     Functions to test:
     insertTail
     Empty
     1-Node
     2-Nodes
     insertHead
     Empty
     1-Node
     2-Nodes
     insert (insertTail, insertHead, middle)
     Empty
     1-Node
     insertTail
     insertHead
     2-Nodes
     insertTail
     insertMiddle
     insertHead
     removeHead
     Empty
     1-Node
     2-Nodes
     removeTail
     Empty
     1-Node
     2-Nodes
     remove (head, tail, middle)
     Empty
     1-Node
     removeHead
     removeTail
     2-Nodes
     removeMiddle
     removeHead
     removeTail
     */
    cout << "Testing insertTail & removeTail:\n";
    list.insertTail(0);
    list.display();
    list.removeTail();
    
    list.insertTail(0);
    list.insertTail(1);
    list.display();
    list.removeTail();
    list.removeTail();
    
    list.insertTail(0);
    list.insertTail(1);
    list.insertTail(2);
    list.display();
    list.removeTail();
    list.removeTail();
    list.removeTail();
    
    cout << "Testing insertHead & removeHead:\n";
    list.insertHead(0);
    list.display();
    list.removeHead();
    
    list.insertHead(1);
    list.insertHead(0);
    list.display();
    list.removeHead();
    list.removeHead();
    
    list.insertHead(2);
    list.insertHead(1);
    list.insertHead(0);
    list.display();
    list.removeHead();
    list.removeHead();
    list.removeHead();
    
    cout << "Testing insert:\n";
    list.insert(0,0);
    list.display();
    list.removeHead();
    
    list.insertTail(1);
    list.insert(1,2);
    list.insert(0,0);
    list.display();
    list.removeHead();
    list.removeHead();
    list.removeHead();
    
    list.insertTail(1);
    list.insertTail(3);
    list.insert(2,4);
    list.insert(0,0);
    list.insert(2,2);
    list.display();
    list.removeHead();
    list.removeHead();
    list.removeHead();
    list.removeHead();
    list.removeHead();
    
    cout << "Testing remove:\n";
    list.insertTail(0);
    list.display();
    list.remove(0);
    list.display();
    
    list.insertTail(0);
    list.insertTail(1);
    list.insertTail(2);
    list.display();
    list.remove(0);
    list.remove(1);
    list.display();
    list.removeHead();
    
    list.insertTail(0);
    list.insertTail(1);
    list.insertTail(2);
    list.insertTail(3);
    list.insertTail(4);
    list.display();
    list.remove(2);
    list.remove(0);
    list.remove(2);
    list.display();
    list.removeHead();
    list.removeHead();
}
void CDLLTest(){
    cout << "\nCircular Double Linked List Test:\n";
    CircularDoubleLinkedList list;
    /*
     Functions to test:
     insertTail
        Empty
        1-Node
        2-Nodes
     insertHead
        Empty
        1-Node
        2-Nodes
     insert (insertTail, insertHead, middle)
        Empty
        1-Node
            insertTail
            insertHead
        2-Nodes
            insertTail
            insertMiddle
            insertHead
     removeHead
        Empty
        1-Node
        2-Nodes
     removeTail
        Empty
        1-Node
        2-Nodes
     remove (head, tail, middle)
        Empty
        1-Node
            removeHead
            removeTail
        2-Nodes
            removeMiddle
            removeHead
            removeTail
    */
    cout << "Testing insertTail & removeTail:\n";
    list.insertTail(0);
    list.display();
    list.removeTail();
    
    list.insertTail(0);
    list.insertTail(1);
    list.display();
    list.removeTail();
    list.removeTail();
    
    list.insertTail(0);
    list.insertTail(1);
    list.insertTail(2);
    list.display();
    list.removeTail();
    list.removeTail();
    list.removeTail();
    
    cout << "Testing insertHead & removeHead:\n";
    list.insertHead(0);
    list.display();
    list.removeHead();
    
    list.insertHead(1);
    list.insertHead(0);
    list.display();
    list.removeHead();
    list.removeHead();
    
    list.insertHead(2);
    list.insertHead(1);
    list.insertHead(0);
    list.display();
    list.removeHead();
    list.removeHead();
    list.removeHead();
    
    cout << "Testing insert:\n";
    list.insert(0,0);
    list.display();
    list.removeHead();
    
    list.insertTail(1);
    list.insert(1,2);
    list.insert(0,0);
    list.display();
    list.removeHead();
    list.removeHead();
    list.removeHead();
    
    list.insertTail(1);
    list.insertTail(3);
    list.insert(2,4);
    list.insert(0,0);
    list.insert(2,2);
    list.display();
    list.removeHead();
    list.removeHead();
    list.removeHead();
    list.removeHead();
    list.removeHead();

    cout << "Testing remove:\n";
    list.insertTail(0);
    list.display();
    list.remove(0);
    list.display();
    
    list.insertTail(0);
    list.insertTail(1);
    list.insertTail(2);
    list.display();
    list.remove(0);
    list.remove(1);
    list.display();
    list.removeHead();
    
    list.insertTail(0);
    list.insertTail(1);
    list.insertTail(2);
    list.insertTail(3);
    list.insertTail(4);
    list.display();
    list.remove(2);
    list.remove(0);
    list.remove(2);
    list.display();
    list.removeHead();
    list.removeHead();
}
void graphTest(){
    cout << "\nGraph Test:\n";
    Graph graph;
    
}

void TreeTest(){
    BTree tree;
    tree.insert(10);
    tree.insert(11);
    tree.insert(8);
    tree.insert(9);
    tree.display(tree.getRoot());
    tree.remove(9);
    tree.display(tree.getRoot());
    tree.insert(9);
    tree.remove(8);
    tree.display(tree.getRoot());
}

int main(){
    //LLTest();
    //DLLTest();
    //CDLLTest();
    TreeTest();
}
