#pragma once
#include "Array.h"

template <typename T> bool isSorted(Array<T> &arr) {
  for (int i = 0; i < arr.get_size() - 1; i++) {
    if (arr[i] > arr[i + 1])
      return false;
  }
  return true;
}