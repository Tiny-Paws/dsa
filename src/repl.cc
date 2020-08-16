#include "repl.h"

void repl::run() {
  std::cout << "RUNNING REPL" << std::endl;
  std::string command;

  while(command != "q") {
    std::getline(std::cin, command);
    std::istringstream ss(command);
    std::vector<std::string> fields(std::istream_iterator<std::string>{ss},
                                    std::istream_iterator<std::string>());
    if(fields.size() < 1)
      continue;
    if(fields[0] == "list")
      list(std::vector<std::string>(fields.cbegin()+1, fields.cend()))();
    else if(fields[0] == "create")
      create(std::vector<std::string>(fields.cbegin()+1, fields.cend()));
    else if(fields[0] == "bst")
      bst(std::vector<std::string>(fields.cbegin()+1, fields.cend()));
  }
}

decltype(*repl::list_bst) repl::list(std::vector<std::string> fields) {
  auto err = [](){std::cout << "Wrong command" << std::endl;};
  if(fields.size() < 1)
    return *err;

  if(fields[0] == "bst")
    return *list_bst;

  return *err;
}

void repl::list_bst() {
  for(const auto& item : state.bst)
    std::cout << item.first << std::endl;
}

void repl::create(std::vector<std::string> fields) {
  if(fields.size() < 2) {
    std::cout << "Wrong command" << std::endl;
    return;
  }

  if(fields[0] == "bst")
    create_bst(fields[1]);
}

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
    else if(fields[2] == "height")
      std::cout << bst->height(bst->root) << std::endl;
  }
}