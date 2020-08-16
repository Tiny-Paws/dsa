#include "linkedlist.h"

SinglyLinkedListNode* LinkedList::insert(SinglyLinkedListNode* node, int data) {
  if(!node)
    return new SinglyLinkedListNode(data);
  return insert(node->next, data);
}

void LinkedList::insert(int data) {
  insert(this->head, data);
}
