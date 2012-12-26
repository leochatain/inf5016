#ifndef __UTIL_H
#define __UTIL_H

#include <algorithm>

typedef long long ll;

// Returns the smaller prime larger than "num".
ll next_prime(const ll num);

// Uses Rabin-Karp method to determine whether the number is a prime,
// with probability 1/4 ^k.
bool is_probable_prime(const ll num, const ll iter = 50);

// C++ mod is broken. -1 % 8 should be 7, not -1. This method fixes it.
ll mod(const ll a, const ll b);

const ll LARGEST_PRIME = 1 << 31 - 1;

#endif
