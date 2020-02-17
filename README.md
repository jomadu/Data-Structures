# Data Structures in C++
Author: Max Dunn
## Description
I wanted to create a library of data structures in c++...so I did!

|Class|Inherits|Inherited By|Used By|
|-|-|-|-|
|`Node`||`LinkedListNode`, `TreeNode`|`LinkedList`, `DoubleLinkedList`, `CircularDoubleLinkedList`, `BinarySearchTree`|
|`LinkedListNode`|`Node`||`LinkedList`, `DoubleLinkedList`, `CircularDoubleLinkedList`|
|`TreeNode`|`Node`||`BinarySearchTree`|
|`Vertex`|||`Graph`|
|`LinkedList`||`DoubleLinkedList`, `CircularDoubleLinkedList`|`Queue`, `Stack`|
|`DoubleLinkedList`|`LinkedList`|
|`CircularDoubleLinkedList`|`LinkedList`|
|`Queue`|
|`Stack`|
|`Graph`|