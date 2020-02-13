# Data Structures in C++
Author: Max Dunn
## Description
I wanted to create a library of data structures in c++...so I did!
## Structures
### Node
Supports `LinkedList`, `DoubleLinkedList`, and `CircularDoubleLinkedList` objects.
#### Private Members
- `int data_`
- `Node * prev_`
- `Node * next_`
### TreeNode
Supports `BinarySearchTree` objects
#### Private Members
- `int data_`
- `TreeNode * parent_`
- `TreeNode * left_`
- `TreeNode * right_`
### Vertex
Supports `Graph` objects
#### Private Members
- `int key_`
- `int val_`
- `std::unordered_map<int, std::shared_ptr<Vertex>> nbrs`
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
- `LinkedList ll_`
### Queue
Queue implemented using `LinkedList`
#### Private Members
- `LinkedList ll_`
### Graph
Undirected graph implemented using `Vertex`
#### Private Members
- `std::unordered_map<int, std::shared_ptr<Vertex>> verticies_`
### BinarySearchTree
Binary Tree implemented using `TreeNode`
#### Private Members
- `TreeNode * root_`