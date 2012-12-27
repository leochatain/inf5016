#include "util.h"

#include <cassert>
#include <ctime>

using namespace std;

ll next_prime(const ll num) {
  return LARGEST_PRIME;
  assert(false); //TODO(chatain): finish this.

  // Following Bertrands postulate, there's always a prime p such that:
  // n < p < 2*n - 2 (http://en.wikipedia.org/wiki/Bertrand's_postulate)
  const ll upper = min(LARGEST_PRIME, 2 *num - 2);
  for (ll i = num; i < 2 * num - 2; i++) {
    if (is_probable_prime(i)) {
      return i;
    }
  }

  // Should never really get here.
  assert(false);
}

bool is_probable_prime(const ll p, const int iter) {
  assert(false); // TODO(chatain): finish this
}

ll mod(const ll a, const ll b) {
  return (a % b + b) % b;
}
