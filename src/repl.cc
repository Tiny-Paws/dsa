#include "repl.h"

void repl::run() {
  std::string command;

  while(command != "q") {
    std::cout << "> ";
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
    else if(fields[0] == "linkedlist")
      linkedlist(std::vector<std::string>(fields.cbegin()+1, fields.cend()));
  }
}

// Very ugly way of doing things
// Must be changed
// Must have a list_container<T>(std::string prefix)
decltype(*repl::list_bst) repl::list(std::vector<std::string> fields) {
  if(fields.size() < 1)
    return *list_everything;

  if(fields[0] == "bst")
    return *list_bst;
  else if(fields[0] == "linkedlist")
    return *list_linkedlist;
}

void repl::list_everything() {
  if(!state.linkedlist.empty()) {
    std::cout << "Linked List :" << std::endl;
    for(const auto& item : state.linkedlist)
      std::cout << "\t" << item.first << std::endl;
  }
}

void repl::create(std::vector<std::string> fields) {
  if(fields.size() < 2) {
    std::cout << "Wrong command" << std::endl;
    return;
  }

  if(fields[0] == "bst")
    create_bst(fields[1]);
  else if(fields[0] == "linkedlist")
    create_linkedlist(fields[1]);
}
