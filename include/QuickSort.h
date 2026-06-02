#pragma once
#include "Array.h"
#include "List1.h"
#include "List2.h"
#include "Parameters.h"
#include <random>

// ===== ARRAY VERSION =====

template <typename T>
int partitionArr(Array<T> &arr, int low, int high, Parameters::Pivots pivot) {
  int pivotIdx;
  switch (pivot) {
  case Parameters::Pivots::left:
    pivotIdx = low;
    break;
  case Parameters::Pivots::middle:
    pivotIdx = low + (high - low) / 2;
    break;
  case Parameters::Pivots::random: {
    static std::mt19937 rng(std::random_device{}());
    pivotIdx = low + rng() % (high - low + 1);
    break;
  }
  case Parameters::Pivots::right:
  default:
    pivotIdx = high;
    break;
  }
  T temp = arr[pivotIdx];
  arr[pivotIdx] = arr[high];
  arr[high] = temp;

  T piv = arr[high];
  int i = low - 1;
  for (int j = low; j < high; j++) {
    if (arr[j] < piv) {
      i++;
      T tmp = arr[i];
      arr[i] = arr[j];
      arr[j] = tmp;
    }
  }
  temp = arr[i + 1];
  arr[i + 1] = arr[high];
  arr[high] = temp;
  return i + 1;
}

template <typename T>
void quickSortHelperArr(Array<T> &arr, int low, int high,
                        Parameters::Pivots pivot) {
  if (low < high) {
    int pi = partitionArr(arr, low, high, pivot);
    quickSortHelperArr(arr, low, pi - 1, pivot);
    quickSortHelperArr(arr, pi + 1, high, pivot);
  }
}

template <typename T>
void quickSortArr(Array<T> &arr, Parameters::Pivots pivot) {
  if (arr.get_size() > 0)
    quickSortHelperArr(arr, 0, arr.get_size() - 1, pivot);
}

// ===== LIST1 VERSION =====

template <typename T>
Node<T> *partitionList1Nodes(Node<T> *low, Node<T> *high, Node<T> *&newPivot) {
  T pivot = high->data;
  Node<T> *i = low;
  for (Node<T> *j = low; j != high; j = j->next) {
    if (j->data < pivot) {
      T temp = i->data;
      i->data = j->data;
      j->data = temp;
      i = i->next;
    }
  }
  T temp = i->data;
  i->data = high->data;
  high->data = temp;
  newPivot = i;
  return i;
}

template <typename T> void quickSortHelperList1(Node<T> *low, Node<T> *high) {
  if (low == nullptr || high == nullptr || low == high)
    return;
  Node<T> *pi;
  partitionList1Nodes(low, high, pi);
  if (pi != low) {
    Node<T> *beforePi = low;
    while (beforePi->next != pi)
      beforePi = beforePi->next;
    quickSortHelperList1(low, beforePi);
  }
  if (pi != high) {
    quickSortHelperList1(pi->next, high);
  }
}

template <typename T> void quickSortList1(List1<T> &list) {
  if (list.get_size() <= 1)
    return;
  Node<T> *head = list.get_head();
  Node<T> *tail = head;
  while (tail->next != nullptr)
    tail = tail->next;
  quickSortHelperList1(head, tail);
}

// ===== LIST2 VERSION =====

template <typename T> void quickSortHelperList2(Node2<T> *low, Node2<T> *high) {
  if (low == nullptr || high == nullptr || low == high)
    return;
  T pivot = high->data;
  Node2<T> *i = low;
  for (Node2<T> *j = low; j != high; j = j->next) {
    if (j->data < pivot) {
      T temp = i->data;
      i->data = j->data;
      j->data = temp;
      i = i->next;
    }
  }
  T temp = i->data;
  i->data = high->data;
  high->data = temp;
  Node2<T> *pi = i;
  if (pi != low) {
    quickSortHelperList2(low, pi->prev);
  }
  if (pi != high) {
    quickSortHelperList2(pi->next, high);
  }
}

template <typename T> void quickSortList2(List2<T> &list) {
  if (list.get_size() <= 1)
    return;
  quickSortHelperList2(list.get_head()->next, list.get_tail()->prev);
}