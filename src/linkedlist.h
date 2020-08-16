#pragma once

struct DoublyLinkedListNode {
  int data;
  DoublyLinkedListNode* next;
  DoublyLinkedListNode* prev;
  DoublyLinkedListNode(int data) : data(data) {}
  ~DoublyLinkedListNode() {
    delete next;
  }
};

// LinkedList uses DoublyLinkedListNode underneath the hood
// It simply doesn't use this->prev
struct LinkedList {
  DoublyLinkedListNode* head;
};

struct DoublyLinkedList {
  DoublyLinkedListNode* head;
};
