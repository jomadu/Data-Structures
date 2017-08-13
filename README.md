# Data Structures in C++
Author: Max Dunn
## Description
I wanted to create a library of data structures in c++...so I did!
## Structures
### Node
Supports `LinkedList`, `DoubleLinkedList`, and `CircularDoubleLinkedList` objects.
#### Private Members
- `int _data`
- `Node * _prev`
- `Node * _next`
### TreeNode
Supports `BTree` objects
#### Private Members
- `int _data`
- `TreeNode * _parent`
- `TreeNode * _left`
- `TreeNode * _right`
### Vertex
Supports `Graph` objects
#### Private Members
- `int _key
- `int _val'
- `unordered_map<int, Vertex *> nbrs'
### LinkedList
Singly Linked List implemented using `Node`
#### Private Members
- `int size`
- `Node * head`
- `Node * tail`
### DoubleLinkedList
Doubly Linked List implemented using `Node`
#### Private Members
- `int size`
- `Node * head`
- `Node * tail`
### CircularDoubleLinkedList
Doubly Linked List implemented using `Node`
#### Private Members
- `int size`
- `Node * head`
- `Node * tail`
### Stack
Stack implemented using `LinkedList`
#### Private Members
- `LinkedList _ll`
### Queue
Queue implemented using `LinkedList`
#### Private Members
- `LinkedList _ll`
### Graph
Undirected graph implemented using `Vertex`
#### Private Members
- `unordered_map<int, Vertex *> _vertices`
### BTree
Binary Tree implemented using `TreeNode`
#### Private Members
- `TreeNode * _root`