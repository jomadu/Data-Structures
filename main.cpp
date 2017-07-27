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


using namespace std;

void LLTest(){
    cout << "\nLinked List Test:\n";
    LinkedList list;
    /*
     Functions to test:
     append
     Empty
     1-Node
     2-Nodes
     prepend
     Empty
     1-Node
     2-Nodes
     insert (append, prepend, middle)
     Empty
     1-Node
     append
     prepend
     2-Nodes
     append
     insertMiddle
     prepend
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
    cout << "Testing append & removeTail:\n";
    list.append(0);
    list.display();
    list.removeTail();
    
    list.append(0);
    list.append(1);
    list.display();
    list.removeTail();
    list.removeTail();
    
    list.append(0);
    list.append(1);
    list.append(2);
    list.display();
    list.removeTail();
    list.removeTail();
    list.removeTail();
    
    cout << "Testing prepend & removeHead:\n";
    list.prepend(0);
    list.display();
    list.removeHead();
    
    list.prepend(1);
    list.prepend(0);
    list.display();
    list.removeHead();
    list.removeHead();
    
    list.prepend(2);
    list.prepend(1);
    list.prepend(0);
    list.display();
    list.removeHead();
    list.removeHead();
    list.removeHead();
    
    cout << "Testing insert:\n";
    list.insert(0,0);
    list.display();
    list.removeHead();
    
    list.append(1);
    list.insert(1,2);
    list.insert(0,0);
    list.display();
    list.removeHead();
    list.removeHead();
    list.removeHead();
    
    list.append(1);
    list.append(3);
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
    list.append(0);
    list.display();
    list.remove(0);
    list.display();
    
    list.append(0);
    list.append(1);
    list.append(2);
    list.display();
    list.remove(0);
    list.remove(1);
    list.display();
    list.removeHead();
    
    list.append(0);
    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);
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
     append
     Empty
     1-Node
     2-Nodes
     prepend
     Empty
     1-Node
     2-Nodes
     insert (append, prepend, middle)
     Empty
     1-Node
     append
     prepend
     2-Nodes
     append
     insertMiddle
     prepend
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
    cout << "Testing append & removeTail:\n";
    list.append(0);
    list.display();
    list.removeTail();
    
    list.append(0);
    list.append(1);
    list.display();
    list.removeTail();
    list.removeTail();
    
    list.append(0);
    list.append(1);
    list.append(2);
    list.display();
    list.removeTail();
    list.removeTail();
    list.removeTail();
    
    cout << "Testing prepend & removeHead:\n";
    list.prepend(0);
    list.display();
    list.removeHead();
    
    list.prepend(1);
    list.prepend(0);
    list.display();
    list.removeHead();
    list.removeHead();
    
    list.prepend(2);
    list.prepend(1);
    list.prepend(0);
    list.display();
    list.removeHead();
    list.removeHead();
    list.removeHead();
    
    cout << "Testing insert:\n";
    list.insert(0,0);
    list.display();
    list.removeHead();
    
    list.append(1);
    list.insert(1,2);
    list.insert(0,0);
    list.display();
    list.removeHead();
    list.removeHead();
    list.removeHead();
    
    list.append(1);
    list.append(3);
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
    list.append(0);
    list.display();
    list.remove(0);
    list.display();
    
    list.append(0);
    list.append(1);
    list.append(2);
    list.display();
    list.remove(0);
    list.remove(1);
    list.display();
    list.removeHead();
    
    list.append(0);
    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);
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
     append
        Empty
        1-Node
        2-Nodes
     prepend
        Empty
        1-Node
        2-Nodes
     insert (append, prepend, middle)
        Empty
        1-Node
            append
            prepend
        2-Nodes
            append
            insertMiddle
            prepend
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
    cout << "Testing append & removeTail:\n";
    list.append(0);
    list.display();
    list.removeTail();
    
    list.append(0);
    list.append(1);
    list.display();
    list.removeTail();
    list.removeTail();
    
    list.append(0);
    list.append(1);
    list.append(2);
    list.display();
    list.removeTail();
    list.removeTail();
    list.removeTail();
    
    cout << "Testing prepend & removeHead:\n";
    list.prepend(0);
    list.display();
    list.removeHead();
    
    list.prepend(1);
    list.prepend(0);
    list.display();
    list.removeHead();
    list.removeHead();
    
    list.prepend(2);
    list.prepend(1);
    list.prepend(0);
    list.display();
    list.removeHead();
    list.removeHead();
    list.removeHead();
    
    cout << "Testing insert:\n";
    list.insert(0,0);
    list.display();
    list.removeHead();
    
    list.append(1);
    list.insert(1,2);
    list.insert(0,0);
    list.display();
    list.removeHead();
    list.removeHead();
    list.removeHead();
    
    list.append(1);
    list.append(3);
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
    list.append(0);
    list.display();
    list.remove(0);
    list.display();
    
    list.append(0);
    list.append(1);
    list.append(2);
    list.display();
    list.remove(0);
    list.remove(1);
    list.display();
    list.removeHead();
    
    list.append(0);
    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);
    list.display();
    list.remove(2);
    list.remove(0);
    list.remove(2);
    list.display();
    list.removeHead();
    list.removeHead();
}

int main(){
    LLTest();
    DLLTest();
    CDLLTest();
}
