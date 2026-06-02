#pragma once
#include "Parameters.h"
#include <chrono>
#include <ctime>
#include <fstream>
#include <string>

namespace CSVWriter {

inline std::string algorithmName(Parameters::Algorithms algo) {
  switch (algo) {
  case Parameters::Algorithms::quick:
    return "quick";
  case Parameters::Algorithms::bucket:
    return "bucket";
  case Parameters::Algorithms::insertion:
    return "insertion";
  default:
    return "unknown";
  }
}

inline std::string structureName(Parameters::Structures structure) {
  switch (structure) {
  case Parameters::Structures::array:
    return "array";
  case Parameters::Structures::singleList:
    return "singleList";
  case Parameters::Structures::doubleList:
    return "doubleList";
  default:
    return "unknown";
  }
}

inline std::string dataTypeName(Parameters::DataTypes dataType) {
  switch (dataType) {
  case Parameters::DataTypes::typeInt:
    return "int";
  case Parameters::DataTypes::typeFloat:
    return "float";
  case Parameters::DataTypes::tyleUnsignedInt:
    return "unsigned int";
  case Parameters::DataTypes::typeChar:
    return "char";
  default:
    return "unknown";
  }
}

inline std::string distributionName(Parameters::Distribution dist) {
  switch (dist) {
  case Parameters::Distribution::random:
    return "random";
  case Parameters::Distribution::ascending:
    return "ascending";
  case Parameters::Distribution::descending:
    return "descending";
  case Parameters::Distribution::ascending50Per:
    return "ascending50";
  default:
    return "unknown";
  }
}

inline std::string timestamp() {
  auto now = std::chrono::system_clock::now();
  std::time_t t = std::chrono::system_clock::to_time_t(now);
  char buf[20];
  std::strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", std::localtime(&t));
  return std::string(buf);
}

inline void writeHeader(const std::string &path) {
  std::ofstream file(path);
  file << "timestamp,algorithm,structure,dataType,distribution,size,iterations,"
          "min_us,max_us,avg_us\n";
}

inline void writeRow(const std::string &path, Parameters::Algorithms algo,
                     Parameters::Structures structure,
                     Parameters::DataTypes dataType,
                     Parameters::Distribution dist, int size, int iterations,
                     long long minTime, long long maxTime, long long avgTime) {
  std::ofstream file(path, std::ios::app);
  file << timestamp() << "," << algorithmName(algo) << ","
       << structureName(structure) << "," << dataTypeName(dataType) << ","
       << distributionName(dist) << "," << size << "," << iterations << ","
       << minTime << "," << maxTime << "," << avgTime << "\n";
}

}