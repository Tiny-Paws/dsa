#include "bst.h"

int BST::height(Node* node) {
  if(!node)
    return 0;
  auto lheight = height(node->left);
  auto rheight = height(node->right);

  if(lheight > rheight)
    return 1 + lheight;
  return 1 + rheight;
}

void BST::insert(int data) {
  this->root = this->insert(this->root, data);
}

Node* BST::insert(Node* node, int data) {
  if(!node)
    return new Node(data);
  if(data < node->data)
    node->left = insert(node->left, data);
  else if(data > node->data)
    node->right = insert(node->right, data);
  return node;
}

void BST::preorder(Node* node) {
  if(!node)
    return;
  std::cout << node->data << " ";
  this->preorder(node->left);
  this->preorder(node->right);
}

void BST::inorder(Node* node) {
  if(!node)
    return;
  this->inorder(node->left);
  std::cout << node->data << " ";
  this->inorder(node->right);
}

void BST::inorder_iterative(Node* node) {
  if(!node)
    return;

  auto curr = node;
  std::stack<Node*> stack;

  while(curr || !stack.empty()) {
    while(curr) {
      stack.push(curr);
      curr = curr->left;
    }

    curr = stack.top();
    stack.pop();
    std::cout << curr->data << " ";
    curr = curr->right;
  }
}

void BST::postorder(Node* node) {
  if(!node)
    return;
  this->postorder(node->right);
  this->postorder(node->left);
  std::cout << node->data << " ";
}

void BST::tree_view() {
  auto height = this->height(this->root);
  //        Reverse depth
  //            root               depth 3
  //        child    child         depth 2
  //     child  child     child    depth 1
  //
  // used to calculate the branch sizes of the tree
  auto depth_multiplier = height-1;

  // offset from the edge of the screen
  auto wall_offset = [depth_multiplier]() {
                  int rs(0);
                  for(auto h=depth_multiplier; h > 0; --h)
                    rs += h*2;
                  return rs;
                }();

  // offset+1 for the root element only
  // to prevent overriding values
  auto offset = (depth_multiplier*2) + 1;

  std::cout << "Height" << depth_multiplier << std::endl;
  std::cout << "offset" << offset << std::endl;
  std::cout << "wall" << wall_offset << std::endl;
  for(auto i=0; i < wall_offset-offset; ++i)
    std::cout << " ";

  for(auto i=0; i < offset+1; ++i) {
    if(i==0)
      std::cout << "+";
    else
      std::cout << "-";
  }
  std::cout << root->data;
  for(auto i=0; i < offset+1; ++i) {
    if(i==offset)
      std::cout << "+";
    else
      std::cout << "-";
  }
  std::cout << std::endl;

  tree_view(this->root->left, wall_offset-offset, depth_multiplier-1);
}

// WONT WORK WITH 2 DIGITS NUMBERS
void BST::tree_view(Node* node, int node_offset, int depth_multiplier) {
  for(auto i=0; i < node_offset; ++i)
    std::cout << " ";
  std::cout << node->data;
}
