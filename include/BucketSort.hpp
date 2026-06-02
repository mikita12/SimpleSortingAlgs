#pragma once
#include "Array.h"
#include "List1.h"
#include "List2.h"
#include <algorithm>

// ===== ARRAY =====
template <typename T> void bucketSortArr(Array<T> &arr) {
  int n = arr.get_size();
  if (n <= 1)
    return;
  T minVal = arr[0], maxVal = arr[0];
  for (int i = 1; i < n; i++) {
    if (arr[i] < minVal)
      minVal = arr[i];
    if (arr[i] > maxVal)
      maxVal = arr[i];
  }
  if (minVal == maxVal)
    return;

  int bucketCount = n;
  Array<T> **buckets = new Array<T> *[bucketCount];
  for (int i = 0; i < bucketCount; i++)
    buckets[i] = new Array<T>(0);

  for (int i = 0; i < n; i++) {
    int idx = (int)((double)(arr[i] - minVal) / (double)(maxVal - minVal + 1) *
                    bucketCount);
    if (idx >= bucketCount)
      idx = bucketCount - 1;
    buckets[idx]->push_back(arr[i]);
  }

  int pos = 0;
  for (int i = 0; i < bucketCount; i++) {
    std::sort(buckets[i]->get_data(),
              buckets[i]->get_data() + buckets[i]->get_size());
    for (int j = 0; j < buckets[i]->get_size(); j++)
      arr[pos++] = (*buckets[i])[j];
    delete buckets[i];
  }
  delete[] buckets;
}

// ===== LIST1 =====
template <typename T> void bucketSortList1(List1<T> &list) {
  int n = list.get_size();
  if (n <= 1)
    return;
  T minVal = list.get_head()->data, maxVal = list.get_head()->data;
  Node<T> *curr = list.get_head()->next;
  while (curr != nullptr) {
    if (curr->data < minVal)
      minVal = curr->data;
    if (curr->data > maxVal)
      maxVal = curr->data;
    curr = curr->next;
  }
  if (minVal == maxVal)
    return;

  int bucketCount = n;
  Array<T> **buckets = new Array<T> *[bucketCount];
  for (int i = 0; i < bucketCount; i++)
    buckets[i] = new Array<T>(0);

  curr = list.get_head();
  while (curr != nullptr) {
    int idx = (int)((double)(curr->data - minVal) /
                    (double)(maxVal - minVal + 1) * bucketCount);
    if (idx >= bucketCount)
      idx = bucketCount - 1;
    buckets[idx]->push_back(curr->data);
    curr = curr->next;
  }

  Node<T> *node = list.get_head();
  for (int i = 0; i < bucketCount; i++) {
    std::sort(buckets[i]->get_data(),
              buckets[i]->get_data() + buckets[i]->get_size());
    for (int j = 0; j < buckets[i]->get_size(); j++) {
      node->data = (*buckets[i])[j];
      node = node->next;
    }
    delete buckets[i];
  }
  delete[] buckets;
}

// ===== LIST2 =====
template <typename T> void bucketSortList2(List2<T> &list) {
  int n = list.get_size();
  if (n <= 1)
    return;
  T minVal = list.get_head()->next->data, maxVal = list.get_head()->next->data;
  Node2<T> *curr = list.get_head()->next->next;
  while (curr != list.get_tail()) {
    if (curr->data < minVal)
      minVal = curr->data;
    if (curr->data > maxVal)
      maxVal = curr->data;
    curr = curr->next;
  }
  if (minVal == maxVal)
    return;

  int bucketCount = n;
  Array<T> **buckets = new Array<T> *[bucketCount];
  for (int i = 0; i < bucketCount; i++)
    buckets[i] = new Array<T>(0);

  curr = list.get_head()->next;
  while (curr != list.get_tail()) {
    int idx = (int)((double)(curr->data - minVal) /
                    (double)(maxVal - minVal + 1) * bucketCount);
    if (idx >= bucketCount)
      idx = bucketCount - 1;
    buckets[idx]->push_back(curr->data);
    curr = curr->next;
  }

  Node2<T> *node = list.get_head()->next;
  for (int i = 0; i < bucketCount; i++) {
    std::sort(buckets[i]->get_data(),
              buckets[i]->get_data() + buckets[i]->get_size());
    for (int j = 0; j < buckets[i]->get_size(); j++) {
      node->data = (*buckets[i])[j];
      node = node->next;
    }
    delete buckets[i];
  }
  delete[] buckets;
}