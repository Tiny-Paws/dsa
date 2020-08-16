#include <iostream>
#include "repl.h"

auto main(void) -> int {
  //repl::run();
  auto bst = BST();
  bst.insert(20);
  bst.insert(10);
  bst.insert(30);
  bst.insert(5);
  bst.insert(15);
  bst.insert(25);
  bst.insert(35);
  bst.insert(3);
  bst.insert(7);
  bst.insert(13);
  bst.insert(17);
  bst.insert(23);
  bst.insert(27);
  bst.insert(33);
  bst.insert(37);
  bst.tree_view();
}
