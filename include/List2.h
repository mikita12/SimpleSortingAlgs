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
  List2() { init(); }

  ~List2() { freeList2(); }

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

    Node<T> *node = (Node<T> *)malloc(sizeof(Node<T>));
    node->data = value;

    Node<T> *cp = tail->prev;

    node->prev = cp;
    node->next = tail;

    cp->next = node;
    tail->prev = node;
  }

  void push_front(const T &value) {

    Node<T> *node = (Node<T> *)malloc(sizeof(Node<T>));
    node->data = value;

    Node<T> *cp = head->next;

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
    Node<T> *cp = head->next;

    while (cp != tail) {
      Node<T> *next = cp->next;
      free(cp);
      cp = next;
    }
  }

  Node<T> *get_head() { return head; }
  Node<T> *get_tail() { return tail; }

  int get_size() const {
    int count = 0;
    Node<T> *cp = head->next;
    while (cp != tail) {
      count++;
      cp = cp->next;
    }
    return count;
  }

  void set_head_tail(Node<T> *newHead, Node<T> *newTail) {//do qs
    head = newHead;
    tail = newTail;
  }
};
