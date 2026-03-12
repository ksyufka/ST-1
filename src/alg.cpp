// Copyright 2025 UNN-CS
#include <cstdint>
#include <limits>
#include <vector>
#include "alg.h"

bool checkPrime(uint64_t value) {
  if (value < 2) {
    return false;
  }
  if (value == 2) {
    return true;
  }
  if (value % 2 == 0) {
    return false;
  }

  for (uint64_t divisor = 3; divisor <= value / divisor; divisor += 2) {
    if (value % divisor == 0) {
      return false;
    }
  }
  return true;
}

uint64_t nPrime(uint64_t n) {
  if (n == 0) {
    return 0;
  }

  uint64_t count = 0;
  uint64_t candidate = 1;
  while (count < n) {
    ++candidate;
    if (checkPrime(candidate)) {
      ++count;
    }
  }
  return candidate;
}

uint64_t nextPrime(uint64_t value) {
  if (value < 2) {
    return 2;
  }
  if (value == std::numeric_limits<uint64_t>::max()) {
    return 0;
  }

  uint64_t candidate = value + 1;
  if (candidate > 2 && candidate % 2 == 0) {
    ++candidate;
  }

  while (candidate != 0 && !checkPrime(candidate)) {
    candidate += (candidate == 2 ? 1 : 2);
  }
  return candidate;
}

uint64_t sumPrime(uint64_t hbound) {
  if (hbound < 2) {
    return 0;
  }
  if (hbound > std::numeric_limits<size_t>::max()) {
    return 0;
  }

  const size_t limit = static_cast<size_t>(hbound);
  std::vector<bool> prime(limit, true);
  prime[0] = false;
  prime[1] = false;

  for (size_t i = 2; i <= (limit - 1) / i; ++i) {
    if (prime[i]) {
      for (size_t multiple = i * i; multiple < limit; multiple += i) {
        prime[multiple] = false;
      }
    }
  }

  uint64_t sum = 0;
  for (size_t i = 2; i < limit; ++i) {
    if (prime[i]) {
      sum += static_cast<uint64_t>(i);
    }
  }
  return sum;
}
