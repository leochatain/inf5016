#include "cuckoo_set.h"

#include <iostream>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  int steps;

  // n is the number of elements.
  // m is the number of queries.

  CuckooSet set(n);

  for (int i = 0; i < n; i++) {
    ll tmp;
    cin >> tmp;

    set.put(tmp, steps);
  }

  for (int i = 0; i < m; i++) {
    ll tmp;
    cin >> tmp;

    string c = set.contains(tmp, steps) ? "1" : "0";
    cout << c << endl;
  }
}
