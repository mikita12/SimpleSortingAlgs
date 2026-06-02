#include "BucketSort.hpp"
#include "CsvWriter.hpp"
#include "DataGenerator.hpp"
#include "FileManager.hpp"
#include "InsertionSort.hpp"
#include "Parameters.h"
#include "QuickSort.h"
#include "Validator.hpp"
#include "structConv.hpp"
#include <chrono>
#include <climits>
#include <iostream>

template <typename T>
long long sortDispatch(Array<T> &data, Parameters::Algorithms algo,
                       Parameters::Structures structure,
                       Parameters::Pivots pivot) {
  long long elapsed = 0;

  switch (structure) {
  case Parameters::Structures::array: {
    auto start = std::chrono::high_resolution_clock::now();
    switch (algo) {
    case Parameters::Algorithms::quick:
      quickSortArr(data, pivot);
      break;
    case Parameters::Algorithms::bucket:
      bucketSortArr(data);
      break;
    case Parameters::Algorithms::insertion:
      insertionSortArr(data);
      break;
    default:
      break;
    }
    auto end = std::chrono::high_resolution_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start)
                  .count();
    break;
  }
  case Parameters::Structures::singleList: {
    List1<T> list = arrayToList1(data);
    auto start = std::chrono::high_resolution_clock::now();
    switch (algo) {
    case Parameters::Algorithms::quick:
      quickSortList1(list);
      break;
    case Parameters::Algorithms::bucket:
      bucketSortList1(list);
      break;
    case Parameters::Algorithms::insertion:
      insertionSortList1(list);
      break;
    default:
      break;
    }
    auto end = std::chrono::high_resolution_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start)
                  .count();
    list1ToArray(list, data);
    break;
  }
  case Parameters::Structures::doubleList: {
    List2<T> list = arrayToList2(data);
    auto start = std::chrono::high_resolution_clock::now();
    switch (algo) {
    case Parameters::Algorithms::quick:
      quickSortList2(list);
      break;
    case Parameters::Algorithms::bucket:
      bucketSortList2(list);
      break;
    case Parameters::Algorithms::insertion:
      insertionSortList2(list);
      break;
    default:
      break;
    }
    auto end = std::chrono::high_resolution_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start)
                  .count();
    list2ToArray(list, data);
    break;
  }
  default:
    break;
  }

  return elapsed;
}

template <typename T>
void run(Parameters::Algorithms algo, Parameters::Structures structure,
         Parameters::Distribution dist, Parameters::Pivots pivot, int size,
         int iters) {
  switch (Parameters::runMode) {
  case Parameters::RunModes::singleFile: {
    Array<T> data = FileManager::read<T>(Parameters::inputFile);
    sortDispatch(data, algo, structure, pivot);
    std::cout << (isSorted(data) ? "OK" : "BLAD SORTOWANIA") << "\n";
    if (!Parameters::outputFile.empty())
      FileManager::write<T>(Parameters::outputFile, data);
    break;
  }
  case Parameters::RunModes::benchmark: {
    long long totalTime = 0;
    long long minTime = LLONG_MAX;
    long long maxTime = 0;

    for (int i = 0; i < iters; i++) {
      Array<T> data = DataGenerator::generate<T>(size, dist);
      long long elapsed = sortDispatch(data, algo, structure, pivot);
      totalTime += elapsed;
      if (elapsed < minTime)
        minTime = elapsed;
      if (elapsed > maxTime)
        maxTime = elapsed;
    }

    long long avgTime = totalTime / iters;
    CSVWriter::writeRow(Parameters::resultsFile, algo, structure,
                        Parameters::dataType, dist, size, iters, minTime,
                        maxTime, avgTime);
    break;
  }
  case Parameters::RunModes::help: {
    Parameters::help();
    break;
  }
  default:
    break;
  }
}

int main(int argc, char **argv) {
  if (Parameters::readParameters(argc - 1, argv + 1) != 0) {
    Parameters::help();
    return 0;
  }
  Parameters::printParameters();

  auto algo = Parameters::algorithm;
  auto structure = Parameters::structure;
  auto dist = Parameters::distribution;
  auto pivot = Parameters::pivot;
  int size = Parameters::structureSize;
  int iters = Parameters::iterations;

  switch (Parameters::dataType) {
  case Parameters::DataTypes::typeInt:
    run<int>(algo, structure, dist, pivot, size, iters);
    break;
  case Parameters::DataTypes::typeFloat:
    run<float>(algo, structure, dist, pivot, size, iters);
    break;
  case Parameters::DataTypes::tyleUnsignedInt:
    run<unsigned int>(algo, structure, dist, pivot, size, iters);
    break;
  case Parameters::DataTypes::typeChar:
    run<char>(algo, structure, dist, pivot, size, iters);
    break;
  default:
    std::cout << "Nieobsługiwany typ danych\n";
    break;
  }

  return 0;
}