#include "repl.h"

void repl::create_bst(std::string name) {
  state.bst.emplace(name, new BST());
}

void repl::bst(std::vector<std::string> fields) {
  // fields            0      1      2
  // [datastructure] [name] insert [data]
  // [datastructure] [name] show   [display method]
  // [datastructure] [name] delete [data]
  if(fields.size() < 3) {
    std::cout << "Wrong command" << std::endl;
    return;
  }
  if(!state.bst.count(fields[0])) {
    std::cout << "Datastructure does not exist" << std::endl;
    return;
  }
  auto bst = state.bst[fields[0]];
  if(fields[1] == "insert") {
    // THIS TRY CATCH DOESNT WORK
    // NEED TO CHECK IF fields[2] is number
    // Right now it just fail and bail
    try {
      bst->insert(std::stoi(fields[2]));
      std::cout << fields[2] << " inserted" << std::endl;
    }
    catch(std::string err) {
      std::cout << "Could not convert " << fields[2] << std::endl;
    }
  }
  else if(fields[1] == "show") {
    if(fields[2] == "preorder")
      bst->preorder(bst->root);
    else if(fields[2] == "inorder")
      bst->inorder(bst->root);
    //bst->inorder_iterative(bst->root);
    else if(fields[2] == "postorder")
      bst->postorder(bst->root);
    else if(fields[2] == "height")
      std::cout << bst->height(bst->root) << std::endl;
    std::cout << std::endl;
  }
}

void repl::list_bst() {
  for(const auto& item : state.bst)
    std::cout << item.first << std::endl;
}
