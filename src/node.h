#pragma once

struct Node {
  int data;
  Node* left;
  Node* right;

  Node(int);
  ~Node();
};
