#include <iostream>
#include <stdlib.h>

#pragma once

template <typename T>

struct Node {
  T data;
  Node<T> *next;
};

template <typename T> class List1 {
private:
  Node<T> *head;

public:
  List1() { head = nullptr; }

  void push_back(const T &value) {
    if (head == nullptr) {
      Node<T> *node = (Node<T> *)malloc(sizeof(Node<T>));
      node->data = value;
      node->next = nullptr;
      head = node;

      return;
    }

    Node<T> *previous = lastList1();
    Node<T> *node = (Node<T> *)malloc(sizeof(Node<T>));

    previous->next = node;
    node->data = value;
    node->next = nullptr;
  }

  Node<T> *lastList1() {

    if (head == nullptr) { //
      std::cout << "nuh uh\n";
      return nullptr;
    }

    Node<T> *cp = head;
    while (cp->next != nullptr) {
      cp = cp->next;
    }
    return cp;
  }

  void freeList1() {

    Node<T> *cp = head;

    while (cp != nullptr) {
      Node<T> *next = cp->next;
      free(cp);
      cp = next;
    }
    head = nullptr;
  }

  void push_front(const T &value) {
    Node<T> *front = (Node<T> *)malloc(sizeof(Node<T>));
    front->data = value;
    front->next = head;
    head = front;
  }

  Node<T> *get_head() { return head; }
};
