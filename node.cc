#include "node.h"

Node::Node(int data) {
  this->data = data;
  this->right = this->left = nullptr;
}

Node::~Node() {
  delete this->left;
  delete this->right;
}
