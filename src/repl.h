#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <iterator>
#include <sstream>
#include "bst.h"
#include "linkedlist.h"

namespace repl {
  struct {
    std::unordered_map<std::string, BST*> bst;
    std::unordered_map<std::string, LinkedList*> linkedlist;
  } state;
  // Repl
  void list_bst(); // Needed in order to satisfy decltype
  void run();
  void list_everything();
  decltype(*repl::list_bst) list(std::vector<std::string>); // must get rid of this
  void create(std::vector<std::string>);

  // Bst related methods
  void create_bst(std::string);
  void bst(std::vector<std::string>);
  // void list_bst();

  // LinkedList related methods
  void list_linkedlist();
  void create_linkedlist(std::string);
  void linkedlist(std::vector<std::string>);
}
