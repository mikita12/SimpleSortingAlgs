#include "Array.h"
#include <fstream>
#include <string>

#pragma once

class CSVWriter {
private:
  std::string filename;

public:
  CSVWriter(const std::string &file) { filename = file; }

  void writeHeader(const std::string &header) {
    std::ofstream out(filename);
    out << header << "\n";
    out.close();
  }

  void appendResult(const std::string &data) {
    std::ofstream out(filename, std::ios::app); // append
    out << data << "\n";
    out.close();
  }
  template <typename T> 
  void appendSorted(Array<T> arr) {
    std::ofstream out(filename, std::ios::app);

    for (int i = 0; i < arr.get_size(); i++) {
      out << arr[i];
      if (i < arr.get_size() - 1) {
        out << ";";
      }
    }
    out << "\n";

    out.close();
  }
};