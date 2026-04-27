#pragma once
#include "Array.h"

template <typename T> int partition(Array<T> &arr, int low, int high) {
  T pivot = arr[high];
  int i = low - 1;

  for (int j = low; j < high; j++) {
    if (arr[j] < pivot) {
      i++;
      T temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
    }
  }

  T temp = arr[i + 1];
  arr[i + 1] = arr[high];
  arr[high] = temp;

  return i + 1;
}

template <typename T> void quickSortHelper(Array<T> &arr, int low, int high) {
  if (low < high) {
    int pi = partition(arr, low, high);
    quickSortHelper(arr, low, pi - 1);
    quickSortHelper(arr, pi + 1, high);
  }
}

template <typename T> void quickSort(Array<T> &arr) {
  if (arr.get_size() > 0) {
    quickSortHelper(arr, 0, arr.get_size() - 1);
  }
}