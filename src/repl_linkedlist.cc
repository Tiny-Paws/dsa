#include "repl.h"

void repl::list_linkedlist() {
  for(const auto& item : state.linkedlist)
    std::cout << item.first << std::endl;
}

void repl::create_linkedlist(std::string name) {
  state.linkedlist.emplace(name, new LinkedList());
}

void repl::linkedlist(std::vector<std::string> fields) {
  // fields            0      1      2
  // [datastructure] [name] insert [data]
  // [datastructure] [name] show   [display method]
  // [datastructure] [name] delete [data]
  if(fields.size() < 3) {
    std::cout << "Wrong command" << std::endl;
    return;
  }
  if(!state.linkedlist.count(fields[0])) {
    std::cout << "Datastructure does not exist" << std::endl;
    return;
  }
  auto linkedlist = state.linkedlist[fields[0]];
  if(fields[1] == "insert") // NEED A TRY CATCH
    linkedlist->insert(std::stoi(fields[2]));
  else if(fields[1] == "show")
    linkedlist->show_ordered();
}
