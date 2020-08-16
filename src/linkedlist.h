#pragma once

struct SinglyLinkedListNode {
  int data;
  SinglyLinkedListNode* next;
  SinglyLinkedListNode(int data) : data(data) {}
  ~SinglyLinkedListNode() {
    delete next;
  }
};

struct DoublyLinkedListNode {
  int data;
  DoublyLinkedListNode* next;
  DoublyLinkedListNode* prev;
  DoublyLinkedListNode(int data) : data(data) {}
  ~DoublyLinkedListNode() {
    delete next;
  }
};

// TODO REPL
// TODO SHOW
// TODO LIST
struct LinkedList {
  SinglyLinkedListNode* head;
  LinkedList() {}
  LinkedList(int data) : head(new SinglyLinkedListNode(data)) {}
  ~LinkedList() {
    delete this->head;
  }
  void insert(int);
private:
  SinglyLinkedListNode* insert(SinglyLinkedListNode*, int);
};

struct DoublyLinkedList {
  DoublyLinkedListNode* head;
};
