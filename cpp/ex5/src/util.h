#ifndef __UTIL_H
#define __UTIL_H

#include <algorithm>

// Returns the smaller prime larger than "num".
int next_prime(const int num);

// Uses Rabin-Karp method to determine whether the number is a prime,
// with probability XX
bool is_probable_prime(const int num, const int iter = 50);

// C++ mod is broken. -1 % 8 should be 7, not -1. This method fixes it.
int mod(const int a, const int b);

const int LARGEST_PRIME = 1 << 31 - 1;

#endif
