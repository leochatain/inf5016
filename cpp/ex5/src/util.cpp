#include "util.h"

#include <cassert>

using namespace std;

int next_prime(const int num) {
  // Following Bertrands postulate, there's always a prime p such that:
  // n < p < 2*n - 2 (http://en.wikipedia.org/wiki/Bertrand's_postulate)
  const int upper = min(LARGEST_PRIME, 2 *num - 2);
  for (int i = num; i < 2 * num - 2; i++) {
    if (is_probable_prime(i)) {
      return i;
    }
  }

  // Should never really get here.
  assert(false);
}

bool is_probable_prime(const int num, const int iter) {
}

int mod(const int a, const int b) {
  return (a % b + b) % b;
}
