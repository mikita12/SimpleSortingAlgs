#pragma once
#include "Array.h"
#include <fstream>
#include <string>

namespace FileManager {

template <typename T> Array<T> read(const std::string &path) {
  std::ifstream file(path);
  int n;
  file >> n;
  Array<T> data(n);
  for (int i = 0; i < n; i++) {
    T val;
    file >> val;
    data.push_back(val);
  }
  return data;
}

template <typename T> void write(const std::string &path, Array<T> &data) {
  std::ofstream file(path);
  int n = data.get_size();
  file << n << "\n";
  for (int i = 0; i < n; i++)
    file << data[i] << "\n";
}

} // namespace FileManager