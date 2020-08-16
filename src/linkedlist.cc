#include "linkedlist.h"

SinglyLinkedListNode* LinkedList::insert(SinglyLinkedListNode* node, int data) {
  if(!node)
    return new SinglyLinkedListNode(data);
  return insert(node->next, data);
}

void LinkedList::insert(int data) {
  // DOESNT WORK - TO FIX
  insert(this->head, data);
  std::cout << data << " inserted" << std::endl;
}

void LinkedList::show_ordered() {
  auto curr = this->head;
  while(curr) {
    std::cout << curr->data << " ";
    curr = curr->next;
  }
  std::cout << std::endl;
}
