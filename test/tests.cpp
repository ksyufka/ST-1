// Copyright 2025 UNN-CS

#include <gtest/gtest.h>
#include <cstdint>
#include "alg.h"


TEST(st1, checkPrime_zero_false) {
  EXPECT_FALSE(checkPrime(0));
}

TEST(st1, checkPrime_one_false) {
  EXPECT_FALSE(checkPrime(1));
}

TEST(st1, checkPrime_two_true) {
  EXPECT_TRUE(checkPrime(2));
}

TEST(st1, checkPrime_prime_true) {
  EXPECT_TRUE(checkPrime(17));
}

TEST(st1, checkPrime_composite_false) {
  EXPECT_FALSE(checkPrime(49));
}

TEST(st1, nPrime_first_is_2) {
  EXPECT_EQ(2u, nPrime(1));
}

TEST(st1, nPrime_fifth_is_11) {
  EXPECT_EQ(11u, nPrime(5));
}

TEST(st1, nPrime_zero_is_0) {
  EXPECT_EQ(0u, nPrime(0));
}

TEST(st1, nextPrime_after_0_is_2) {
  EXPECT_EQ(2u, nextPrime(0));
}

TEST(st1, nextPrime_after_prime) {
  EXPECT_EQ(13u, nextPrime(11));
}

TEST(st1, nextPrime_after_even) {
  EXPECT_EQ(5u, nextPrime(4));
}

TEST(st1, sumPrime_small_bound_0) {
  EXPECT_EQ(0u, sumPrime(0));
}

TEST(st1, sumPrime_small_bound_2) {
  EXPECT_EQ(0u, sumPrime(2));
}

TEST(st1, sumPrime_10) {
  uint64_t res = sumPrime(10);
  uint64_t expected = 17;
  EXPECT_EQ(expected, res);
}

TEST(st1, sumPrime_2000000) {
  uint64_t res = sumPrime(2000000);
  uint64_t expected = 142913828922;
  EXPECT_EQ(expected, res);
}
