#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <iterator>
#include <sstream>
#include "bst.h"

namespace repl {
  struct {
    std::unordered_map<std::string, BST*> bst;
  } state;
  void run();
  void list_bst();
  void create_bst(std::string);
  decltype(*list_bst) list(std::vector<std::string>);
  void create(std::vector<std::string>);
  void bst(std::vector<std::string>);
}
