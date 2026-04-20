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

  void push_back(){
    if(head == nullptr){
        Node<T> *node = (Node<T> *)malloc(sizeof(Node<T>));
    }
  }
};
