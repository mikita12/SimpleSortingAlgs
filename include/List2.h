#include <stdlib.h>

#pragma once

template <typename T>

struct Node2 {
  T data;
  Node2<T> *next;
  Node2<T> *prev;
};

template <typename T> class List2 {
private:
  Node2<T> *head;
  Node2<T> *tail;

public:
  List2() { init(); }

  ~List2() { freeList2(); }

  void init() {
    head = (Node2<T> *)malloc(sizeof(Node2<T>));

    tail = (Node2<T> *)malloc(sizeof(Node2<T>));

    head->next = tail;

    tail->prev = head;

    head->prev = nullptr;

    tail->next = nullptr;

    head->data = T();

    tail->data = T();
  }

  void push_back(const T &value) {

    Node2<T> *node = (Node2<T> *)malloc(sizeof(Node2<T>));
    node->data = value;

    Node2<T> *cp = tail->prev;

    node->prev = cp;
    node->next = tail;

    cp->next = node;
    tail->prev = node;
  }

  void push_front(const T &value) {

    Node2<T> *node = (Node2<T> *)malloc(sizeof(Node2<T>));
    node->data = value;

    Node2<T> *cp = head->next;

    node->next = cp;
    node->prev = head;

    cp->prev = node;
    head->next = node;
  }

  T get_last() {

    if (tail->prev == head) {
      return NULL;
    }

    return tail->prev->data;
  }

  T get_front() {

    if (tail->prev == head) {
      return NULL;
    }

    return head->next->data;
  }

  void freeList2() {
    Node2<T> *cp = head->next;

    while (cp != tail) {
      Node2<T> *next = cp->next;
      free(cp);
      cp = next;
    }
  }

  Node2<T> *get_head() { return head; }
  Node2<T> *get_tail() { return tail; }

  int get_size() const {
    int count = 0;
    Node2<T> *cp = head->next;
    while (cp != tail) {
      count++;
      cp = cp->next;
    }
    return count;
  }

  void set_head_tail(Node2<T> *newHead, Node2<T> *newTail) { // do qs
    head = newHead;
    tail = newTail;
  }
};
