#include "linked_set.h"

#include <iostream>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  // n is the number of elements.
  // m is the number of queries.

  LinkedSet set(n);

  for (int i = 0; i < n; i++) {
    ll tmp;
    cin >> tmp;

    int steps;
    set.put(tmp, steps);
  }

  for (int i = 0; i < m; i++) {
    ll tmp;
    cin >> tmp;

    int steps;
    string c = set.contains(tmp, steps) ? "1" : "0";
    cout << c << endl;
  }
}
