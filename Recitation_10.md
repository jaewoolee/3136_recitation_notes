# Recitation 10 #

## Trees ##

### What's a tree? ###
A tree is a data structure with a set of linked nodes in a hierarchical tree-like structure.

### What are the parts of a tree? ###
The root of a tree is the top most node on the tree (Think of it like an upside down real tree).
Two nodes can be related to each other as "parent" and "child" nodes.  The parent node "points" to the child node.
In a graphical represenatation of a tree, the parent is on top of the child.
The leaves of the tree are the nodes that don't have any children. (If the tree consists of one node, that node is both a root and a leaf!)
A "subtree" is a tree whose root is one of the children of a the node the subtree is being compared to.

### Branching Factor ###
The branching factor is the number of children at each non-leaf node. Think of it as the average fertility of a node (how many children it makes).
This number is not always uniform and so the average branching factor is calculated.

### What's a linked list? ###
We worked a lot with linked lists in HW2.  Is a linked list a type of tree?
Yes!  A linked list is a tree with a branching factor of 1!

## Binary Trees ##

### What's a binary tree? ###
A binary tree is a tree in which every node has at most two children.

### Some more vocab ###
```
Directed edge: link from parent to child.
Depth(of a node): The length of the path from the root to a given node.
Level: The set of all nodes at a given depth.
Depth(of a tree): The depth of the deepest node.  Also called height.
Siblings: Nodes that share the same parent.
Size(of a node): Number of descendants it has including itself.
```
### Types of Binary Trees ###
Let's see what different types of binary trees look like in the wild.
```
Full Binary Tree: Every node other than the leaves has 2 children.
Complete Binary Tree: Every level is completely filled except for possibly the last.
Perfect Binary Tree: Full and all leaves are at the same level.
Balanced Binary Tree: The depth of the left and right subtrees of every node differ by one or less.
Degenerate Tree: Is a tree where for each parent node, there is only one associated child node. (Performs like a linked list).
```
### Performance of Binary Trees ###
When we don't know the properties of a binary tree, performance can be poor in the worst case. 
```
Note that in the following, n is the number of nodes in the tree.
space: O(n)
search(Node n): O(n) 
delete(Node n): O(n)
insert(Node n): O(n)
print_tree: O(n)
```

## Binary Search Trees ##

### What's a binary search tree? ###
A binary search tree (BST) is a binary tree where the left subtree contains all values less than the node,
the right subtree contains values greater than the node for all nodes and there are no duplicate nodes.

### Performance Measure ###
We still don't know if the tree full/complete/perfect, so in the worst case, performance is still poor. Why? Because a binary tree could just be a linked list which we means we can't take advantage of the binary search capabilities.
```
space: O(n)
search(Node n): O(n) 
delete(Node n): O(n)
insert(Node n): O(n)
print_tree: O(n)
```
However, if our tree is rougly balanced (and not just a linked list) then we get very good runtimes O(logn). This is what happens on average.
```
space: O(n)
search(Node n): O(logn) 
delete(Node n): O(logn)
insert(Node n): O(logn)
print_tree: O(n)
```

## Traversals ##

### Types of traversals ###
Two general types of traversals: Depth First and Breadth first. In breadth first, we explore nodes by level.  We care more about depth first, where we explore nodes by depth.

### Depth First Traversal Methods ###
Here's what the different depth order traversal methods look like.
```
Pre-order: visit root, traverse left subtree, then traverse right subtree.
In-order: traverse left subtree, visit root, then traverse right subtree.
Post-order: traverse left subtree, then traverse right subtree, and then finally visit the root.
```
Confused? Maybe some animation will help. Go to https://www.khanacademy.org/cs/depth-first-traversals-of-binary-trees/934024358 for and watch the respective animations for pre-order, in-order, and post-order traversal.
