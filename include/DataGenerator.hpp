#pragma once
#include <algorithm>
#include <random>

#include "Array.h"
#include "Parameters.h"

namespace DataGenerator {

template <typename T> T randomValue() {
  static std::mt19937 rng(std::random_device{}());
  if constexpr (std::is_integral_v<T>) {
    std::uniform_int_distribution<long long> dist(0, 10000);
    return static_cast<T>(dist(rng));
  } else if constexpr (std::is_floating_point_v<T>) {
    std::uniform_real_distribution<double> dist(0.0, 10000.0);
    return static_cast<T>(dist(rng));
  }
  return T{};
}

template <typename T>
Array<T> generate(int size, Parameters::Distribution dist) {
  Array<T> data(size);

  for (int i = 0; i < size; i++)
    data.push_back(randomValue<T>());

  switch (dist) {
  case Parameters::Distribution::ascending:
    std::sort(data.get_data(), data.get_data() + size);
    break;
  case Parameters::Distribution::descending:
    std::sort(data.get_data(), data.get_data() + size, std::greater<T>());
    break;
  case Parameters::Distribution::ascending50Per: {
    std::sort(data.get_data(), data.get_data() + size);
    static std::mt19937 rng(std::random_device{}());
    std::shuffle(data.get_data() + size / 2, data.get_data() + size, rng);
    break;
  }
  case Parameters::Distribution::random:
  default:
    break;
  }

  return data;
}
} // namespace DataGenerator
