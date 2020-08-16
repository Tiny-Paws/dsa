#pragma once

#include <iostream>
#include "node.h"

struct BST {
  Node* root;
  BST() {}
  BST(int data) : root(new Node(data)) {}
  ~BST() {
    delete this->root;
  }
  int height(Node* ); // REPL missing
  void insert(int);
  void preorder(Node*);
  void inorder(Node*);
  void postorder(Node*);
  void tree_view();

private:
  Node* insert(Node*, int);
  void tree_view(Node*, int, int);
};
