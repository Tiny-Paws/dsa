# Tiny-Paws' DSA program

The DSA program is my way of exploring data structures such as
- Linked lists
- Binary trees
- Binary search trees
- Self balanced binary trees
## Objectives
I want this program to implement every data structure I mentioned above. The self balanced binary tree implementation I'm going to use is B-Tree.

The data structure should implement methods to interact with the dataset (searching, inserting etc...) and provide a way to visualize the data and its layout.

Visualizations I'm working on for BST are :
- In Order
- Pre Order
- Post Order
- Top View
- ASCII representation of the tree

As of today, only binary search trees are supported and not every visualization/operations are available.
## Using the software
### Requirements
In order to use the software, you will have to compile it as I do not provide binaries.

The software has been compiled and tested with :
- clang++ 10.0.0
- make 4.2.1
### Compiling
```bash
git clone https://github.com/Tiny-Paws/dsa.git
cd dsa/src
make
```
### Using
The purpose of this software is to create and interact with data structures.

To create a data structure, use the create command followed by its type and name.
```
create bst test
```
This will effectively create a binary search tree (bst) named test.

To list your bsts, use the command list bst
```
list bst
test
```

To insert data, you must use the bst command. Its syntax is like so
> bst [name] insert [data]

Where name is the name of the bst you created and data is an integer.
```
bst test insert 6
6 inserted
```
Lastly you can display your tree the way you like by using the bst command.
```
bst test show preorder
6
```

More visualizations and data structures to come !
