#pragma once
#include "Array.h"
#include "List1.h"
#include "List2.h"

// ===== ARRAY =====
template <typename T> void insertionSortArr(Array<T> &arr) {
  int n = arr.get_size();
  for (int i = 1; i < n; i++) {
    T key = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = key;
  }
}

// ===== LIST1 =====
template <typename T> void insertionSortList1(List1<T> &list) {
  if (list.get_size() <= 1)
    return;
  Node<T> *sorted = nullptr;
  Node<T> *curr = list.get_head();
  while (curr != nullptr) {
    Node<T> *next = curr->next;
    if (sorted == nullptr || sorted->data >= curr->data) {
      curr->next = sorted;
      sorted = curr;
    } else {
      Node<T> *tmp = sorted;
      while (tmp->next != nullptr && tmp->next->data < curr->data)
        tmp = tmp->next;
      curr->next = tmp->next;
      tmp->next = curr;
    }
    curr = next;
  }
  list.set_head(sorted);
}

// ===== LIST2 =====
template <typename T> void insertionSortList2(List2<T> &list) {
  if (list.get_size() <= 1)
    return;
  Node2<T> *curr = list.get_head()->next->next;
  while (curr != list.get_tail()) {
    T key = curr->data;
    Node2<T> *prev = curr->prev;
    while (prev != list.get_head() && prev->data > key) {
      prev->next->data = prev->data;
      prev = prev->prev;
    }
    prev->next->data = key;
    curr = curr->next;
  }
}