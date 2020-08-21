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
  void run();
  void list_everything();
  void list_bst();
  void list_linkedlist();
  void create_bst(std::string);
  void create_linkedlist(std::string);
  decltype(*list_bst) list(std::vector<std::string>);
  void create(std::vector<std::string>);
  void bst(std::vector<std::string>);
  void linkedlist(std::vector<std::string>);
}
