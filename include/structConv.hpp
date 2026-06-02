#pragma once
#include "Array.h"
#include "List1.h"
#include "List2.h"

template <typename T> List1<T> arrayToList1(Array<T> &data) {
  List1<T> list;
  for (int i = 0; i < data.get_size(); i++)
    list.push_back(data[i]);
  return list;
}

template <typename T> void list1ToArray(List1<T> &list, Array<T> &data) {
  Node<T> *curr = list.get_head(); // bez sentinela, od razu dane
  for (int i = 0; i < data.get_size(); i++) {
    data[i] = curr->data;
    curr = curr->next;
  }
}

template <typename T> List2<T> arrayToList2(Array<T> &data) {
  List2<T> list;
  for (int i = 0; i < data.get_size(); i++)
    list.push_back(data[i]);
  return list;
}

template <typename T> void list2ToArray(List2<T> &list, Array<T> &data) {
  Node2<T> *curr = list.get_head()->next; // pomiń sentinel head
  for (int i = 0; i < data.get_size(); i++) {
    data[i] = curr->data;
    curr = curr->next;
  }
}