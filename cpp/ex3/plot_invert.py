#!/usr/bin/python

import pickle
from math import log
import matplotlib.pyplot as plt
import sys

if (len(sys.argv) < 2):
  print 'parameters'
  exit(1)

in_file = str(sys.argv[1])

times = pickle.load(open(in_file, 'rb'))

x_axis = list(x[0] for x in times)
vals = list(x[1] for x in times)
exp = []

for i in xrange(10, 151, 10):
  n = i**2 + 2
  m = 3 * i * (i-1)
  # (n logn + m)mlogC
  exp.append((n * log(n, 2) + m) * m)

final = []
for i in xrange(len(times)):
  final.append(vals[i]/exp[i])

print final

ax = plt.subplot(111)
ax.plot(x_axis, final)
plt.show()
