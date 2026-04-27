#include <stdlib.h>

#pragma once

template <typename T>

struct Node {
  T data;
  Node<T> *next;
  Node<T> *prev;
};

template <typename T> class List2 {
private:
  Node<T> *head;
  Node<T> *tail;

public:
  List2() {
    head = nullptr;
    tail = nullptr;
  }

  void init() {
    head = (Node<T> *)malloc(sizeof(Node<T>));

    tail = (Node<T> *)malloc(sizeof(Node<T>));

    head->next = tail;

    tail->prev = head;

    head->prev = nullptr;

    tail->next = nullptr;

    head->data = NULL;

    tail->data = NULL;
  }

  void push_back(const T &value) {

    if (head == nullptr && tail == nullptr) {
      init();
      Node<T> *node = (Node<T> *)malloc(sizeof(Node<T>));
      tail->prev = node;
      head->next = node;
      node->data = value;
      node->prev = head;
      node->next = tail;
      return;
    }

    Node<T> *node = (Node<T> *)malloc(sizeof(Node<T>));
    node->data = value;

    Node<T> *cp = tail->prev;

    node->prev = cp;
    node->next = tail;

    cp->next = node;
    tail->prev = node;
  }
};
